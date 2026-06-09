平方再排序为常规做法，不过忽略了有序条件

由于数组有序，较大平方必然位于两侧，故而采用双指针法，一头一尾，遇到较大平方则插入并移动指针

代码：
```
class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		int length = A.size();
		vector<int> ans(length);
		int i = 0, j = length - 1,k = length - 1;
		while (k >= 0) {
			int a = A[i] * A[i];
			int b = A[j] * A[j];
			if (a > b) {
				ans[k] = a;
				i++;
			}
			else {
				ans[k] = b;
				j--;
			}
			k--;
		}
		return ans;
	}
};
```
