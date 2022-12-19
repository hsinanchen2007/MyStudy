### 解题思路
首先确定是否有解，可知连通含有n个结点的网络，至少需要n-1条线路，如果线路小于n-1，则直接return -1；
然后，采用并查集来求解，该网络中含有多少个连通分量，算出来之后再减1，便得到结果。

### 代码

```cpp
class Solution {
public:
    int Tree[100000];
    int findRoot(int x){             // 求解连通分量代码1
        if(Tree[x] == -1) return x;
        else{
            int tmp = findRoot(Tree[x]);
            Tree[x] = tmp;
            return tmp;
        }
    }


    int makeConnected(int n, vector<vector<int>>& connections) {
        for(int i=0; i<n; i++) Tree[i] = -1;
        int len = connections.size();
        if(len < (n-1)) return -1;
        for(int i=0; i<len; i++){
            int a = this->findRoot(connections[i][0]);
            int b = this->findRoot(connections[i][1]);
            if(a != b) Tree[a] = b;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(Tree[i] == -1) ans++;
        }
        return ans-1;
    }
};
```