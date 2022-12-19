```
class Solution {
public:
    const int WHITE=0;
    const int BLACK=1;
    const int GRAY=2;
    int* color;
    bool canFinish(int num, vector<vector<int>>& edges) {
        color= new int[num+10];//color数组记录每一个节点的颜色
        fill(color,color+num+10,WHITE);//刚开始全部为白色
        vector<vector< int > > edge(num,vector< int >());//edge邻接表记录边的信息
        for(auto& v:edges){
            edge[v[0]].push_back(v[1]);
        }
        for(int i=0;i<num;++i){
            if(dfs(edge,i)){// 对每个节点进行dfs（dfs返回是否有环路）
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector< int > >& edge,int i){
        if(color[i]==BLACK)return false;//黑色代表已经访问过
        if(color[i]==GRAY)return true;//如果访问到到正在访问的
        color[i]=GRAY; //白色节点代表从未访问过 置为灰色代表正在访问，倒数第二行置为黑色代表此节点已经访问结束
        vector<int>& link=edge[i];//link存的是i节点的直接后继
        for(int next:link){
            if(dfs(edge,next)){//递归访问
                return true;
            }
        }
        color[i]=BLACK;  //在这里置为黑色，代表完全访问过
        return false;
    }
     //eg: [0,1],[1,0]这种情况的执行过程 首先访问到0节点并置为灰色，然后访问1节点同样置为灰色，因从1节点有条边
     // 可以访问到0节点 这时候0节点还是灰色 说明存在环路。
     //
};
```
