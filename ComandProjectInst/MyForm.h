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
	/// —водка дл¤ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		Bitmap^bmp = gcnew Bitmap(1000, 1000);
		Graphics^gp = Graphics::FromImage(bmp);
		Pen^pen = gcnew Pen(Brushes::DarkRed);
		ref class piy
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
			void a(int i, Graphics^gp, Pen^pen)
			{
				if (i > 0)
				{
					d(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2 = x2 + u, y2);
					x1 = x2;
					y1 = y2;
					a(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2, y2 = y2 + u);
					x1 = x2;
					y1 = y2;
					a(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2 = x2 - u, y2);
					x1 = x2;
					y1 = y2;
					c(i - 1, gp, pen);
				}
			}
			void b(int i, Graphics^gp, Pen^pen)
			{
				if (i > 0)
				{
					c(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2 = x2 - u, y2);
					x1 = x2;
					y1 = y2;
					b(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2, y2 = y2 - u);
					x1 = x2;
					y1 = y2;
					b(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2 = x2 + u, y2);
					x1 = x2;
					y1 = y2;
					d(i - 1, gp, pen);
				}
			}
			void c(int i, Graphics^gp, Pen^pen)
			{
				if (i > 0)
				{
					b(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2, y2 = y2 - u);
					x1 = x2;
					y1 = y2;
					c(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2 = x2 - u, y2);
					x1 = x2;
					y1 = y2;
					c(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2, y2 = y2 + u);
					x1 = x2;
					y1 = y2;
					a(i - 1, gp, pen);
				}
			}
			void d(int i, Graphics ^gp, Pen^pen)
			{
				if (i > 0)
				{
					a(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2, y2 = y2 + u);
					x1 = x2;
					y1 = y2;
					d(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2 = x2 + u, y2);
					x1 = x2;
					y1 = y2;
					d(i - 1, gp, pen);
					gp->DrawLine(pen, x1, y1, x2, y2 = y2 - u);
					x1 = x2;
					y1 = y2;
					b(i - 1, gp, pen);
				}
			}
		private:

		};
		piy^Piy = gcnew piy;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
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
		/// “ребуетс¤ переменна¤ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб¤зательный метод дл¤ поддержки конструктора - не измен¤йте
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
			this->pictureBox1->Location = System::Drawing::Point(106, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(256, 256);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(488, 256);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		//существует 4 вида позиции стандартной формы "ѕ"


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		pictureBox1->Height = MyForm::Height - 40;
		pictureBox1->Width = MyForm::Height - 40;
		pictureBox1->Top = ClientSize.Height / 2 - pictureBox1->Height / 2;
		pictureBox1->Left = ClientSize.Width / 2 - pictureBox1->Width / 2;
		Piy->x1 = 1;
		Piy->y1 = 1;
		Piy->x2 = 1;
		Piy->y2 = 1;
		Piy->u = 2;
		Piy->a(8, gp, pen);
		this->pictureBox1->Image = bmp;
	}

	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		pictureBox1->Height = MyForm::Height - 40;
		pictureBox1->Width = MyForm::Height - 40;
		pictureBox1->Top = ClientSize.Height / 2 - pictureBox1->Height / 2;
		pictureBox1->Left = ClientSize.Width / 2 - pictureBox1->Width / 2;
		Piy->shtrih = 2; //минимальна¤ длина штриха
		gp->Clear(Color::LightBlue);
		int pr = pictureBox1->Height - 2; // рабоча¤ переменна¤ хран¤ща¤ размерность
		int p = pictureBox1->Height - 2;
		while (pr > 0)
		{
			if ((pr & (pr - 1)) == 0) break;
			pr = pr - 1;
		}
		int kol_p = (log10(double(pr)) / log10(double(2)));// kol_p-пор¤док
		int k = pow(2, double(kol_p)) - 1 / pow(2, double(kol_p));//k=2^n-1/2^n минимально зан¤та¤ площадь
		Piy->x1 = 1;
		Piy->y1 = 1;
		Piy->x2 = 1;
		Piy->y2 = 1;
		Piy->u = k / ((3 + kol_p - 1) * kol_p);
		if (Piy->u <3) Piy->u = 2;
		//if ((Piy->u = ((pow(2, double(kol_p)))) / kol_p)<3) Piy->u = 3;
		//Piy->u = 2;
		Piy->a(kol_p, gp, pen);
		this->pictureBox1->Image = bmp;
	}


	};
}
