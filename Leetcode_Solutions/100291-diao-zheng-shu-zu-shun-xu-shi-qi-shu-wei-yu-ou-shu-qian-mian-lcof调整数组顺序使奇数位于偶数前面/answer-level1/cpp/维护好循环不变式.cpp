### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

    // 时间复杂度: (time complexity)  O(n)
    // 空间复杂度: (space complexity) O(1)
    vector<int> exchange(vector<int>& nums) {

        // 写对正确的循环需要维护好循环不变式(loop invariant)
        // 变量k的含义为在数组[0...k)的半开半闭区间中存放的都是奇数
        // 翻译过来就是奇数位于数组的前半部分。
        int k = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (nums[i] % 2)
                swap(nums[i], nums[k++]);
        }

        return nums;
    }
};
```