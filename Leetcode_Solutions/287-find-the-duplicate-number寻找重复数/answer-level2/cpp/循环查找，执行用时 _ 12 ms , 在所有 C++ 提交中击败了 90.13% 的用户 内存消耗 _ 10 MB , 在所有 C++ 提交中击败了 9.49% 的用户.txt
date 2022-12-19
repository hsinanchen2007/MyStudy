#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		vector<int>q = nums;
		sort(q.begin(), q.end());
		int a = q.size();
		for (int i = 0; i < a; i++) {
			if (q[i] == q[i + 1]) { return q[i]; break; }
		}
		return 0;
	}
};