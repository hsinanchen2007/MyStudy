1. 建树的时候只能从上往下建树，为什么不能从下往上建树？
2. 设定变量people，people含有四个变量```parent, coins,subCoins,child```,```parent```代表此人的上级管理者，```coins```代表本人所需要由本人及下属管理员工所持有的coin总数,subcoins代表需要给每个下属节点分发的coins数量。
```c++ []
const int mod = 1e9+7;

struct people{
    long long parent;
    long long coins;
    long long subCoins;
    long long child;
    people(){
        this->parent = 0;
        this->coins = 0;
        this->subCoins = 0;
        this->child = 1;
    }
};

class Solution {
public:
    int buildTree(int idx,vector<people> & graph,vector<vector<int>> & node){
        for(int i = 0;i < node[idx].size(); ++i){
            graph[idx].child += buildTree(node[idx][i],graph,node);
        }
        return graph[idx].child;
    }
    
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        vector<people> graph(n+1,people());
        vector<vector<int>> node(n+1);
        vector<int> ans;
        
        for(auto r : leadership){
            node[r[0]].push_back(r[1]);
            graph[r[1]].parent = r[0];
        }
        buildTree(1,graph,node);       
        
        for(auto op : operations){
            if(op[0] == 1){
                int f = op[1];
                long long add = op[2];
                while(f){
                    graph[f].coins = (graph[f].coins + op[2])%mod;
                    f = graph[f].parent;
                }
            }else if(op[0] == 2){
                graph[op[1]].subCoins = (graph[op[1]].subCoins + op[2])%mod;
                int f = op[1];
                long long add = graph[op[1]].child*op[2]%mod;
                while(f){
                    graph[f].coins = (graph[f].coins + add)%mod;
                    f = graph[f].parent;
                }
            }else if(op[0] == 3){
                long long count = graph[op[1]].coins;
                int f = graph[op[1]].parent;
                while(f){
                    count = (count + graph[op[1]].child*graph[f].subCoins)%mod;
                    f = graph[f].parent;
                }
                ans.push_back(count%mod);
            }
        }
        
        return ans;
    }
};
```
```python []
class TreeNode:
    def __init__(self):
        self.child = 1
        self.parent = 0
        self.coins = 0
        self.subCoins = 0
        
class Solution:
    def bonus(self, n: int, leadership: List[List[int]], operations: List[List[int]]) -> List[int]:
        graph = [TreeNode() for _ in range(n+1)]
        node = [[] for _ in range(n+1)]
        mod = 1000000007
        
        for i in range(len(leadership)):
            graph[leadership[i][1]].parent = leadership[i][0]
            node[leadership[i][0]].append(leadership[i][1])
        
        def buildTree(idx):
            for i in range(len(node[idx])):
                graph[idx].child += buildTree(node[idx][i])
            return graph[idx].child
        
        buildTree(1)
        
        ans = []
        for i in range(len(operations)):
            if operations[i][0] == 1:
                graph[operations[i][1]].coins += operations[i][2]
                f = graph[operations[i][1]].parent
                while f != 0:
                    graph[f].coins += operations[i][2]
                    f = graph[f].parent
                    
            elif operations[i][0] == 2:
                graph[operations[i][1]].subCoins += operations[i][2]
                add = graph[operations[i][1]].child*operations[i][2]
                f = operations[i][1]
                while f != 0:
                    graph[f].coins += add
                    f = graph[f].parent
                    
            elif operations[i][0] == 3:
                res = graph[operations[i][1]].coins
                f = graph[operations[i][1]].parent
                while f != 0:
                    res += (graph[f].subCoins*graph[operations[i][1]].child)%mod
                    f = graph[f].parent
                ans.append(res%mod)
                
        return ans  
```