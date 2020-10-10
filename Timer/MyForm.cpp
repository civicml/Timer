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
	i = i * 2;
	return System::Void();
}

System::Void Timer1::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	i = i / 2;
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
		switch (comboBox1->SelectedIndex)
		{
			case 0:
				switch (i) 
				{
					case 60:
						MessageBox::Show("Выключение через 60 секунд!", "Закрытие", MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1, MessageBoxOptions::ServiceNotification);
					break;
					case 0:
						WinExec("shutdown -s -t 0", SW_HIDE);
					break;
				}
			break;
			case 1:
				switch (i)
				{
					case 60:
						MessageBox::Show("Перезагрузка через 60 секунд!", "Закрытие", MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button1, MessageBoxOptions::ServiceNotification);
					break;
					case 0:
						WinExec("shutdown -r -t 0", SW_HIDE);
					break;
				}
			break;
		}
		
	
	return System::Void();
}

System::Void Timer1::MyForm::проверкаОбновленийToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Timer1::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	try 
	{
		if (textBox1->Text == "") {
			textBox1->Text = "0";
		}
		if (textBox2->Text == "") {
			textBox2->Text = "0";
		}
		if (textBox3->Text == "") {
			textBox3->Text = "1";
			
		}
		i = (System::Int32::Parse(textBox1->Text) * 60 * 60) + (System::Int32::Parse(textBox2->Text) * 60) + (System::Int32::Parse(textBox3->Text));
		textBox1->Clear();
		textBox2->Clear();
		textBox3->Clear();
	}
	catch (FormatException^)
	{
		MessageBox::Show("Где-то вы ввели не цифры...", "Закрытие", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	return System::Void();
}


