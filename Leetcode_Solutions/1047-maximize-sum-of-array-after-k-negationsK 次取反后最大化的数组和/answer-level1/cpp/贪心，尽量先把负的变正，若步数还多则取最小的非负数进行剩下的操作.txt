解题思路如题。当然也可以次次进行排序，然后取最小值取反，不过这样用时会长一点。
代码如下：
```
class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		for (int i = 0; i < A.size(); i++) {
			if (K > 0) {
				if (A[i] < 0) {
					A[i] = -A[i];
					K--;
				}
				else {
					if (K % 2 == 1) {
						if (i == 0 || (i != 0 && A[i] < A[i - 1]))
							A[i] = -A[i];
						else if(i != 0 && A[i] >= A[i - 1])
							A[i-1] = -A[i-1];
					}					
					K = 0;
				}
			}
			else
				break;
		}
		int sum = 0;
		for (int i = 0; i < A.size(); i++)
			sum += A[i];
		return sum;
	}
};
```
