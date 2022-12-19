深度优先搜索+剪枝
首先比较重要的是用什么数据结构保存中间变量，这里我们选用unordered_map<int,vector<pair<int,int> > >保存当前节点的可达节点和可达节点的路径
第二个是如何求取全局最小值，这里我们选用剪枝操作，对大于当前最小值的路径剪枝，最后求得的结果就是全局最小值。
实现如下：
```
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int,vector<pair<int,int> > > m;
        for(auto flight:flights){
            m[flight[0]].push_back(make_pair(flight[1],flight[2]));
        }
        int res=INT_MAX;
        helper(m,src,dst,K,0,res);
        return res==INT_MAX?-1:res;
    }
    void helper(unordered_map<int,vector<pair<int,int> > >& m,int src,int dst,int k,int tmp,int& res){
        if(src==dst){
            res=tmp;
            return;
        }
        if(k<0) return;
        for(auto t:m[src]){
            if(tmp+t.second>=res) continue;
            helper(m,t.first,dst,k-1,tmp+t.second,res);
        }
    }
};
```