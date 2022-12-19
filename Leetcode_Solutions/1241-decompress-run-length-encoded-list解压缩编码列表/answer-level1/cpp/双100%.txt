![image.png](https://pic.leetcode-cn.com/7b9d1fbebcdc8d0a4216688027776f48d4cf6a6958abd2d25d35e64193ca7367-image.png)

```
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i+=2)
        {
            int cnt = nums[i];
            while(cnt--) res.push_back(nums[i+1]);
        }
        return res;
    }
};
```