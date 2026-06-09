**map建树，两次dfs搜索即可**
比赛的时侯考虑掉了一个情况，本来想最后时刻绝杀的最后wa 8。。。。。。
```
#define pii pair<int,int>
#define map unordered_map
class Solution {
public:
        map<int,vector<int>> mp;
    int dfs(int x,vector<int>& value,int nodes){
        int sum=value[x];
        for(int i=0;i<mp[x].size();i++){
            sum+=dfs(mp[x][i],value,nodes);
        }
        if(!sum){
            value[x]=INT_MIN;
        }
        return sum;
    }//存在一种情况：子树的结点和不为0,但是父节点的和为0，此时有一部分其余结点并没有删除
    int df(int x,vector<int>& value){
        if(value[x]==INT_MIN)return 0;
        int re=1;
        for(int i=0;i<mp[x].size();i++){
            re+=df(mp[x][i],value);
        }
        return re;
    }
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
       int n=nodes,ans=0;
        for(int i=1;i<parent.size();i++){
            mp[parent[i]].push_back(i);
        }//图简便直接用红黑树加速
        dfs(0,value,nodes);//标记
        return df(0,value);//统计结点
    }
};
```
