#pragma once
#include <vector>
#include <string>
#include <exception>
#include <msclr\marshal_cppstd.h>
#include "arithmetic_analyzer.h"
#include "methods_optimization.h"

namespace softwareGlobalOptimization {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum METHOD{ STRONGIN, PIYAVSKY, SCAN };

	arithmetic_analyzer a_analyzer;

	double f(double x) {
		a_analyzer.setVar("x", x);
		return a_analyzer.calcArithmExp();
	}

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		strongin_method* strongin;
		piyavsky_method* piyavsky;
		scan_method* scan;
		optimization_method* opt_method;

		double a, b, eps, r, m, x, y;
		int Nmax, *N;
		vector<trial>* trial_points;
		METHOD method;
		string* function;

	public:
		MainForm(void)
		{
			InitializeComponent();
			
			strongin = new strongin_method(f);
			piyavsky = new piyavsky_method(f);
			scan = new scan_method(f);

			trial_points = new vector<trial>;
			function = new string;
			N = new int;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ GroupBoxFunc;
	private: System::Windows::Forms::GroupBox^ GroupBoxMethodParam;
	private: System::Windows::Forms::Button^ ButtonStart;
	private: System::Windows::Forms::GroupBox^ GroupBoxInfo;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ Chart;
	private: System::Windows::Forms::Label^ LabelN;
	private: System::Windows::Forms::Label^ LabelValMin;
	private: System::Windows::Forms::Label^ LabelCoordMin;
	private: System::Windows::Forms::TableLayoutPanel^ TableLayoutPanelTask;
	private: System::Windows::Forms::TableLayoutPanel^ TableLayoutPanelMain;
	private: System::Windows::Forms::Label^ LabelX;
	private: System::Windows::Forms::Label^ LabelPhi;
	private: System::Windows::Forms::Label^ LabelBracket;
	private: System::Windows::Forms::Label^ LabelSemicolon;
	private: System::Windows::Forms::RadioButton^ RadioButtonScan;
	private: System::Windows::Forms::RadioButton^ RadioButtonPiyavsky;
	private: System::Windows::Forms::RadioButton^ RadioButtonStrongin;
	private: System::Windows::Forms::Label^ LabelNmax;
	private: System::Windows::Forms::Label^ LabelEps;
	private: System::Windows::Forms::Label^ LabelM;
	private: System::Windows::Forms::Label^ LabelR;
	private: System::Windows::Forms::TextBox^ TextBoxPhi;
	private: System::Windows::Forms::TextBox^ TextBoxA;
	private: System::Windows::Forms::TextBox^ TextBoxB;
	private: System::Windows::Forms::TextBox^ TextBoxN;
	private: System::Windows::Forms::TextBox^ TextBoxValMin;
	private: System::Windows::Forms::TextBox^ TextBoxCoordMin;
	private: System::Windows::Forms::TextBox^ TextBoxNmax;
	private: System::Windows::Forms::TextBox^ TextBoxEps;
	private: System::Windows::Forms::TextBox^ TextBoxM;
	private: System::Windows::Forms::TextBox^ TextBoxR;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->GroupBoxFunc = (gcnew System::Windows::Forms::GroupBox());
			this->TextBoxB = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxA = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxPhi = (gcnew System::Windows::Forms::TextBox());
			this->LabelBracket = (gcnew System::Windows::Forms::Label());
			this->LabelSemicolon = (gcnew System::Windows::Forms::Label());
			this->LabelX = (gcnew System::Windows::Forms::Label());
			this->LabelPhi = (gcnew System::Windows::Forms::Label());
			this->GroupBoxMethodParam = (gcnew System::Windows::Forms::GroupBox());
			this->TextBoxNmax = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxEps = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxM = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxR = (gcnew System::Windows::Forms::TextBox());
			this->LabelNmax = (gcnew System::Windows::Forms::Label());
			this->LabelEps = (gcnew System::Windows::Forms::Label());
			this->LabelM = (gcnew System::Windows::Forms::Label());
			this->LabelR = (gcnew System::Windows::Forms::Label());
			this->RadioButtonScan = (gcnew System::Windows::Forms::RadioButton());
			this->RadioButtonPiyavsky = (gcnew System::Windows::Forms::RadioButton());
			this->RadioButtonStrongin = (gcnew System::Windows::Forms::RadioButton());
			this->ButtonStart = (gcnew System::Windows::Forms::Button());
			this->GroupBoxInfo = (gcnew System::Windows::Forms::GroupBox());
			this->TextBoxN = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxValMin = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxCoordMin = (gcnew System::Windows::Forms::TextBox());
			this->LabelN = (gcnew System::Windows::Forms::Label());
			this->LabelValMin = (gcnew System::Windows::Forms::Label());
			this->LabelCoordMin = (gcnew System::Windows::Forms::Label());
			this->Chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->TableLayoutPanelTask = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->TableLayoutPanelMain = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->GroupBoxFunc->SuspendLayout();
			this->GroupBoxMethodParam->SuspendLayout();
			this->GroupBoxInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Chart))->BeginInit();
			this->TableLayoutPanelTask->SuspendLayout();
			this->TableLayoutPanelMain->SuspendLayout();
			this->SuspendLayout();
			// 
			// GroupBoxFunc
			// 
			this->GroupBoxFunc->AutoSize = true;
			this->GroupBoxFunc->Controls->Add(this->TextBoxB);
			this->GroupBoxFunc->Controls->Add(this->TextBoxA);
			this->GroupBoxFunc->Controls->Add(this->TextBoxPhi);
			this->GroupBoxFunc->Controls->Add(this->LabelBracket);
			this->GroupBoxFunc->Controls->Add(this->LabelSemicolon);
			this->GroupBoxFunc->Controls->Add(this->LabelX);
			this->GroupBoxFunc->Controls->Add(this->LabelPhi);
			this->GroupBoxFunc->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GroupBoxFunc->Location = System::Drawing::Point(3, 3);
			this->GroupBoxFunc->Name = L"GroupBoxFunc";
			this->GroupBoxFunc->Size = System::Drawing::Size(421, 84);
			this->GroupBoxFunc->TabIndex = 0;
			this->GroupBoxFunc->TabStop = false;
			this->GroupBoxFunc->Text = L"Целевая функция";
			// 
			// TextBoxB
			// 
			this->TextBoxB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBoxB->Location = System::Drawing::Point(126, 47);
			this->TextBoxB->Name = L"TextBoxB";
			this->TextBoxB->Size = System::Drawing::Size(43, 27);
			this->TextBoxB->TabIndex = 6;
			this->TextBoxB->Text = L"3.0";
			// 
			// TextBoxA
			// 
			this->TextBoxA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBoxA->Location = System::Drawing::Point(57, 47);
			this->TextBoxA->Name = L"TextBoxA";
			this->TextBoxA->Size = System::Drawing::Size(43, 27);
			this->TextBoxA->TabIndex = 5;
			this->TextBoxA->Text = L"-3.0";
			// 
			// TextBoxPhi
			// 
			this->TextBoxPhi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBoxPhi->Location = System::Drawing::Point(71, 19);
			this->TextBoxPhi->Name = L"TextBoxPhi";
			this->TextBoxPhi->Size = System::Drawing::Size(331, 27);
			this->TextBoxPhi->TabIndex = 4;
			this->TextBoxPhi->Text = L"3sin(4x)+3cos(5x)";
			// 
			// LabelBracket
			// 
			this->LabelBracket->AutoSize = true;
			this->LabelBracket->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelBracket->Location = System::Drawing::Point(175, 49);
			this->LabelBracket->Name = L"LabelBracket";
			this->LabelBracket->Size = System::Drawing::Size(14, 20);
			this->LabelBracket->TabIndex = 3;
			this->LabelBracket->Text = L"]";
			// 
			// LabelSemicolon
			// 
			this->LabelSemicolon->AutoSize = true;
			this->LabelSemicolon->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelSemicolon->Location = System::Drawing::Point(106, 49);
			this->LabelSemicolon->Name = L"LabelSemicolon";
			this->LabelSemicolon->Size = System::Drawing::Size(14, 20);
			this->LabelSemicolon->TabIndex = 2;
			this->LabelSemicolon->Text = L";";
			// 
			// LabelX
			// 
			this->LabelX->AutoSize = true;
			this->LabelX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelX->Location = System::Drawing::Point(9, 49);
			this->LabelX->Name = L"LabelX";
			this->LabelX->Size = System::Drawing::Size(42, 20);
			this->LabelX->TabIndex = 1;
			this->LabelX->Text = L"x ∈ [";
			// 
			// LabelPhi
			// 
			this->LabelPhi->AutoSize = true;
			this->LabelPhi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelPhi->Location = System::Drawing::Point(9, 22);
			this->LabelPhi->Name = L"LabelPhi";
			this->LabelPhi->Size = System::Drawing::Size(56, 20);
			this->LabelPhi->TabIndex = 0;
			this->LabelPhi->Text = L"φ(x) =";
			// 
			// GroupBoxMethodParam
			// 
			this->GroupBoxMethodParam->Controls->Add(this->TextBoxNmax);
			this->GroupBoxMethodParam->Controls->Add(this->TextBoxEps);
			this->GroupBoxMethodParam->Controls->Add(this->TextBoxM);
			this->GroupBoxMethodParam->Controls->Add(this->TextBoxR);
			this->GroupBoxMethodParam->Controls->Add(this->LabelNmax);
			this->GroupBoxMethodParam->Controls->Add(this->LabelEps);
			this->GroupBoxMethodParam->Controls->Add(this->LabelM);
			this->GroupBoxMethodParam->Controls->Add(this->LabelR);
			this->GroupBoxMethodParam->Controls->Add(this->RadioButtonScan);
			this->GroupBoxMethodParam->Controls->Add(this->RadioButtonPiyavsky);
			this->GroupBoxMethodParam->Controls->Add(this->RadioButtonStrongin);
			this->GroupBoxMethodParam->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GroupBoxMethodParam->Location = System::Drawing::Point(3, 93);
			this->GroupBoxMethodParam->Name = L"GroupBoxMethodParam";
			this->GroupBoxMethodParam->Size = System::Drawing::Size(421, 164);
			this->GroupBoxMethodParam->TabIndex = 1;
			this->GroupBoxMethodParam->TabStop = false;
			this->GroupBoxMethodParam->Text = L"Метод и параметры";
			// 
			// TextBoxNmax
			// 
			this->TextBoxNmax->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBoxNmax->Location = System::Drawing::Point(302, 130);
			this->TextBoxNmax->Name = L"TextBoxNmax";
			this->TextBoxNmax->Size = System::Drawing::Size(100, 27);
			this->TextBoxNmax->TabIndex = 10;
			this->TextBoxNmax->Text = L"1000";
			// 
			// TextBoxEps
			// 
			this->TextBoxEps->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBoxEps->Location = System::Drawing::Point(141, 101);
			this->TextBoxEps->Name = L"TextBoxEps";
			this->TextBoxEps->Size = System::Drawing::Size(100, 27);
			this->TextBoxEps->TabIndex = 9;
			this->TextBoxEps->Text = L"0.001";
			// 
			// TextBoxM
			// 
			this->TextBoxM->Enabled = false;
			this->TextBoxM->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBoxM->Location = System::Drawing::Point(143, 72);
			this->TextBoxM->Name = L"TextBoxM";
			this->TextBoxM->Size = System::Drawing::Size(100, 27);
			this->TextBoxM->TabIndex = 8;
			this->TextBoxM->Text = L"5.0";
			// 
			// TextBoxR
			// 
			this->TextBoxR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBoxR->Location = System::Drawing::Point(135, 43);
			this->TextBoxR->Name = L"TextBoxR";
			this->TextBoxR->Size = System::Drawing::Size(100, 27);
			this->TextBoxR->TabIndex = 7;
			this->TextBoxR->Text = L"2.0";
			// 
			// LabelNmax
			// 
			this->LabelNmax->AutoSize = true;
			this->LabelNmax->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelNmax->Location = System::Drawing::Point(9, 133);
			this->LabelNmax->Name = L"LabelNmax";
			this->LabelNmax->Size = System::Drawing::Size(287, 20);
			this->LabelNmax->TabIndex = 6;
			this->LabelNmax->Text = L"Максимальное число итераций =";
			// 
			// LabelEps
			// 
			this->LabelEps->AutoSize = true;
			this->LabelEps->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelEps->Location = System::Drawing::Point(9, 104);
			this->LabelEps->Name = L"LabelEps";
			this->LabelEps->Size = System::Drawing::Size(126, 20);
			this->LabelEps->TabIndex = 5;
			this->LabelEps->Text = L"Точность, ε  =";
			// 
			// LabelM
			// 
			this->LabelM->AutoSize = true;
			this->LabelM->Enabled = false;
			this->LabelM->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelM->Location = System::Drawing::Point(9, 75);
			this->LabelM->Name = L"LabelM";
			this->LabelM->Size = System::Drawing::Size(128, 20);
			this->LabelM->TabIndex = 4;
			this->LabelM->Text = L"Параметр m =";
			// 
			// LabelR
			// 
			this->LabelR->AutoSize = true;
			this->LabelR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelR->Location = System::Drawing::Point(9, 46);
			this->LabelR->Name = L"LabelR";
			this->LabelR->Size = System::Drawing::Size(120, 20);
			this->LabelR->TabIndex = 3;
			this->LabelR->Text = L"Параметр r =";
			// 
			// RadioButtonScan
			// 
			this->RadioButtonScan->AutoSize = true;
			this->RadioButtonScan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RadioButtonScan->Location = System::Drawing::Point(239, 22);
			this->RadioButtonScan->Name = L"RadioButtonScan";
			this->RadioButtonScan->Size = System::Drawing::Size(103, 24);
			this->RadioButtonScan->TabIndex = 2;
			this->RadioButtonScan->TabStop = true;
			this->RadioButtonScan->Text = L"Перебор";
			this->RadioButtonScan->UseVisualStyleBackColor = true;
			this->RadioButtonScan->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RadioButtonScan_CheckedChanged);
			// 
			// RadioButtonPiyavsky
			// 
			this->RadioButtonPiyavsky->AutoSize = true;
			this->RadioButtonPiyavsky->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->RadioButtonPiyavsky->Location = System::Drawing::Point(122, 22);
			this->RadioButtonPiyavsky->Name = L"RadioButtonPiyavsky";
			this->RadioButtonPiyavsky->Size = System::Drawing::Size(111, 24);
			this->RadioButtonPiyavsky->TabIndex = 1;
			this->RadioButtonPiyavsky->Text = L"Пиявский";
			this->RadioButtonPiyavsky->UseVisualStyleBackColor = true;
			this->RadioButtonPiyavsky->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RadioButtonPiyavsky_CheckedChanged);
			// 
			// RadioButtonStrongin
			// 
			this->RadioButtonStrongin->AutoSize = true;
			this->RadioButtonStrongin->Checked = true;
			this->RadioButtonStrongin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->RadioButtonStrongin->Location = System::Drawing::Point(6, 22);
			this->RadioButtonStrongin->Name = L"RadioButtonStrongin";
			this->RadioButtonStrongin->Size = System::Drawing::Size(110, 24);
			this->RadioButtonStrongin->TabIndex = 0;
			this->RadioButtonStrongin->TabStop = true;
			this->RadioButtonStrongin->Text = L"Стронгин";
			this->RadioButtonStrongin->UseVisualStyleBackColor = true;
			this->RadioButtonStrongin->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RadioButtonStrongin_CheckedChanged);
			// 
			// ButtonStart
			// 
			this->ButtonStart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ButtonStart->Location = System::Drawing::Point(3, 263);
			this->ButtonStart->Name = L"ButtonStart";
			this->ButtonStart->Size = System::Drawing::Size(421, 64);
			this->ButtonStart->TabIndex = 2;
			this->ButtonStart->Text = L"Начать расчет";
			this->ButtonStart->UseVisualStyleBackColor = true;
			this->ButtonStart->Click += gcnew System::EventHandler(this, &MainForm::ButtonStart_Click);
			// 
			// GroupBoxInfo
			// 
			this->GroupBoxInfo->Controls->Add(this->TextBoxN);
			this->GroupBoxInfo->Controls->Add(this->TextBoxValMin);
			this->GroupBoxInfo->Controls->Add(this->TextBoxCoordMin);
			this->GroupBoxInfo->Controls->Add(this->LabelN);
			this->GroupBoxInfo->Controls->Add(this->LabelValMin);
			this->GroupBoxInfo->Controls->Add(this->LabelCoordMin);
			this->GroupBoxInfo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GroupBoxInfo->Location = System::Drawing::Point(3, 333);
			this->GroupBoxInfo->Name = L"GroupBoxInfo";
			this->GroupBoxInfo->Size = System::Drawing::Size(421, 150);
			this->GroupBoxInfo->TabIndex = 3;
			this->GroupBoxInfo->TabStop = false;
			this->GroupBoxInfo->Text = L"Справка";
			// 
			// TextBoxN
			// 
			this->TextBoxN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBoxN->Location = System::Drawing::Point(221, 73);
			this->TextBoxN->Name = L"TextBoxN";
			this->TextBoxN->ReadOnly = true;
			this->TextBoxN->Size = System::Drawing::Size(130, 27);
			this->TextBoxN->TabIndex = 5;
			// 
			// TextBoxValMin
			// 
			this->TextBoxValMin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBoxValMin->Location = System::Drawing::Point(254, 44);
			this->TextBoxValMin->Name = L"TextBoxValMin";
			this->TextBoxValMin->ReadOnly = true;
			this->TextBoxValMin->Size = System::Drawing::Size(130, 27);
			this->TextBoxValMin->TabIndex = 4;
			// 
			// TextBoxCoordMin
			// 
			this->TextBoxCoordMin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBoxCoordMin->Location = System::Drawing::Point(251, 15);
			this->TextBoxCoordMin->Name = L"TextBoxCoordMin";
			this->TextBoxCoordMin->ReadOnly = true;
			this->TextBoxCoordMin->Size = System::Drawing::Size(130, 27);
			this->TextBoxCoordMin->TabIndex = 3;
			// 
			// LabelN
			// 
			this->LabelN->AutoSize = true;
			this->LabelN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelN->Location = System::Drawing::Point(6, 76);
			this->LabelN->Name = L"LabelN";
			this->LabelN->Size = System::Drawing::Size(209, 20);
			this->LabelN->TabIndex = 2;
			this->LabelN->Text = L"Количество итераций =";
			// 
			// LabelValMin
			// 
			this->LabelValMin->AutoSize = true;
			this->LabelValMin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelValMin->Location = System::Drawing::Point(6, 47);
			this->LabelValMin->Name = L"LabelValMin";
			this->LabelValMin->Size = System::Drawing::Size(242, 20);
			this->LabelValMin->TabIndex = 1;
			this->LabelValMin->Text = L"Значение минимума, φ(x*) =";
			// 
			// LabelCoordMin
			// 
			this->LabelCoordMin->AutoSize = true;
			this->LabelCoordMin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelCoordMin->Location = System::Drawing::Point(6, 18);
			this->LabelCoordMin->Name = L"LabelCoordMin";
			this->LabelCoordMin->Size = System::Drawing::Size(239, 20);
			this->LabelCoordMin->TabIndex = 0;
			this->LabelCoordMin->Text = L"Координата минимума, x* =";
			// 
			// Chart
			// 
			this->Chart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->AxisX->Title = L"X";
			chartArea1->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			chartArea1->AxisY->Title = L"Y";
			chartArea1->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			chartArea1->Name = L"ChartArea1";
			this->Chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->Chart->Legends->Add(legend1);
			this->Chart->Location = System::Drawing::Point(436, 3);
			this->Chart->Name = L"Chart";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Color = System::Drawing::Color::DodgerBlue;
			series1->LabelBorderColor = System::Drawing::Color::Transparent;
			series1->Legend = L"Legend1";
			series1->Name = L"φ(x)";
			series2->BorderWidth = 4;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Square;
			series2->Name = L"x*";
			series3->BorderWidth = 2;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Color = System::Drawing::Color::Black;
			series3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series3->LabelBorderColor = System::Drawing::Color::Transparent;
			series3->Legend = L"Legend1";
			series3->MarkerSize = 3;
			series3->Name = L"Точки испытаний";
			series3->YValuesPerPoint = 4;
			this->Chart->Series->Add(series1);
			this->Chart->Series->Add(series2);
			this->Chart->Series->Add(series3);
			this->Chart->Size = System::Drawing::Size(973, 486);
			this->Chart->TabIndex = 4;
			this->Chart->Text = L"Chart";
			// 
			// TableLayoutPanelTask
			// 
			this->TableLayoutPanelTask->AutoSize = true;
			this->TableLayoutPanelTask->ColumnCount = 1;
			this->TableLayoutPanelTask->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->TableLayoutPanelTask->Controls->Add(this->GroupBoxMethodParam, 0, 1);
			this->TableLayoutPanelTask->Controls->Add(this->GroupBoxInfo, 0, 3);
			this->TableLayoutPanelTask->Controls->Add(this->ButtonStart, 0, 2);
			this->TableLayoutPanelTask->Controls->Add(this->GroupBoxFunc, 0, 0);
			this->TableLayoutPanelTask->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TableLayoutPanelTask->Location = System::Drawing::Point(3, 3);
			this->TableLayoutPanelTask->Name = L"TableLayoutPanelTask";
			this->TableLayoutPanelTask->RowCount = 4;
			this->TableLayoutPanelTask->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				90)));
			this->TableLayoutPanelTask->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				170)));
			this->TableLayoutPanelTask->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				70)));
			this->TableLayoutPanelTask->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->TableLayoutPanelTask->Size = System::Drawing::Size(427, 486);
			this->TableLayoutPanelTask->TabIndex = 5;
			// 
			// TableLayoutPanelMain
			// 
			this->TableLayoutPanelMain->AutoSize = true;
			this->TableLayoutPanelMain->ColumnCount = 2;
			this->TableLayoutPanelMain->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				433)));
			this->TableLayoutPanelMain->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->TableLayoutPanelMain->Controls->Add(this->Chart, 1, 0);
			this->TableLayoutPanelMain->Controls->Add(this->TableLayoutPanelTask, 0, 0);
			this->TableLayoutPanelMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TableLayoutPanelMain->Location = System::Drawing::Point(0, 0);
			this->TableLayoutPanelMain->Name = L"TableLayoutPanelMain";
			this->TableLayoutPanelMain->RowCount = 1;
			this->TableLayoutPanelMain->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->TableLayoutPanelMain->Size = System::Drawing::Size(1412, 492);
			this->TableLayoutPanelMain->TabIndex = 6;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1412, 492);
			this->Controls->Add(this->TableLayoutPanelMain);
			this->Name = L"MainForm";
			this->Text = L"Решение задачи одномерной оптимизации";
			this->GroupBoxFunc->ResumeLayout(false);
			this->GroupBoxFunc->PerformLayout();
			this->GroupBoxMethodParam->ResumeLayout(false);
			this->GroupBoxMethodParam->PerformLayout();
			this->GroupBoxInfo->ResumeLayout(false);
			this->GroupBoxInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Chart))->EndInit();
			this->TableLayoutPanelTask->ResumeLayout(false);
			this->TableLayoutPanelTask->PerformLayout();
			this->TableLayoutPanelMain->ResumeLayout(false);
			this->TableLayoutPanelMain->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RadioButtonStrongin_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		LabelR->Enabled = true; TextBoxR->Enabled = true;
		LabelM->Enabled = false; TextBoxM->Enabled = false;
		method = STRONGIN;
	}

	private: System::Void RadioButtonPiyavsky_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		LabelR->Enabled = false; TextBoxR->Enabled = false;
		LabelM->Enabled = true; TextBoxM->Enabled = true;
		method = PIYAVSKY;
	}

	private: System::Void RadioButtonScan_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		LabelR->Enabled = false; TextBoxR->Enabled = false;
		LabelM->Enabled = false; TextBoxM->Enabled = false;
		method = SCAN;
	}

	private: System::Void ButtonStart_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!Double::TryParse(TextBoxA->Text, System::Globalization::NumberStyles::Float, System::Globalization::CultureInfo::InvariantCulture, a)) {
			MessageBox::Show("a не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (!Double::TryParse(TextBoxB->Text, System::Globalization::NumberStyles::Float, System::Globalization::CultureInfo::InvariantCulture, b)) {
			MessageBox::Show("b не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (!Double::TryParse(TextBoxEps->Text, System::Globalization::NumberStyles::Float, System::Globalization::CultureInfo::InvariantCulture, eps)) {
			MessageBox::Show(L"ε не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		} else if (eps <= 0.0) {
			MessageBox::Show(L"ε меньше либо равно нулю", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (!Int32::TryParse(TextBoxNmax->Text, System::Globalization::NumberStyles::Float, System::Globalization::CultureInfo::InvariantCulture, Nmax)) {
			MessageBox::Show(L"Nₘₐₓ не число(целое)", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		} else if (Nmax <= 0) {
			MessageBox::Show(L"Nₘₐₓ меньше либо равно нулю", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		
		if (method == STRONGIN) {
			opt_method = strongin;
			if (!Double::TryParse(TextBoxR->Text, System::Globalization::NumberStyles::Float, System::Globalization::CultureInfo::InvariantCulture, r)) {
				MessageBox::Show(L"r не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			} else if (r <= 0.0) {
				MessageBox::Show(L"r меньше либо равно нулю", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		} else if (method == PIYAVSKY) {
			opt_method = piyavsky;
			if (!Double::TryParse(TextBoxM->Text, System::Globalization::NumberStyles::Float, System::Globalization::CultureInfo::InvariantCulture, m)) {
				MessageBox::Show(L"m не число", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			} else if (m <= 0.0) {
				MessageBox::Show(L"m меньше либо равно нулю", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		} else {
			opt_method = scan;
		}

		*function = msclr::interop::marshal_as<std::string>(TextBoxPhi->Text);
		a_analyzer.init(*function);
		try {
			a_analyzer.conversToRevPolNot();
		} catch (const exception &e) {
			String^ str = gcnew String(e.what());
			MessageBox::Show("Ошибка формульного анализатора(" + str + ")", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (a_analyzer.countVars() != 1) {
			MessageBox::Show("Ошибка формульного анализатора(неправильное количество аргументов функции)", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		opt_method->setA(a);
		opt_method->setB(b);
		opt_method->setEps(eps);
		if (method == STRONGIN) {
			dynamic_cast<strongin_method*>(opt_method)->setR(r);
		} else if (method == PIYAVSKY) {
			dynamic_cast<piyavsky_method*>(opt_method)->setM(m);
		}

		*N = Nmax;
		x = opt_method->solve(*N, ACCNUMBER);
		y = f(x);
		opt_method->getTrialPoints(*trial_points);

		TextBoxCoordMin->Text = x.ToString();
		TextBoxValMin->Text = y.ToString();
		TextBoxN->Text = (*N).ToString();

		double yMin, yMin_1, y_tmp;
		Chart->Series[L"φ(x)"]->Points->Clear();
		for (double i = a; i <= b; i += 0.01) {
			y_tmp = f(i);
			Chart->Series[L"φ(x)"]->Points->AddXY(i, y_tmp);
		}

		Chart->Series[L"x*"]->Points->Clear();
		Chart->Series[L"x*"]->Points->AddXY(x, y);

		Chart->Series[L"Точки испытаний"]->Points->Clear();

		Chart->Update();

		yMin = Chart->ChartAreas[0]->AxisY->PixelPositionToValue(Chart->ChartAreas[0]->AxisY->ValueToPixelPosition(Chart->ChartAreas[0]->AxisY->Minimum) - 1);
		yMin_1 = Chart->ChartAreas[0]->AxisY->PixelPositionToValue(Chart->ChartAreas[0]->AxisY->ValueToPixelPosition(Chart->ChartAreas[0]->AxisY->Minimum) - 10);

		// Найти минимум у нижнюю границу
		for (int i = 0; i < trial_points->size(); i++) {
			Chart->Series[L"Точки испытаний"]->Points->AddXY((*trial_points)[i].x, yMin);
			Chart->Series[L"Точки испытаний"]->Points->AddXY((*trial_points)[i].x, yMin_1);
			Chart->Series[L"Точки испытаний"]->Points->AddXY((*trial_points)[i].x, yMin_1);
			int count = Chart->Series[L"Точки испытаний"]->Points->Count;
			Chart->Series[L"Точки испытаний"]->Points[count - 1]->IsEmpty = true;
		}
	}
};
}
