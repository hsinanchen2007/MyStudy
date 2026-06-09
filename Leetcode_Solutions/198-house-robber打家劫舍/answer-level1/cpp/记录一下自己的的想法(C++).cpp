我自己在写的时候也是用了动态规划，但是与官方解法不同的是，我考虑的是上一个抢劫房子是i-2还是i-3(因为不能连续抢劫，所以i-1一定不可能)
```
class Solution {
public:
    int rob(vector<int>& nums) {
	    int n_len = nums.size();
	    if(n_len < 1)
	    	return 0;
	    int n_2 = 0;
	    int n_3 = 0;
	    if(n_len == 1)
		    return nums[0];
	    for(int i=0;i<n_len;i++){
		    n_2 = i-2>=0?nums[i-2]:0;
		    n_3 = i-3>=0?nums[i-3]:0;
		    nums[i] += (n_2>n_3)?n_2:n_3;
	    }
	    return nums[n_len-1]> nums[n_len-2]?nums[n_len-1]:nums[n_len-2];
    }
};
```

老实说写的有些麻烦了，官方解法要简洁很多，还是要学习一个。
