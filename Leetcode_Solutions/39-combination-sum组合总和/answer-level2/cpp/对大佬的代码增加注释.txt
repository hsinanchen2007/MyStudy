### 解题思路
参考高赞题解的代码。
增加了注释
是个子集树转换成排列树来做的问题，但是为了去重，又需要排序，变成了个排序树问题。但是这个不是一般的用i来判断边界，而是用target来判断。当我的目标为零的时候，说明我所有的target都满足了，就可以push_back当前的path了。

### 代码

```cpp
class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());// 排序+记录当前遍历到的元素i，可防止重复
        this->candidates = candidates;// 使得本函数的参数对其他函数均可见。
        dfs(0,target);// 现在我搜索到了第0个元素，我的目标是target。
        return res;
    }
    void dfs(int start, int target){
        if(target == 0){
            res.push_back(path);
            return ;
        }
        for(int i=start; i<candidates.size() && target-candidates[i]>=0; i++){
            path.push_back(candidates[i]);
            dfs(i,target-candidates[i]);//现在我搜索到了第i个元素，目标是target-canditates[i]
            // 显然在下一步中我最多还是选canditates[i],而不会选canditates[i-1]了。因此选出的元组内部元素永远是从小打到排序的，因而不会重复。可以将sort函数去掉，看看会发生什么。
            path.pop_back();
        }
    }
};
```