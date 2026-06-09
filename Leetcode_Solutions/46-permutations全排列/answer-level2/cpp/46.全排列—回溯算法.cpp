```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        backtrack(res,vec,nums,0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int> vec, vector<int> nums, int level){
        if(level==nums.size()){
            res.emplace_back(vec);
            return;
        } 
        for(int i=0;i<nums.size();i++){
            int j=0;
            for(;j<vec.size();j++)
                if(nums[i]==vec[j]) break; //找vec是否存在num[i]   
            if(j!=vec.size()) continue; //如果vec中有num[i]则不压入
            vec.emplace_back(nums[i]);
            backtrack(res,vec,nums,level+1);
            vec.pop_back();
        }
    }
};
```
一个布尔数组visited，初始化的时候都为false表示这些数还没有被选择，当我们选定一个数的时候，就将这个数组的相应位置设置为true。
```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        vector<bool> visited(nums.size(),false);
        helper(res,vec,nums,0,visited);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int> vec, vector<int> nums, int level,vector<bool>& visited){
        if(level==nums.size()){
            res.emplace_back(vec);
            return;
        } 
        for(int i=0;i<nums.size();i++){   
            if(visited[i]) continue;
            visited[i]=true;
            vec.emplace_back(nums[i]);
            helper(res,vec,nums,level+1,visited);
            vec.pop_back();
            visited[i]=false;
        }
    }
};
```


