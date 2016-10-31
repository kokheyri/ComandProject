#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

int main(array<String^>^ arg){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ComandProjectInst::MyForm form;
	Application::Run(%form);
	return 0;
}