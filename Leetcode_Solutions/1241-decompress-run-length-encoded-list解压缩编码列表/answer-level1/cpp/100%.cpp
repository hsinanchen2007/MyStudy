### 解题思路
此处撰写解题思路
![WX20200320-215054@2x.png](https://pic.leetcode-cn.com/824d3fe8facc3573da4a059f6a4a71f90e4544fc8e3a47fd61b55298671b13cf-WX20200320-215054@2x.png)

### 代码

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i+=2){
            ans.insert(ans.end(),nums[i],nums[i+1]);
        }
        return ans;
    }
};
```