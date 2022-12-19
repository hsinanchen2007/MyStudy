### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/8960911b230a0c03431f1f772baebaed52b81e38ed1acaa6539dd72cd0f02469-image.png)

### 代码

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return !(find(nums.begin(),nums.end(),target)==nums.end());
    }
};
```