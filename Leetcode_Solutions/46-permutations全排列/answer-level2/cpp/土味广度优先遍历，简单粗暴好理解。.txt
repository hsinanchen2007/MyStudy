### 解题思路
看不懂算我输。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> begin;
        next(begin,nums);
        return res;
    }
    void next(vector<int>& nums,vector<int>& left){
        int n = nums.size();
        int m = left.size();
        if(m==1){
            nums.push_back(left[0]);
            res.push_back(nums);
            return;
        } 

        for(int i = 0;i<m-1;i++){
            vector<int> nv(nums);
            vector<int> nl(left);    
            nv.push_back(nl[i]);
            nl.erase(nl.begin()+i);
            next(nv,nl);   
        }
        nums.push_back(left[m-1]);
        left.pop_back();
        next(nums,left);
        
    }
};
```