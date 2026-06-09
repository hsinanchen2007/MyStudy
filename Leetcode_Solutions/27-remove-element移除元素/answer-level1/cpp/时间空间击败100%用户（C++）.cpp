### 解题思路
![image.png](https://pic.leetcode-cn.com/5d2abe157fd0a56ffe76f1c12999cce933681aae20dd6d03d393c28337b30e0e-image.png)

主指针$i$依次扫描原数组元素。因为是就地修改，所以就用一个新的指针$j$指向数组头部，根据情况移动$j$来覆盖旧元素，达到就地修改的目的。

初始两个指针$i$、$j$都在数组头部（等于0），$i$遍历整个数组。
- 如果$nums[i]$等于参数$val$：不做任何操作，$i$指针继续移动，$j$指针原地不动
- 如果$nums[i]$不等于参数$val$：元素符合要求，将在$nums[i]$的数付给$nums[j]$的数，覆盖原来的数，并且$j$指针向后移动，为下一次覆盖做准备。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
```