### 解题思路
快慢指针：
1，慢指针指向将要填充的位置
2，快指针向后逐个遍历

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = 1;
        int c = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                ++c;
            } else {
                c = 1;
            }
            if (c <= 2) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
```

![image.png](https://pic.leetcode-cn.com/97a02ccf18873834d2f809c4de49826b70103c4cb48d9cadd0a426f80dd443d6-image.png)
