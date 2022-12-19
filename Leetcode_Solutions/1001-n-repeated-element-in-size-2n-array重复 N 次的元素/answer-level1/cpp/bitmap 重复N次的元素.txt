![image.png](https://pic.leetcode-cn.com/9f9d305c2a7d1c29475330a97fd2136a9e20398da4a6fe7116d6000f415c418b-image.png)

class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		int bitmap[313];
		memset(&bitmap, 0, sizeof(bitmap));
		for (int i = 0; i < A.size(); i++)
		{
			int high = A[i] >> 5;
			int low = A[i] & 0x1F;
			if (bitmap[high] & (1 << low))
			{
				return 32 * high + low;
			}
			bitmap[high] |= (1 << low);
		}
		return -1;
	}
};