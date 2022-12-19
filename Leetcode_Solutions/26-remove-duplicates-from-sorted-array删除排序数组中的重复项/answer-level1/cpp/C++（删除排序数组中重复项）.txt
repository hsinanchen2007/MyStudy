### 解题思路
此处撰写解题思路
本题要求在原地进行修改，不需要考虑s数组中超出新长度后面的元素。
我们只需要就原来的数字覆盖掉即可：
（1）从前到后进行遍历，设置一个变量result来存储每一个不重复的数；
（2）设置一个标记变量rev，记录每一个不重复数字的位置，而且可以作为最后数组长度返回。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int size = nums.size();
        if(size == 0) return 0;
        int rev = 0;
        for(int i = 1; i < size; i++)
        {
            int result = nums[rev];
            if(nums[i] != result)
            {
                rev++;
                nums[rev] = nums[i];
            }
        }
        return rev+1;
    }
};
```