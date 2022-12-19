
考虑到大佬们爱用指针这个吓坏萌新的名词，我决定换种说法——遍历数组，当遇到一个更大的数字时，用它覆盖掉当前的数字，并把返回长度加一。此题的切入点是如果可以额外开辟数组空间，那么不需要覆盖当前数组，进而根据题目O(1) memory的要求，考虑覆盖操作。
代码如下
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int len = 1;
        int big = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != big)
            {
                // a bigger non-duplicated number, overrite the original array and count
                big = nums[i];
                nums[len] = big;
                len++;               
            }
           // else it's a duplicated number, skip

        }
        return len;
    }
};
```
