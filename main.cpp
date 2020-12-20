#include <cstdlib>
#include <iostream>
#include "fileMang.h"

using namespace std;

int main() {

	fileMang FM;
	string flagCheck = "y";

	do {
		int userinput;

		cout << "Tasks to perform" << endl;
		cout << "1: Create File" << endl;
		cout << "2: Delete Existing File" << endl;
		cout << "3: Open File" << endl;
		cout << "4: Move File Content" << endl;
		cout << "5: Save Memory Map\n" << endl;
		cout << "Enter no. (of which task to perform)" << endl;

		cin >> userinput;

		switch (userinput){

			case 1: {
				string fileName;
				cout << "Enter File Name: ";
				cin >> fileName;
				if (FM.fifFileExists(fileName) == 1) {
					cout << "The file '" << fileName << "' already prsent in the directory" << endl;
				}
				else {
					FM.fcreateFile(fileName);
				}
				break;
			}
			case 2: {
				string fileName;
				cout << "Enter file-Name to Delete: ";
				cin >> fileName;
				if (FM.fifFileExists(fileName)) {
					FM.fdeleteFile(fileName);				
				}
				else {
					cout << "File with this name (" << fileName << ") is not available in the directory" << endl;
				}
				break;
			}

			case 3: {
				string fileName, dummy;
				cout << "Enter the file-name to open: ";
				cin >> fileName;
				if (FM.fifFileExists(fileName) == 1) {
					string opentype;
					cout << "On which mode you want to open the file : " << endl;
					cout << "r (for read)" << endl;
					cout << "rf (for read from specific location in a file)" << endl;
					cout << "wt(for write at aspecific location)" << endl;
					cout << "w (to write)" << endl;
					cout << "a (to append to text)" << endl;
					cin >> opentype;
					getline(cin, dummy);
					if (opentype == "r" || opentype == "w" || opentype == "a") {
						FM.fopenFile(fileName, opentype);
					}
					else if (opentype == "rf") {
						int position, length;
						cout << "Enter location to start from (in the file): " << endl;
						cin >> position;
						cout << "Enter total characters to read after position: " << endl;
						cin >> length;
						FM.freadFrom(fileName, position, length);
					}
					else {
						cout << "Invalid Mode value is Entered" << endl;
					}
				}
				else {
					cout << "The file does (" << fileName << ") not exits in the directory:" << endl;
				}

				break;
			}

			case 4: {
				string sourceFileName, destintionFileName;
				cout << "Enter the source File-Name: ";
				cin >> sourceFileName;
				if (FM.fifFileExists(sourceFileName)) {
					cout << "Enter the destination/target File-Name: ";
					cin >> destintionFileName;
					if (FM.fifFileExists(destintionFileName)) {
						FM.fmoveFile(sourceFileName, destintionFileName);
					}
					else {
						cout << "The target File does not exist: " << destintionFileName << endl;
					}
				}
				else {
					cout << "The source File does not exist: " << sourceFileName << endl;
				}
				break;
			}

			case 5: {
				FM.fprintToCheck();
				break;
			}

			case 6: {
				FM.fprintDeleteVector();
				break;
			}

			default:
				cout << "Entered invalied output" << endl;
				break;
		}
		cout << "Do you want to continue [Y/N]: ";
		cin >> flagCheck;
	} while (flagCheck == "y" || flagCheck == "Y");

	//fileMang fM;
	////	fM.createFile("ahmad");

	//fM.fcreateFile("ali");
	//fM.fcreateFile("ahmad");
	//////	fM.fcreateFile("ali2");


	//fM.fopenFile("ali", "w");
	//////	fM.fprintToCheck();

	////cout << "------------------------------------------------" << endl;

	//fM.fopenFile("ahmad", "w");
	//////	fM.fprintToCheck();

	////cout << "------------------------------------------------" << endl;

	////fM.fopenFile("ali", "a");
	//////	fM.fprintToCheck();

	////cout << "------------------------------------------------" << endl;

	//fM.fprintToCheck();

	////cout << "------------------------------------------------" << endl;
	////cout << "                     Read File                  " << endl;
	////cout << "------------------------------------------------" << endl;

	////fM.fopenFile("ali", "r");

	////cout << "------------------------------------------------" << endl;
	////cout << "Delete Function Check";
	////cout << "------------------------------------------------" << endl;

	////cout << "------------------------------------------------" << endl;
	////cout << "                     Address Check              " << endl;
	////cout << "------------------------------------------------" << endl;



	////fM.fcreateFile("zargham");
	////fM.fopenFile("zargham", "w");

	////cout << "------------------------------------------------" << endl;
	////cout << "                     Check File                 " << endl;
	////cout << "------------------------------------------------" << endl;

	////fM.fprintToCheck();
	//fM.fmoveFile("ali", "ahmad");
	//fM.fprintToCheck();

	//cout << endl;


	//for (int i = 0; i < fM.deleteInfoVector.size(); i++) {
	//	cout << fM.deleteInfoVector.at(i) << " ";
	//}


	//fM.fcreateFile("zargham");
	//fM.fopenFile("zargham", "w");
	//fM.fprintToCheck();


	//cout << endl;


	//for (int i = 0; i < fM.deleteInfoVector.size(); i++) {
	//	cout << fM.deleteInfoVector.at(i) << " ";
	//}

	//cout << fM.dataVector.size() << endl;

	return 0;

}