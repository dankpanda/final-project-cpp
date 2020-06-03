///-----------------------------------------------------------------
///
/// @file      Final Project GUIFrm.cpp
/// @author    Eric Edgari , Yowen , William
/// Created:   02/06/2020 18:51:57
/// @section   DESCRIPTION
///            Final_Project_GUIFrm class implementation
///
///------------------------------------------------------------------



#include "Final Project GUIFrm.h"
#include<iostream>
using namespace std;

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
#include "Images/Final_Project_GUIFrm_frmNewForm_XPM.xpm"
////Header Include End

//----------------------------------------------------------------------------
// Final_Project_GUIFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Final_Project_GUIFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Final_Project_GUIFrm::OnClose)
	EVT_ACTIVATE(Final_Project_GUIFrm::Final_Project_GUIFrmActivate)
	EVT_BUTTON(ID_ADD,Final_Project_GUIFrm::TotalClick)
	
	EVT_TEXT(ID_WXEDIT1,Final_Project_GUIFrm::WxEdit1Updated)
END_EVENT_TABLE()
////Event Table End




Final_Project_GUIFrm::Final_Project_GUIFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
	
	
}

Final_Project_GUIFrm::~Final_Project_GUIFrm()
{
}

void Final_Project_GUIFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("ID"), wxPoint(25, 84), wxDefaultSize, 0, _("WxStaticText3"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Name"), wxPoint(17, 48), wxDefaultSize, 0, _("WxStaticText2"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("ID"), wxPoint(-24, 104), wxDefaultSize, 0, _("WxStaticText1"));

	WxListCtrl1 = new wxListCtrl(this, ID_WXLISTCTRL1, wxPoint(44, 134), wxSize(250, 150), wxLC_REPORT, wxDefaultValidator, _("WxListCtrl1"));
	WxListCtrl1->InsertColumn(0, _("ID"), wxLIST_FORMAT_LEFT, 100);
	WxListCtrl1->InsertColumn(1, _("Name"), wxLIST_FORMAT_LEFT, 100);

	Add = new wxButton(this, ID_ADD, _("Add"), wxPoint(236, 50), wxSize(75, 25), 0, wxDefaultValidator, _("Add"));

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, _("6"), wxPoint(75, 82), wxSize(121, 19), 0, wxDefaultValidator, _("WxEdit2"));

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("Jack"), wxPoint(75, 45), wxSize(121, 19), 0, wxDefaultValidator, _("WxEdit1"));

	SetTitle(_("Final Project GUI"));
	SetIcon(Final_Project_GUIFrm_frmNewForm_XPM);
	SetSize(8,8,501,396);
	Center();
	
	////GUI Items Creation End
}

void Final_Project_GUIFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * Final_Project_GUIFrmActivate
 */
void Final_Project_GUIFrm::Final_Project_GUIFrmActivate(wxActivateEvent& event)
{
    
}

/*
 * TotalClick
 */
void Final_Project_GUIFrm::TotalClick(wxCommandEvent& event)
{
	// insert your code here
	WxListCtrl1->DeleteAllItems();
	string name = string(WxEdit1->GetValue().mb_str());
	int id = wxAtoi(WxEdit2->GetValue());
	updateTree(id,name);	
    updateListBox();

   
}



/*
 * WxEdit1Updated
 */
void Final_Project_GUIFrm::WxEdit1Updated(wxCommandEvent& event)
{
	// insert your code here
}


    
void Final_Project_GUIFrm::updateTree(int id , string name){
    myTree.insert(id,name);
    myHash.insertItem(name,id);
    

}
void Final_Project_GUIFrm::updateListBox(){
    
    vector<int> idList = myTree.getIdList();
    vector<string> nameList = myTree.getNameList();
    
    
    
    
    for (int i = 0 ; i < idList.size();i++){
        
        wxString id;
        id<<idList[i];
        WxListCtrl1->InsertItem(i,id);
        
        wxString name(nameList[i]);;
        
        WxListCtrl1->SetItem(i,1,name);
        
        
        }
        
    }
    



/*
 * WxListBox1Selected
 */
void Final_Project_GUIFrm::WxListBox1Selected(wxCommandEvent& event)
{
	// insert your code here
}



