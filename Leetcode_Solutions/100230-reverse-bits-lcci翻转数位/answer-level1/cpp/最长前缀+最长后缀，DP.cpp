```
class Solution {
public:
	int reverseBits(int num) {
		int dp1[32] = { 0 };
		int dp2[32] = { 0 };
		int count = 0;
		int n = num;
		while (count < 32)
		{
			if (count == 0)
				dp1[count] = n % 2;
			else
				dp1[count] = n % 2 ? dp1[count - 1] + 1 : 0;
			count++;
			n >>= 1;
		}
		n = num;
		int idx = 31;
		while (idx >= 0)
		{
			if (idx == count)
				dp2[idx] = (n & (1 << idx)) >> idx;
			else
				dp2[idx] = ((n & (1 << idx)) >> idx) ? dp2[idx + 1] + 1 : 0;
			idx--;
		}

		int ret = 1;
		for (int i = 0; i < 32; i++)
		{
			if (i == 0)
				ret = max(ret, dp2[i + 1] + 1);
			else if (i == 31)
				ret = max(ret, dp1[i - 1] + 1);
			else
			{
				if (num & (1 << i))
					ret = max(max(dp1[i], dp2[i]), ret);
				else
					ret = max(dp1[i - 1] + dp2[i + 1] + 1, ret);
			}
		}
		return ret;
	}
};
```
