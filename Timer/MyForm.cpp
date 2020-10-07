#include "MyForm.h"
#include <Windows.h>
using namespace Timer1;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}
const int hours_in_day = 24;
const int mins_in_hour = 60;
const int secs_to_min = 60;
int i = 7200;
System::Void Timer1::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Timer1::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Timer1::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	
		i--;
		long seconds = i % secs_to_min;
		long minutes = i / secs_to_min % mins_in_hour;
		long hours = i / secs_to_min / mins_in_hour;
		label1->Text = seconds.ToString();
		label2->Text = minutes.ToString();
		label3->Text = hours.ToString();
	
	return System::Void();
}

System::Void Timer1::MyForm::проверкаОбновленийToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
