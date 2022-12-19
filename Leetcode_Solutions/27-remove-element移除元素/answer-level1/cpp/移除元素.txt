### 解题思路
此处撰写解题思路
使用两个指针i,j，i从左往右遍历数组，直到找到等于val的元素，j从右向左遍历元素，直到找到不等于val的元素，用j位置的元素值覆盖i位置的元素
循环终止条件是i>j，此时i的值即为移除元素后的数组长度
### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, j=nums.size()-1;
        while(i <= j)
        {
            while((i <= j) && (nums[i] != val))
            {
                i++;
            }
            if(i > j)
            {
                break;
            }
            
            while((j >= i) && (nums[j] == val))
            {
                j--;
            }
            if(j < i)
            {
                break;
            }
            nums[i++] = nums[j--];
        }
        return i;
    }
};
```