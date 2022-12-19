### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        for(int i=0;i<=nums.size();++i){
            back_trace(res,tmp,nums,i,0);
        }
        return res;
    }
    void back_trace(vector<vector<int>> &res, vector<int> &tmp,vector<int> &nums,int no,int pos){//总数，当前数，当前位置
        if(tmp.size()==no){
            res.push_back(tmp);
            return;
        }
        for(int j=pos;j<nums.size();++j){
            tmp.push_back(nums[j]);
            back_trace(res,tmp,nums,no,j+1);
            tmp.pop_back();
        }
    }
};
```