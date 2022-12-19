老办法，双指针，分别指向奇数位和偶数位，遍历一次放到对应位置，同时挪动指针

代码：
```
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		int len = A.size();
		vector<int> ans(len);
		int i = 0, j = 1;
		for (int k = 0; k < len; k++) {
			if (A[k] % 2) {
				ans[j] = A[k];
				j = j + 2;
			}
			else {
				ans[i] = A[k];
				i = i + 2;
			}
		}
		return ans;
	}
};
```
