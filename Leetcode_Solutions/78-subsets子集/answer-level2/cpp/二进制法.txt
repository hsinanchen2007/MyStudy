### 解题思路
![QQ图片20200117102129.png](https://pic.leetcode-cn.com/06d88a814a8a6dcab09d9788ed3a4f7b2e6ea7cb4c39e845b2a124293811d9d3-QQ%E5%9B%BE%E7%89%8720200117102129.png)

+ 任一集合子集个数可由公式求得，恰好对应相应的二进制个数
+ 如3  为011，表示选第一个元素，第二个元素，不选第三个元素的子集

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>rs;
        int pos = pow(2,nums.size());//二进制法
        
        for(int i=0;i<pos;i++)
        {
            vector<int>temp;
            for(int dix=0;dix<nums.size();dix++)
            {
                if((i>>dix)&1)
                    temp.push_back(nums[dix]);
            }
            rs.push_back(temp);
        }
        return rs;
    }
};
```