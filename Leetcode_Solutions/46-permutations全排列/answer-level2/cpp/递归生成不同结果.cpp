### 解题思路
递归解决问题：
每次递归更新可选项（删掉用过的选项）

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>temp;
        for(int i = 0 ; i < nums.size() ; i++){
            generate(res,nums,nums[i],temp,nums.size());
        }
        return res;
    }
    void generate(vector<vector<int>> &res,vector<int> option,int add,vector<int>temp,int len){
        temp.push_back(add);
        if (temp.size() == len) {
            res.push_back(temp);
            return;
        }
        option.erase(find(option.begin(), option.end(), add));
        for(int i = 0 ; i < option.size() ; i++){
            generate(res,option,option[i],temp,len);
        } 
    }
};
```