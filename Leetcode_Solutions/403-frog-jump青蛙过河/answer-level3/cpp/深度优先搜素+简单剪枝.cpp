对于答案是能否到达的题目一般用dfs即可，因为搜索到结果便停止搜索。

开始写了带记忆化搜索的方法，即记录在坐标为x步长为step的状态无法到达终点，但是效果不明显，反倒是加入剪枝更有效：如果终点是一个特别大的坐标，无论如何都无法到达，如果不加剪枝可能会搜索完所有的状态；因此在最开始加入判断：如果以最长步长一直跳仍然无法超过终点坐标就返回false。n个单元格最大可能的坐标为$n * (n - 1) / 2$。

```c++
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(*stones.rbegin() > (n - 1) * n / 2)
            return false;
        unordered_set<int> st(stones.begin(), stones.end());
        return dfs(st, 0, 0, *stones.rbegin());
    }
    bool dfs(unordered_set<int>& st, int pos, int step, int target){
        if(pos == target)
            return true;
        for(int s = step + 1; s > step - 2; s--){
            if(s + pos <= pos)
                continue;
            if(st.count(s + pos) && dfs(st, pos + s, s, target))
                return true;
        }
        return false;
    }
};
```