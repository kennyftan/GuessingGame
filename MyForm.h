#pragma once
#include <string>
#include <cstdlib>
#include <ctime>

namespace $safeprojectname$ {

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
			srand(time(NULL)); // initializes random number generation
			randomNumber = rand() % 10 + 1;
			number_guess = 0;
			previous_guess = 10;
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
	private: 
		int randomNumber;
		int number_guess;
		int previous_guess;
	private: System::Windows::Forms::Label^ Prompt;
	private: System::Windows::Forms::TextBox^ TextBox;
	

	private: System::Windows::Forms::Button^ PlayAgain;
	private: System::Windows::Forms::Button^ SubmitButton;
	private: System::Windows::Forms::Label^ Result;

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
			this->Prompt = (gcnew System::Windows::Forms::Label());
			this->TextBox = (gcnew System::Windows::Forms::TextBox());
			this->PlayAgain = (gcnew System::Windows::Forms::Button());
			this->SubmitButton = (gcnew System::Windows::Forms::Button());
			this->Result = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Prompt
			// 
			this->Prompt->AutoSize = true;
			this->Prompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Prompt->Location = System::Drawing::Point(63, 9);
			this->Prompt->Name = L"Prompt";
			this->Prompt->Size = System::Drawing::Size(434, 58);
			this->Prompt->TabIndex = 0;
			this->Prompt->Text = L"I have a number between 1 and 10 - \r\nCan you guess my number\?";
			this->Prompt->Click += gcnew System::EventHandler(this, &MyForm::Prompt_Click);
			// 
			// TextBox
			// 
			this->TextBox->AcceptsReturn = true;
			this->TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TextBox->Location = System::Drawing::Point(68, 137);
			this->TextBox->Name = L"TextBox";
			this->TextBox->Size = System::Drawing::Size(172, 34);
			this->TextBox->TabIndex = 1;
			// 
			// PlayAgain
			// 
			this->PlayAgain->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayAgain->Location = System::Drawing::Point(68, 254);
			this->PlayAgain->Name = L"PlayAgain";
			this->PlayAgain->Size = System::Drawing::Size(172, 39);
			this->PlayAgain->TabIndex = 2;
			this->PlayAgain->Text = L"Play Again";
			this->PlayAgain->UseVisualStyleBackColor = true;
			this->PlayAgain->Visible = false;
			this->PlayAgain->Click += gcnew System::EventHandler(this, &MyForm::PlayAgain_Click);
			// 
			// SubmitButton
			// 
			this->SubmitButton->Location = System::Drawing::Point(246, 137);
			this->SubmitButton->Name = L"SubmitButton";
			this->SubmitButton->Size = System::Drawing::Size(91, 34);
			this->SubmitButton->TabIndex = 3;
			this->SubmitButton->Text = L"Submit";
			this->SubmitButton->UseVisualStyleBackColor = true;
			this->SubmitButton->Click += gcnew System::EventHandler(this, &MyForm::SubmitButton_Click);
			// 
			// Result
			// 
			this->Result->AutoSize = true;
			this->Result->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->Result->ForeColor = System::Drawing::Color::White;
			this->Result->Location = System::Drawing::Point(187, 118);
			this->Result->Name = L"Result";
			this->Result->Size = System::Drawing::Size(53, 16);
			this->Result->TabIndex = 4;
			this->Result->Text = L"Correct!";
			this->Result->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 353);
			this->Controls->Add(this->Result);
			this->Controls->Add(this->SubmitButton);
			this->Controls->Add(this->PlayAgain);
			this->Controls->Add(this->TextBox);
			this->Controls->Add(this->Prompt);
			this->Name = L"MyForm";
			this->Text = L"Guessing Game- Kenny Tan";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Prompt_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->randomNumber = rand() % 10 + 1; // Random number generation
	}

	private: System::Void SubmitButton_Click(System::Object^ sender, System::EventArgs^ e)
	{

		if (this->TextBox->Text != "")
		{
			number_guess = Convert::ToInt16(this->TextBox->Text);
			this->Result->Visible = true;
		}
		else
		{
			this->Result->Visible = false;
		}

		int distance = abs(randomNumber - number_guess); // Calculate distance between guess and answer
		if (distance > previous_guess) // Compares distance to previous guess distance
		{
			this->Result->BackColor = System::Drawing::Color::Blue;
		}
		else if (distance <= previous_guess)
		{
			this->Result->BackColor = System::Drawing::Color::Red;
		}

		previous_guess = distance; // Sets current guess to be previous distance

		if (number_guess > randomNumber)
		{
			this->Result->Text = L"Too High";
		}
		else if (number_guess < randomNumber)
		{
			this->Result->Text = L"Too Low";
		}
		else
		{
			this->Result->Text = L"Correct!"; // Correct answer actions
			this->PlayAgain->Visible = true;
			this->TextBox->Enabled = false;
			this->PlayAgain->Text = L"Play Again";
			this->Result->BackColor = System::Drawing::Color::Green;
		}

	}

	private: System::Void PlayAgain_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->randomNumber = rand() % 10 + 1; // resets settings and generations new number
		this->TextBox->Text = L"";
		this->TextBox->Enabled = true;
		this->PlayAgain->Visible = false;
		this->Result->Visible = false;
		previous_guess = 10;
	}

};
}
