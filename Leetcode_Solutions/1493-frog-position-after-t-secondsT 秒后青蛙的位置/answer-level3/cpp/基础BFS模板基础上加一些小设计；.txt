### 解题思路

基础模板：pair和队列：bfs时父子结点相关的参数的计算；
         vector<vector<int> >  用来建树；
         注意说是双向，但是树结构没有环且从根节点(顶点)开始跳，所以退化成单向树(判断大小后 小-->大）
         pair<pair<int,double>,int>  {{结点编号，到达结点概率}，结点深度}
         deep:深度，max:最大深度；到达父节点A的孩子结点概率=到达A概率/(A孩子数)；
添加部分：二维数组记录结点信息，数值*-1对应叶子结点；这样就能通过数组来进行判断；
         ret[i][2];ret[i][0]:到达结点i的概率；ret[i][1]:绝对值标示所在层数，若<0则为叶子结点；
         对于只有一个结点的情况特殊处理下（没找到改进的地方）；
也是看到大佬的思路然后有了想法；还是想在基础模板上进行设计答题。
### 代码

```cpp
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1 && target==1)return 1;
        if(target>n || target==1)return 0.0;        
       vector<vector<int> > my_son(n+1);
       for(int i=0;i<edges.size();i++)
       {
           int _min=min(edges[i][0],edges[i][1]);
           int _max=max(edges[i][0],edges[i][1]);
           my_son[_min].push_back(_max);
       }
       
       queue<pair<pair<int,double>,int> >Q;
       double ret[n+1][2]={0.0};
       Q.push({{1,1.0},0});
       ret[1][0]=0;
       int max=0;
        pair<pair<int,double>,int>cur;
        while(!Q.empty())
        {
            cur=Q.front();
            Q.pop();
            int size=my_son[cur.first.first].size();
            if(size==0){ret[cur.first.first][1]*=-1;}
            if(size>0){
              for(auto it:my_son[cur.first.first])
                 {
                   int deep=cur.second;
                   max=max>deep?max:deep+1;
                   ret[it][1]=deep+1;
                   ret[it][0]=cur.first.second/size;
                   Q.push({{it,cur.first.second/size},deep+1});
                 }
            }
        } 
         int deepth=ret[target][1];
        if(deepth<0 &&t<-deepth)return 0;
        if(deepth>0 && t!=deepth)return 0;
        return ret[target][0];
    }
};
```