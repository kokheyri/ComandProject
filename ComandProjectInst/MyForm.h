#pragma once
#include <stdlib.h>
#include <time.h>
#include <math.h>

namespace ComandProjectInst {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		int x1;
		int y1;
		int x2;
		int y2;
		int u;
		int Kol_shtrihov;
		int shtrih;
		int kol_p;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		Bitmap^bmp = gcnew Bitmap(1000, 1000);
		Graphics^gp = Graphics::FromImage(bmp);
		Pen^pen = gcnew Pen(Brushes::White);
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:


	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->pictureBox1->BackColor = System::Drawing::Color::LightBlue;
			this->pictureBox1->Location = System::Drawing::Point(177, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 400);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(754, 401);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		//существует 4 вида позиции стандартной формы "П"
		void a(int i)
		{
			if (i > 0)
			{
				d(i - 1);
				gp->DrawLine(pen, x1, y1, x2 = x2 + u, y2);
				x1 = x2;
				y1 = y2;
				a(i - 1);
				gp->DrawLine(pen, x1, y1, x2, y2 = y2 + u);
				x1 = x2;
				y1 = y2;
				a(i - 1);
				gp->DrawLine(pen, x1, y1, x2= x2 - u, y2);
				x1 = x2;
				y1 = y2;
				c(i - 1);
			}
		}
		void b(int i)
		{
			if (i > 0)
			{
				c(i - 1);
				gp->DrawLine(pen, x1, y1, x2 = x2 - u, y2);
				x1 = x2;
				y1 = y2;
				b(i - 1);
				gp->DrawLine(pen, x1, y1, x2, y2 = y2 - u);
				x1 = x2;
				y1 = y2;
				b(i - 1);
				gp->DrawLine(pen, x1, y1, x2 = x2 + u, y2);
				x1 = x2;
				y1 = y2;
				d(i - 1);
			}
		}
		void c(int i)
		{
			if (i > 0)
			{
				b(i - 1);
				gp->DrawLine(pen, x1, y1, x2, y2 = y2 - u);
				x1 = x2;
				y1 = y2;
				c(i - 1);
				gp->DrawLine(pen, x1, y1, x2 = x2 - u, y2);
				x1 = x2;
				y1 = y2;
				c(i - 1);
				gp->DrawLine(pen, x1, y1, x2, y2 = y2 + u);
				x1 = x2;
				y1 = y2;
				a(i - 1);
			}
		}
		void d(int i)
		{
			if (i > 0)
			{
				a(i - 1);
				gp->DrawLine(pen, x1, y1, x2, y2 = y2 + u);
				x1 = x2;
				y1 = y2;
				d(i - 1);
				gp->DrawLine(pen, x1, y1, x2 = x2 + u, y2);
				x1 = x2;
				y1 = y2;
				d(i - 1);
				gp->DrawLine(pen, x1, y1, x2, y2 = y2 - u);
				x1 = x2;
				y1 = y2;
				b(i - 1);
			}
		}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		pictureBox1->Height = MyForm::Height - 40;
		pictureBox1->Width = MyForm::Height - 40;
		pictureBox1->Top = ClientSize.Height / 2 - pictureBox1->Height / 2;
		pictureBox1->Left = ClientSize.Width / 2 - pictureBox1->Width / 2;
		x1 = 4;
		y1 = 4;
		x2 = 4;
		y2 = 4;
		u = 4;
		a(7);
		this->pictureBox1->Image = bmp;
	}

	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		pictureBox1->Height = MyForm::Height - 40;
		pictureBox1->Width = MyForm::Height - 40;
		pictureBox1->Top = ClientSize.Height / 2 - pictureBox1->Height / 2;
		pictureBox1->Left = ClientSize.Width / 2 - pictureBox1->Width / 2;
		shtrih = 2; //минимальная длина штриха
		gp->Clear(Color::LightBlue);
		int pr = pictureBox1->Height; // рабочая переменная хранящая размерность
		int p = pictureBox1->Height;
		while(pr > 0)
		{
			if ((pr & (pr - 1)) == 0) break;
			pr = pr - 1;
		}
		int kol_p = (log10(double(pr))/log10(double(2)))*2;//pr- количество штрихов, kol_p-порядок
		int k = rand() % kol_p;
		x1 = 4;
		y1 = 4;
		x2 = 4;
		y2 = 4;
		u =p/ pow(2,double(k));
		a(k);
		this->pictureBox1->Image = bmp;
	}
	
	
	};
}
