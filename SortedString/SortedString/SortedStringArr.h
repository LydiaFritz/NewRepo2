#pragma once
#include <string>

using namespace std;

class SortedStringArr {
private:
	int numItems;
	int capacity;
	string * strArr;

	void ensureCapacity(int n) {
		if (strArr == NULL) {
			strArr = new string[n];
			capacity = n;
		}
		else {
			
			string * temp = new string[n];
			//copy from this strArr to temp
			for (int i = 0; i < this->numItems; i++) {
				temp[i] = strArr[i];
			}
			delete[] strArr;
			strArr = temp;
			capacity = n;
		}
	}

public:
	SortedStringArr() {
		strArr = NULL;
		capacity = numItems = 0;
	}
	~SortedStringArr() {
		delete[] strArr;
	}
	void add(string s) {
		if (strArr == NULL)
			ensureCapacity(1);
		else if (numItems == capacity)
			ensureCapacity(2 * numItems);

					
	}


};
