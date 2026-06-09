### 解题思路
**本题类似于第26题“删除排序数组中的重复项”：定义两个指针，一个快指针i，一个慢指针j。**

**起始时，令j指向第一个元素，让i从第一个元素开始遍历，当遍历到一个元素值不等于val时，就把当前遍历到的这个值赋值给第一个元素，即，让第一个元素更改为当前遍历到的这个值。然后令j+1。**

**以此类推，直到遍历完整个数组。由于不需要考虑数组中超出新长度后面的元素，因此只需要把前j个值更改完即可，不用考虑后面的值。**

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
        {
            return 0;
        }
        int j = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] != val)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
```