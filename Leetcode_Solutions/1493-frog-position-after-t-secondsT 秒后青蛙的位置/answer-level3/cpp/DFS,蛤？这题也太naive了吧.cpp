### 解题思路
map 统计所有边加快遍历速度
count 计可走路径，+1s后，分支概率为 prob/count
如果还有剩余时间但是没有可以走的路径，或者时间结束，则返回当前节点是否为目标
### 代码

```cpp
class Solution {
public:
    double dfs(map<int,vector<int>> &dict, vector<bool> &visit,int cur,int t,int target){
        if(t<0)return 0;
        if(t==0)return cur==target;
        double count=0,prob=0;
        visit[cur] = true;
        for(int x:dict[cur]){
            if(!visit[x]){
                count++;
                prob = max(prob,dfs(dict,visit,x,t-1,target));
            }
        }
        visit[cur] = false;
        if(count==0)return cur==target;
        return prob / count;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1)return target==1;
        map<int,vector<int>> dict;
        for(auto &e:edges){
            dict[e[0]].push_back(e[1]);
            dict[e[1]].push_back(e[0]);
        }
        vector<bool> visit(n+1,false);
        return dfs(dict,visit,1,t,target);
    }
};
```