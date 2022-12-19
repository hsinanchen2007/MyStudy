### 解题思路
如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。
### 代码

```cpp
class Solution {
public:
   bool canThreePartsEqualSum(vector<int>& A)
	{
		int nSize = A.size();
		if (3 > nSize)
		{
			return false;
		}
		int nSum = 0;//数组所有元素的和
		for (int i = 0; i < nSize; i++)
		{
			nSum += A[i];
		}
		if (0 != nSum % 3 )
		{
			return false;
		}
		int nOneThird = nSum / 3;
		int nSum1 = 0;
		int i = 0;
		bool bIsFind = false;
		for (i = 0; i < nSize; i++)
		{
			nSum1 += A[i];
			if (nOneThird == nSum1)
			{
				bIsFind = true;
				break;
			}
		}
		if (!bIsFind)
		{
			return false;
		}

		bIsFind = false;
		int j = 0;
		nSum1 = 0;
		for (j = nSize - 1; i >= 0; j--)
		{
			nSum1 += A[j];
			if (nOneThird == nSum1)
			{
				bIsFind = true;
				break;
			}
		}
		if (!bIsFind)
		{
			return false;
		}

        if (i + 1 >= j)
		{
			return false;
		}
        
		return true;

	}
};
```