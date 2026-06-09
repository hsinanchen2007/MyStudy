```
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        if(n==1) return nums[0];
        //以三个房子举例，房子1的钱小于房子2的钱，现在来到了房子3
        int curmax=0;//房子2价格，边界
        int premax=0;//房子1价格，边界
        for(int x:nums)
        {
            int temp=curmax;
            curmax=max(curmax,(premax+x));//状态转移公式
            premax=temp;
        }
        return curmax;
    }
```
