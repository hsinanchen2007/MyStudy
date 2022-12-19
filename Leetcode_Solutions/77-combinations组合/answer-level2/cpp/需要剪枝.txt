### 解题思路
开始写的回溯发现运行超时，参考了题解进行剪枝执行效率好了很多。主要节省的是一个备忘录，如果按照顺序添加元素，则不需要格外添加一个备忘录。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> demo;
        if(n==k){
            for(int i=1;i<=n;i++){
                temp.push_back(i);
            }
            res.push_back(temp);
            return res;
        }
        helper(res, temp, 0, k, n);
        return res;
    }
    void helper(vector<vector<int>>& res,vector<int>& temp,int first,int k,int n){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=first;i<n;i++){
            temp.push_back(i+1);
            helper(res,temp,i+1,k,n);
            temp.pop_back();
        }
    }
};
```