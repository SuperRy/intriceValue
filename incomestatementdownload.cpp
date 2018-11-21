#include <stdio.h>
#include <urlmon.h>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <string>
// http://supercomputingblog.com/windows/how-to-download-html-with-c/
// that link is to download the html to a txt file in c++

// FIRST STEP
/*. Go to the Configuration Properties -> Linker -> Input window.
In the “Additional Dependencies” field, type urlmon.lib and press enter.
Apply your changes, and close the project properties window. */

// NEXT STEP
/* Configuration Properties -> General window.
Notice what the “Character Set” field is set to.
“Not Set” corresponds to using the ASCII character set.*/

// info on how this all works
/*This function returns an HRESULT error code, which is really just a long.
When dealing with HRESULTs, just keep in mind that zero is returned as success.
Therefore, it is always best to explicitly use the error code definitions, such as S_OK for success.*/

#define DLL_EXPORT
#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif
using namespace std;

char urlname1[300];
char urlname2[300];
char urlname3[300];
char urlname4[300];
char isfilename[21] = "incomestatment.txt";
char bsfilename[21] = "balancesheet.txt";
char cffilename[21] = "cashflow.txt";
char frfilename[21] = "finacialratios.txt";
//void main()

extern "C"
{	__declspec(dllexport) string donwloadincomestatement(string s)
{
	string nasdaq = "https://www.nasdaq.com/symbol/", symble;

	symble = s;

	string  incomestatement = "/financials?query=income-statement";
	strcpy_s(urlname1, (nasdaq + symble + incomestatement).c_str());
	HRESULT hr1 = URLDownloadToFile(NULL, urlname1, isfilename, 0, NULL);
	if (hr1 == S_OK)
	{
		ifstream istxt(isfilename);
	}
	else
	{
		cout << "ERRO CODE 1 " << hr1 << "\n";
	}


	//Balance sheet
	string balancesheet = "/financials?query=balance-sheet";
	strcpy_s(urlname2, (nasdaq + symble + balancesheet).c_str());
	HRESULT hr2 = URLDownloadToFile(NULL, urlname2, bsfilename, 0, NULL);
	if (hr2 == S_OK)
	{
		ifstream bstxt(bsfilename);
	}



	//cash flow
	string cashflow = "/financials?query=cash-flow";
	strcpy_s(urlname3, (nasdaq + symble + cashflow).c_str());
	HRESULT hr3 = URLDownloadToFile(NULL, urlname3, cffilename, 0, NULL);
	if (hr3 == S_OK)
	{
		ifstream istxt(cffilename);
	}



	// Financil Ratios
	string financilratios = "/financials?query=ratios";
	strcpy_s(urlname4, (nasdaq + symble + financilratios).c_str());
	HRESULT hr4 = URLDownloadToFile(NULL, urlname4, frfilename, 0, NULL);
	if (hr4 == S_OK)
	{
		ifstream istxt(frfilename);
	}

	return s;
}
}