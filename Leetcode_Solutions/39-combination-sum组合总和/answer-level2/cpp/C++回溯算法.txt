### 解题思路
C++,简单的回溯法，12ms，击败95.69%，9.6MB，击败88.23%。
首先对candidates数组排序（看例子我以为默认排好序的，结果自信一提交就报错了。。。）
然后删去候选数组中大于target的值（这些值绝对用不到）
然后就是for循环回溯算法了。
这是我第一个纯粹靠自己编出来的回溯算法题，可算会用了。


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    int t=0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int u=0;
        for(;u<candidates.size();u++){
            if(candidates[u]>target)
            break;
        }
        candidates.erase(candidates.begin()+u,candidates.end());
        for(int i=0;i<candidates.size();i++){
            t=0;
            tmp.clear();
            dfs(i,candidates,target);
        }
        return res;
    }
    void dfs(int i,vector<int>& candidates,int target){
        t+=candidates[i];
        tmp.push_back(candidates[i]);
        if(t==target)
        {res.push_back(tmp);
        return;}
        if(t+candidates[i]>target)
        return;
        for(int j=i;j<candidates.size();j++){
            dfs(j,candidates,target);
            tmp.pop_back();
            t-=candidates[j];
        }
    }
};
```