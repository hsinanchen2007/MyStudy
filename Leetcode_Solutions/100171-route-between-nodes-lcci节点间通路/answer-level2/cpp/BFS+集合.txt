### 解题思路
![Snipaste_2020-03-16_12-02-32.png](https://pic.leetcode-cn.com/3b85122e0c9e3a47f9119ee88637a0acd58ca5e8781cf55443f1d2195752b202-Snipaste_2020-03-16_12-02-32.png)

首先，建立一个辅助数组start_index，记录每个结点对应边的下标是从哪里开始的。比如：当n=4, graph=[[0, 1], [0, 2], [1, 2], [1, 3]]时,
则start_index[0]=0，start_index[1]=2，start_index[2]=-1,start_index[3]=-1。

下一步，使用一个队列来进行BFS，使用集合set来记录已经加入过队列的结点，避免死循环。

最后，将start结点加入队列进行BFS，直到发现目标结点或队列为空返回false。


### 代码

```cpp
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        if(start==target) return true;
        int start_index[n+1], temp, next_index;
        for(int i=0; i<n+1; ++i) start_index[i]=-1;
        start_index[graph[0][0]]=0;
        for(int i=1; i<graph.size(); ++i)
            if(graph[i][0] != graph[i-1][0]) start_index[graph[i][0]]=i;
        start_index[n]=graph.size();
        unordered_set<int> myS;  //是否已经加入过队列
        queue<int> myQ;
        myQ.push(start);
        myS.insert(start);
        while(!myQ.empty()) {
            temp=myQ.front();
            myQ.pop();
            if(start_index[temp]==-1) continue;
            next_index=temp+1;
            while(start_index[next_index]==-1) ++next_index;
            for(int i=start_index[temp]; i<start_index[next_index]; ++i) {
                if(graph[i][1]==target) return true;
                else if(myS.find(graph[i][1])==myS.end()) {
                    myQ.push(graph[i][1]);
                    myS.insert(graph[i][1]);
                }
            }
        }
        return false;
    }
};
```