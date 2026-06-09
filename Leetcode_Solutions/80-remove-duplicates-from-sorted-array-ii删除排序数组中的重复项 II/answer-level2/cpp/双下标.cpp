### 解题思路
双下标
![e615a42b80ed429c7346cf96de00070.jpg](https://pic.leetcode-cn.com/1a08d4e8c48b25f5a3bd60b22b573d260a87fb66c8b6756f47b1ff74bf20022c-e615a42b80ed429c7346cf96de00070.jpg)

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() < 3)
        {
            return nums.size();
        }
        int k = 1;  //[0,k]有效
        int i = 2; 
        while (i < nums.size())
        {
            if (nums[k] == nums[k - 1] && nums[k] == nums[i])
            {
                i++;
            }
            else
            {
                ++k;
                nums[k] = nums[i];
                i++;
            }
        }
        return k + 1;
    }
};
```