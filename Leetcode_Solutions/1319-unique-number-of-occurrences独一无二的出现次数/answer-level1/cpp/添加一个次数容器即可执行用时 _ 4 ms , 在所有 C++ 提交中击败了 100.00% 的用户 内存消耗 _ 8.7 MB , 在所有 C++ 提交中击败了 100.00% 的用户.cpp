#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		if (arr.size() == 0) { return true; }
		sort(arr.begin(), arr.end());
		vector<int>q;
		int temp = arr[0];
		q.push_back(1);
		for (int i = 1; i < arr.size(); i++) {
			if (temp == arr[i]) { q[q.size() - 1]++; }
			else {
				    temp = arr[i];
					q.push_back(1);
			}		
			if ((i + 1 <arr.size() && arr[i + 1] != temp) || i + 1 >=arr.size()) {
						for (int j = 0; j < q.size() - 1; j++) {
							if (q[q.size() - 1] == q[j]) { return false; }
						}
					}
		}
		return true;
	}
};