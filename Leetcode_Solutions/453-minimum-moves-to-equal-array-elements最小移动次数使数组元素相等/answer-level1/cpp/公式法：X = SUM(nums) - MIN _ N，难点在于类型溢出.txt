```
class Solution {
public:

    int minMoves(vector<int>& nums) 
    {
        if(nums.size()<=1)
            return 0;
        // 公式： X = SUM(nums) - MIN * N
        // 直接按公式写，需要考虑类型溢出，sum尽量给大些
        // int n = nums.size(), min = nums[0];
        // long long sum = 0;
        // for(int i=0;i<n;i++)
        // {
        //     sum += nums[i];
        //     if(min > nums[i])
        //         min = nums[i];
        // }
        // return sum - min * n;          

        // 公式变形：X = sum(nums[i] - min)
        int n = nums.size(), min = nums[0], res = 0;
        for(int i=1;i<n;i++)
        {
            if(min > nums[i])
                min = nums[i];
        }
        for(int i=0;i<n;i++)
        {
            res += nums[i] - min;
        }
        return res;
    }
};
```