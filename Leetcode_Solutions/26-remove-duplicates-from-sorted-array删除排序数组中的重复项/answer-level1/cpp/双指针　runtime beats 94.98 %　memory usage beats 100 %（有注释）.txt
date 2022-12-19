一直很菜鸟的我，看到这道题居然挺有灵感，不用看题解便自己想出了双指针的方法，提交后发现效果还不错，故分享下。
大体思路就是将所有不重复的数字移动到数组的前面，使用一个慢指针指向不重复数字的最后一个数字，一个快指针。例如快指针当前遍历到数组的第５位，而这５位数字中有２个是不重复数字，那么慢指针指向的下标是１，下标为０和下标为１的都是不重复的数字。
代码如下：
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int len = nums.size();
        if(len < 2)
            return len;
        int first = 0;　//　慢指针
        int second;　// 快指针
        for(second = 1; second < len; second++)
        {
            if(nums[first] == nums[second])　// 两个指针所指向的数字相同的话，快指针继续往前遍历
                continue;
            else
            {
                int tmp = nums[second];
                nums[second] = nums[first+1]; // 两指针所指向的数字不一样的话，说明又出现一个不重复数字，于是将second和first+1所指向的下标互换（注意是first+1）
                nums[++first] = tmp;
            }     
        }
        return first+1;
    }
};
```
