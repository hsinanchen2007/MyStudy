![image.png](https://pic.leetcode-cn.com/c7386a926fd3e1293403556ede191d3a3ad698c44b6a420dbfdfaf56a7b43dba-image.png)

### 解题思路
判断边界然后从头到尾遍历一次

### 代码

```cpp
class Solution {
public:
    //第一种：从头到尾遍历
    int searchInsert(vector<int>& nums, int target) {
        if (nums[nums.size() - 1] < target) { //判断最右边界值
            return nums.size();
        } else if (target <= nums[0]) { //判断最左边界
            return 0;
        } else {
            for (int i = 1; i < nums.size(); i++) { //如果夹在中间
                if (target == nums[i] || target <nums[i]) {
                    return i;
                } 
            }
        }
        return 0;
    }
};
```