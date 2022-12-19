双指针，并借助计数器记录数字的个数
1. 若当前元素不等于nums[pre]，nums[++pre]等于当前元素，计数器重置为1
2. 若当前元素等于nums[pre]同时个数小于2，nums[++pre]等于当前元素，计数器加1
``` C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=1;
        int count=1;//计数器，用于记录数出现的次数
        int pre=0;
        for (int cur=1;cur<nums.size();cur++)
        {
            if(nums[pre]!=nums[cur])//若当前元素不等于nums[pre]，nums[++pre]等于当前元素
            {
                nums[++pre]=nums[cur];
                count=1;//计数器重置为1
                res++;
            }
            else if(nums[pre]==nums[cur]&&count<2)//若当前元素等于nums[pre]同时个数小于2，nums[++pre]等于当前元素
            {
                nums[++pre]=nums[cur];
                count++;//计数器加1
                res++;
            }
        }
        return res;
    }
};
```