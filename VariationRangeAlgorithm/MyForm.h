#pragma once

namespace VariationRangeAlgorithm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(131, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(96, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"V=";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Location = System::Drawing::Point(13, 63);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(1359, 150);
			this->dataGridView1->TabIndex = 16;
			this->dataGridView1->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(290, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 46);
			this->button1->TabIndex = 5;
			this->button1->Text = L"solve";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1384, 537);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int V;
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			V = Int32::Parse(textBox1->Text);
		}
		catch (...) {
			dataGridView1->Visible = false;
		}
		generateTabel();
	}

	private: System::Void generateTabel() {
		int gd = gcd(System::Math::Abs(V - 1454), 12);
		int z = (System::Math::Abs(V - 1454) / gd) % (12 / gd);
		int k = z + 9;
		int h = (V + 1345) % 13 + 8;
		int n0 = System::Math::Abs((V + 40) / 27 - 4);
		int x0 = System::Math::Abs((V + 120) / 10 - 4) + 8;
		dataGridView1->ColumnCount = k + 1;
		dataGridView1->RowCount = 2;

		dataGridView1->Rows[0]->Cells[0]->Value = "xi";
		dataGridView1->Rows[1]->Cells[0]->Value = "ni";
		dataGridView1->Visible = true;
		for (int i = 1; i <= k; i++) {
			int X = x0 + 10 * i + h;
			dataGridView1->Rows[0]->Cells[i]->Value = System::Convert::ToString(X);

			if (i % 2 == 0) {
				z = (V + 14 * i) % 15;
				if ((V + 14 * i) % 3 == 0) {
					z = ((V + 14 * i) / 3) % 5;
				}
				X = 1 + System::Math::Abs(z - 2 * i);
			}
			else {
				X = 1 + System::Math::Abs((V + 14 * i) % 13 - 3 * i);
			}
			dataGridView1->Rows[1]->Cells[i]->Value = System::Convert::ToString(X);
		}
		
	}

	private: int gcd(int a, int b) {
		while (a && b) {
			if (a > b)
				a %= b;
			else
				b %= a;
		}
		return a + b;
	}
};
}
