直接使用vector的insert函数，非常简单。
```
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for(int i = 0; i<index.size(); i++){
            res.insert(res.begin()+index[i],nums[i]);
        }
        return res;
    }
};
```