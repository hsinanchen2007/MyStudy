
# 分析
本题其实就三种情况。
1. 情况1是多出的边指向某个非root的结点，该结点记为end，它的入度为2，答案为指向end的两条边之一，注意这时候答案唯一，删错边可能导致图不联通，无法构成树:
```
    2 -> 1
    ^  / ^
    | v  |
    4    3
```
2. 情况2与情况1类似，存在入度为2的end结点，此时答案不唯一，删掉指向end的哪条边都能使得图变成树，按照题目要求返回最后环内最后出现的边即可:
```
5 <- 1 -> 2
     |    |
     v    v
     4 <- 3
```
3. 情况3是多出的边指向root，所有结点的入度都是1，此时答案不唯一，删除环内任意边都可以，按照题目要求返回最后环内最后出现的边即可：
```
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
```

# 结论
根据以上分析，代码可以分情况处理，虽然写出来不优雅，但是速度也不算太慢。（这里假设你已经懂了并查集，若不懂，可以先做一下这题[684.冗余链接I](https://leetcode-cn.com/problems/redundant-connection/)，把并查集学一下）
- 情况1和2可以合并处理，并查集合并所有边，对于指向end的边只合并第一条，若最后联通分量合并为1，则可以把指向end的第二条边删除，否则只能删除第一条边。
- 情况3时,这时候题目退化为[684.冗余链接I](https://leetcode-cn.com/problems/redundant-connection/)，解法相同，即用并查集不断合并结点，直到将要合并的顶点已经联通了，则当前边是多余的，可删掉。

```cpp
// test case:
// [[1,2],[1,3],[2,3]]
// [[1,2], [2,3], [3,4], [4,1], [1,5]]
// [[2,1],[3,1],[4,2],[1,4]]
class Solution {
public:
    vector<int> parents;
    int count;
    int MyFind(int a){
        while(a != parents[a]){
            parents[a] = parents[parents[a]];// 稍微压缩一下路径
            a = parents[a];
        }
        return a;
    }
    bool IsConnect(int a, int b){
        int p1 = MyFind(a);
        int p2 = MyFind(b);
        return p1 == p2;
    }
    void MyUnion(int a, int b){
        int p1 = MyFind(a);
        int p2 = MyFind(b);
        if(p1 == p2) return;
        parents[p1] = p2;
        count--;
        return;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // 统计大家出入度，并找到入度为2的终点（若有的话）
        int n = edges.size(); // n个顶点，注意顶点从1开始
        vector<int> inDegree(n); // 入度
        int end = -1;
        for(auto &e : edges){
            inDegree[e[1]-1]++; // 入度+1
            if(inDegree[e[1]-1] > 1) end = e[1];
        }

        // 并查集初始化
        count = edges.size();
        parents.resize(count);
        for(int i = 0; i<count; ++i){
            parents[i] = i;
        }
        // 若有end，则为情况1、2，答案为指向end的两条边之一
        if(-1 != end){
            bool is_first = true;
            vector<int> edge_first;
            vector<int> edge_second;
            for(auto &e : edges){
                // 对于指向end的两条边，只合并第一条，看最后是否能联通
                if(e[1] == end){
                    if(is_first){
                        is_first = false;
                        MyUnion(e[0]-1, e[1]-1);
                        edge_first = e;
                    }
                    else{
                        edge_second = e;
                    }
                }
                else{
                    MyUnion(e[0]-1, e[1]-1);
                }
            }

            // 有可能删掉任意边都行，这时优先返回靠后的边，即second
            if(1 == count) return edge_second;
            else return edge_first;
        }
        // 若无end，则删除环路中任意一条边都行，按照题意，删除环路中最后出现的那条边
        else{
            for(auto &e : edges){
                // 若将添加的边已经有连接了，则该边可删除
                if(IsConnect(e[0]-1, e[1]-1)){
                    return e;
                }
                MyUnion(e[0]-1, e[1]-1);
            }
        }
        // 不会运行到这里
        return vector<int>();
    }
};
```
![image.png](https://pic.leetcode-cn.com/33e270fe93b2de7acd5ebab75f874aaf40b19b9af132cf584e925ef9d2c067ca-image.png)
