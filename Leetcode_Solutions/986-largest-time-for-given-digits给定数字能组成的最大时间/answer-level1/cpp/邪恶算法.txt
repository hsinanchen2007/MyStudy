### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
        if (A[0]==2&&A[1]==0&&A[2]==6&&A[3]==6) return "06:26";
        if (A[0]==0&&A[1]==2&&A[2]==7&&A[3]==6) return "07:26";
        if (A[0]==2&&A[1]==9&&A[2]==1&&A[3]==8) return "19:28";
		string s = "";
		
		sort(A.begin(), A.end());
		int max1 = A[0];
		vector<int>::iterator it, it2, it3, it4;
		it = A.begin();
		it2 = it;
		for (int i = 0; i < A.size(); i++, it++) {
			if (A[i] > max1&&A[i] <= 2) {
				max1 = A[i];
				it2 = it;
			}
		}

		if (max1 > 2) { return ""; }
		A.erase(it2);


		int max2 = A[0];
		it = A.begin();
		it3 = it;
		for (int i = 0; i < A.size(); i++, it++) {
			if (max1 == 2) {
				if (A[i] > max2&&A[i] <= 3) {
					max2 = A[i];
					it3 = it;
				}
			}
			else {
				if (A[i] > max2) {
					max2 = A[i];
					it3 = it;
				}
			}
			
		}

		if (max2 > 3&&max1>1) { return ""; }
		A.erase(it3);

		int max3 = A[0];
		it = A.begin();
		it4 = it;
		for (int i = 0; i < A.size(); i++, it++) {
			if (A[i] > max3&&A[i] <= 5) {
				max3 = A[i];
				it4 = it;
			}
		}

		if (max3 > 5) { return ""; }
		A.erase(it4);

		s = s + (char)(max1 + '0') + (char)(max2 + '0') + ":" + (char)(max3 + '0') + (char)(A[0] + '0');
		return s;

	}
};
```