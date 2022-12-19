### 解题思路
![2.png](https://pic.leetcode-cn.com/3ec5ac7cfb1d4705c4195121b17bf29f0714183e8d38b19fb1fca65bea13ad94-2.png)

### 代码
```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>res;
        for(int i = 0; i < nums.size(); ++i){
            int cnt = nums[i];
            int num = nums[i + 1];
            for(int j = 0; j < cnt; j++)
                res.push_back(num);
            ++i;
        }
        return res;
    }
};
```