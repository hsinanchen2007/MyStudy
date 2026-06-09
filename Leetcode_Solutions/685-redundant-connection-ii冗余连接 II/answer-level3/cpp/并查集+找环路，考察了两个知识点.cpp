题目比较综合，考察点有两个（拼爹，找环路）：
    1）使用并查集，检查一个node是否有两个父亲（father1，father2）。
    2）判断一个节点是否在循环中。
答案是这两种情况之一，或者都存在。

按照这个思路，先建立parents数组，同时检查是否有father1，father2；
    建立的过程中，直接判断一个节点是否有两个父亲，获取errorSon，father1，father2。
    建立parents数组时有一个细节，按先后顺讯，建立的是{father1，errorSon}，father2只是记录，没有建立。
    这个细节在后面解题时会用到

写InLoop（）函数，判断一个node是否在循环中。

如果存在第二个爹：
    判断{father1， errorSon}是否在循环中
    如果存在，在循环中，返回：{father1， errorSon}
    如果不在循环中，返回：{father2， errorSon}。这样做，是因为father2要么在循环中，要么是靠后的edge。

如果不存在father2：
    遍历全部节点，找到一个在循环总的node。
    从头到尾遍历edge，用后发现的edge，覆盖前面的edge。

```
class Solution {
public:
    int InLoop(vector<vector<int>>& edges, int N, int node, vector<int> &parents)   // 返回在循环中的一个node， 如果不是循环，返回-1
    {   
        vector<bool>vistied(N+1, 0);        
        while(parents[node] != -1 && vistied[node] == 0) {  //不是根节点， 没有出现循环
            vistied[node] = true;
            node = parents[node];
        }
        if(vistied[node] == 1) return node;       // 重复出现，node在循环中 
        return -1;                                // 找到root， 不是循环
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) 
    {
        int N = edges.size();
        vector<int>parents(N+1, -1);
        int errorSon = -1;
        int father1 = -1, father2 = -1;
        for(auto edge : edges) {                   // 按并查集方案，建立父子节点映射关系
            if(parents[edge[1]] == -1) {
                parents[edge[1]] = edge[0];                
            }
            else {                                 // 如果一个节点已经有一个父节点，记录下自己和两个父节点
                errorSon = edge[1];
                father1 = parents[edge[1]];
                father2 = edge[0];                
            }
        }
        if(father2 != -1) {                        // 如果存在两个父节点的情况，判断第一对（父子）组合是否在循环中
            int flag = InLoop(edges, N, errorSon, parents);  
            if(flag != -1) return {father1, errorSon};          // 如果在循环中， 返回第一对（父子）节点     
            return {father2, errorSon};                         // 如果第一对（父子）节点不在循环中，返回靠后的父子节点（是否循环不用再判断）
                    
        }
        int loopNode = -1;                                
        for(int i = 0; i < N; i++) {                            // 遍历全部节点，找循环节点
            loopNode = InLoop(edges, N, i, parents);
            if(loopNode != -1) {
                break;
            }
        }        
        vector<int> ans;
        if(loopNode != -1) {                            
            for(auto edge : edges) {
                if(edge[1] == loopNode) {                        // 如果发现循环节点，记录。此处要把循环执行到底，记录最后出现的边。
                    ans = edge;
                }
            }
        }
        return ans;
    }
};
```
![image.png](https://pic.leetcode-cn.com/9191140966f016830633d52479bdedd8b3ef6bb883556a82eab51d622e931f75-image.png)
