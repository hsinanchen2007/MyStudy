
先将数组排序，排序后找出序列中0 的个数
再求非零元素间的差值，只要保证，0的个数与非零元素间做差的次数 的和 大于等于非零元素间的差值，就可以组成连续数。
```
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int num=0;//元素0 的个数
        int i=0;
        int del=0;//记录非零元素的差值
        while(nums[i]==0)
        {
            num++;
            i++;
        }
        for(;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                return false;//当有相同的元素时返回false
            }
            del+=nums[i+1]-nums[i];
            num++;//此时num也要加一
        }
        return num>=del?true:false;
    }
};
```
