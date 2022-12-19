由高中知识，我们知道一个含n个的集合，其子集有2的n次方种，因为对于每个元素，有选和不选两种方法。

我们可以用位运算来实现，比如一个集合为{2,3,1},我们可以用一个二进制数来表示选取的方案，比如二进制数010，就表示选取了3不选取2和1。

这样下来，这个二进制数应该是在000和111之间，转换成十进制就是0到2的n次方-1之间。

对于每个二进制数，可以通过&1的操作来解析

由于会出现重复的数字，所以在最后的结果上进行排序，然后用哈希表去重即可。

代码如下：
```c++ []
class Solution {
public:
    map<vector<int>,bool> vis;
    
    void cal(int state,vector<int>& nums,vector<vector<int>>& ans){
        vector<int> tmp; tmp.clear();
        for(int i = nums.size()-1; i >= 0; i--){
            if(state & 1) tmp.push_back(nums[i]);
            state >>= 1;
        }
        reverse(tmp.begin(),tmp.end());
        ans.push_back(tmp);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans; ans.clear();
        vector<vector<int>> res; res.clear();
        int n = pow(2,nums.size())-1;
        for(int i = 0; i <= n; i++)
            cal(i,nums,ans);
        for(int i = 0; i < ans.size(); i++)
            sort(ans[i].begin(),ans[i].end());
        for(int i = 0; i < ans.size(); i++)
            if(!vis[ans[i]]){
                vis[ans[i]] = true;
                res.push_back(ans[i]);
            }
        return res;
    }
};
```
