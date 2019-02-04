#include "iostream"
#include "utility"
#include "fstream"
#include "vector"

using namespace std;

bool contains(pair<int, int> p, vector <pair<int, int>> vec);

int main() {
	ifstream fin("input.txt");
	if (!fin) {
		cerr << "File not found.\n";
		exit(2);
	}
	else
		cout << "File found\n";
	pair<int, int> temp;


	//creates a vector of paris of ints
	vector<pair<int, int>> blockedCells;
	vector<pair<int, int>> start;
	int numCols, numRows;
	vector<pair<int, int>> end;
	// input 
	fin >> numCols >> numRows;

	for (int i = 0; i < 1; i++) {
		(fin >> temp.first >> temp.second);
		start.push_back(temp);
	}


	for (int i = 0; i < 1; i++) {
		(fin >> temp.first >> temp.second);
		end.push_back(temp);
	}
	//fin >> start.first >> start.second;

	while (fin >> temp.first >> temp.second) {
		// push temp onto the vector
		blockedCells.push_back(temp);
		//	cout << blockedCells.assign = vector<pair<int,int>>;
	}
	int k = 0;
	int t = 0;


	for (int i = 0; i < 11; i++) {
		cout << " " << i << "  ";
	}
	cout << endl;

	for (int i = 0; i < numCols; i++) {
		/*cout << "    " << endl;
		cout << " " << i << "  " << endl;
		cout << "    " << endl;*/


		for (int w = 0; w < 3; w++) {


			for (int j = 0; j < numRows; j++) {

				//switch (w) {
				//	case 1:
				//		//cout with s or e
				//		break;
				//	default:
				//		//cout regular
				//		break;
				//}
				//if ((i, j) = start[i].first, start[j].second) {
				/*	cout << "fuckkkkkk'";

				}*/


				if (contains(pair<int, int>(i, j), start)) {
					switch (w) {
						//case 1:
						//cout << "    ";
					case 0:
						cout << "--- ";
						continue;
					case 1:
						cout << "-S- ";
						continue;
					case 2:
						cout << "--- ";
						continue;
					}

					//cout << "-S- ";

					continue;
				}
				if (contains(pair<int, int>(i, j), end)) {
					switch (w) {
						//case 1:
						//cout << "    ";
					case 0:
						cout << "--- ";
						continue;
					case 1:
						cout << "-E- ";
						continue;
					case 2:
						cout << "--- ";
						continue;
					}
					//cout << "-E- ";
					continue;
				}


				if (contains(pair<int, int>(i, j), blockedCells)) {
					cout << "XXX ";
					k++;
					t++;
					continue;
				}

				else {
					cout << "--- ";
				}

			}
			k = 0;
			switch (w) {
				//case 1:
				//cout << "    ";
			case 1:
				cout << " " << i << "  ";
			case 2:
				cout << "    ";
			}

			cout << endl;


		}



		//cout <<  endl;
	}



	/*for (int i = 0; i < blockedCells.size(); i++) {

	cout << blockedCells[i].first;
	cout << blockedCells[i].second << endl;


	}*/


	return 0;
}

bool contains(pair<int, int> p, vector<pair<int, int>> vec)
{
	int i = 0;
	while (i < vec.size()) {
		if (p.first == vec[i].first &&
			p.second == vec[i].second)
			return true;
		i++;
	}
	return false;


}
