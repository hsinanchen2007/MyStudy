执行用时 :28 ms, 在所有 C++ 提交中击败了88.77%的用户
内存消耗 :28.6 MB, 在所有 C++ 提交中击败了5.17%的用户

任何小问题都能被自己搞得很复杂，这么简单的问题居然被自己搞出这么多分支，还好执行速度可以，不过内存占用太多
还是逻辑思维能力不行，继续练吧
```
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int index = A.size() -1;
		int jinwei = 0;
		int sum = 0;
		while (K && index >= 0)
		{
			sum = A[index] +  K % 10 + jinwei;
			A[index] = sum % 10;
			jinwei = sum / 10;
			K /= 10;
			--index;
		}

		if (K==0 && index < 0)
		{
			if (jinwei != 0)
				A.insert(A.begin(), jinwei);
			return A;
		}
		else if (K == 0)
		{
			if (jinwei == 0)
				return A;

			while (jinwei != 0) {
				if (index < 0) {
					A.insert(A.begin(), 0);
					index = 0;
				}
				sum = A[index] + jinwei;
				A[index] = sum % 10;
				jinwei = sum / 10;
				--index;
			}

			return A;
		}
		else
		{
			while (K)
			{
				sum = K % 10 + jinwei;
				A.insert(A.begin(), sum % 10);
				jinwei = sum / 10;
				K /= 10;
			}

			if (jinwei)
				A.insert(A.begin(),jinwei);

			return A;
		}
	}
};
```
