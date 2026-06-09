
```
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for(int i = 0; i < index.size(); ++i){
            res.insert(res.begin()+index[i], nums[i]);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/f04d0171d1b964dd6a5a02247d5c60eaa67ea2d06616491067fa29fbd2247371-image.png)
