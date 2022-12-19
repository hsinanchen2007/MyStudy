### 解题思路
此处撰写解题思路
五毒神掌法

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // 保存非0的值
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // nums[j] = nums[i];
                // if (j != i) {
                //     nums[i] = 0;
                // }
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j++;
            }
        }
    }
};
```

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // 保存非0的值
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                if (j != i) {
                    nums[i] = 0;
                }
                // int temp = nums[j];
                // nums[j] = nums[i];
                // nums[i] = temp;
                j++;
            }
        }
    }
};
```