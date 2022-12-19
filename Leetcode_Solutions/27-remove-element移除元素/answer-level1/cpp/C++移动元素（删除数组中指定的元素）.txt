### 解题思路
此处撰写解题思路
首先要注意本题的要求是在原地做修改；
所以我们只需要从前到后将数组遍历一遍，然后寻找到要不要删除的元素将其移动到前面即可。
同时需要一个标志位来记录每一次需要放的位置。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int size = nums.size();
        int rev = 0; //设置标志
        for(int i = 0; i < size; i++)
        {
            if(nums[i] != val)
            {
               nums[rev] =  nums[i]; //将不等于val的数字移到数组的前面
               rev++; //同时将标志位移动一个
            }

        }
        return rev;       
    }
};
```