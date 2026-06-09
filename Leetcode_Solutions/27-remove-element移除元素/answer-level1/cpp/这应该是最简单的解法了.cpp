### 解题思路
这题和第26题很相似
应该是最简单的解法了
萌新第一次击败100%用户
![捕获.JPG](https://pic.leetcode-cn.com/999426e0be2123f901692b0cf1d0d282438c01edb571c633920f2bd473b664ab-%E6%8D%95%E8%8E%B7.JPG)


### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[len] = nums[i];
                len++;
            }
        }
        return len;
    }
};
```