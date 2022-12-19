因为这个题有负数的存在，所以我们每次都要维护最大值和最小值
怎么维护呢？
其实我们遇到的数要么整要么负要么0
那最大值就是imax（当前最大值*新数， 当前最小值*新数， 新数）
最小值就是 imin（当前最大值*新数， 当前最小值*新数， 新数）

然后更新一下最终的最大值就可以了 res = max（res， imax）

`
```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int res = INT_MIN, imax = 1, imin = 1;
        for (int i = 0; i < n; i++)
        {
        	int tmp = imax;
        	imax = max(max(nums[i], imax * nums[i]), imin * nums[i]);
        	imin = min(min(nums[i], tmp * nums[i]), imin * nums[i]);
        	
        	res = max(res, imax);
		}
		
		return res;
    }
};
```

