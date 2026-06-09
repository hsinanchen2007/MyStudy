核心思想还是基数排序，32位的分为4部分，每部分8位，减少空间使用以及寻址时间。
```
class Solution {
    
public:
    #define M  255
    #define N  256
    unsigned cnt[N];
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int tmp[nums.size()] = {0};
        
        for (int i = 0; i < nums.size(); i++)
		    cnt[nums[i] & M]++;
	    for (int i = 1; i < N; i++)
		    cnt[i] += cnt[i - 1];
	    for (int i = nums.size() - 1; i >= 0; i--)
		    tmp[--cnt[nums[i] & M]] = nums[i];
        
	    memset(cnt,0,sizeof(cnt));
	    for (int i = 0; i < nums.size(); i++)
		    cnt[tmp[i] >> 8 & M]++;
	    for (int i = 1; i < N; i++)
		    cnt[i] += cnt[i - 1];
	    for (int i = nums.size() - 1; i >= 0; i--)
		    nums[--cnt[tmp[i] >> 8 & M]] = tmp[i];
        
        memset(cnt,0,sizeof(cnt));
        memset(tmp,0,sizeof(tmp));
       
        for (int i = 0; i < nums.size(); i++)
		    cnt[nums[i]>>16 & M]++;
	    for (int i = 1; i < N; i++)
		    cnt[i] += cnt[i - 1];
	    for (int i = nums.size() - 1; i >= 0; i--)
		    tmp[--cnt[nums[i]>>16 & M]] = nums[i];
       
	    memset(cnt,0,sizeof(cnt));
	    for (int i = 0; i < nums.size(); i++)
		    cnt[tmp[i] >> 24 ]++;
	    for (int i = 1; i < N; i++)
		    cnt[i] += cnt[i - 1];
	    for (int i = nums.size() - 1; i >= 0; i--)
		    nums[--cnt[tmp[i] >> 24]] = tmp[i];
        
        int maxn = 0;
        for(int i = 0; i < nums.size() - 1; i ++)
        {
            maxn = max(maxn,nums[i + 1] - nums[i]);
        }
        return maxn;
    }
};
```
