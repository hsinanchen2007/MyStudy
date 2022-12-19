[题目描述](https://leetcode-cn.com/problems/move-zeroes/)
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
>示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

#### 思路：双指针
这个题相对来说比较简单，所以简写一下。
> 这个题采用新数组生成思想，其实不用移动

遍历一遍数组， 设置一个非零元素计数器counot0, 如果当前元素不是0， nums[counot0++] = 当前元素
    遍历一遍之后，从counot0位置开始，到len-1， 全置为0.
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();

        int cou_not0 = 0;
        for (int i=0; i<len; i++)
        {
            if (nums[i] != 0)
                nums[cou_not0++] = nums[i];
        }

        for (int i=cou_not0; i<len; i++)
            nums[i] = 0;
    }
};
```
改进思路就是上面的两次循环，可以写到一个里面：就是在判断出该位置元素不等于0之后，看看是不是等于新数组的末尾指针counot0，如果不是，直接置为0即可。

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();

        int cou_not0 = 0;
        for (int i=0; i<len; i++)
        {
            if (nums[i] != 0)
            {
                nums[cou_not0] = nums[i];
                if (cou_not0 != i)
                    nums[i] = 0;
                cou_not0++;
            }
        }
    }
};
```
