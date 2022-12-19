# 注意事项

-  先要有一个判空，不然样例空数组会出错，报错：
`Line 923: Char 34: runtime error: reference binding to null pointer of type 'value_type' (stl_vector.h)`
- 由于if语句中用了nums[i+1],所以for循环中i要小于数组长度-1，否则会出现数组越界错误：
`AddressSanitizer: heap-buffer-overflow on address 0x6020000000d4 at pc 0x0000004058e0 bp 0x7ffca4d04a00 sp 0x7ffca4d049f0`
- 或者可以令i=1,判断nums[i] == nums[i-1]

# 代码

```class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        if(nums.size()==0) return false;

        sort (nums.begin(), nums.end() );

        for(int i=0; i < nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1]) 
            {
                return true;
            }
        }

        return false;
    }
};