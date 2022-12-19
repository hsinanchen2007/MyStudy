### 解题思路
rooms就是邻接表
队列实现bfs
vis数组记录是否访问过


### 代码

```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(),sum = 1;
        queue<int> que;
        vector<int> vis(n,0);
        for(int i:rooms[0])
        que.push(i);
        vis[0] = 1;
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                int q = que.front();
                 que.pop();
                if(vis[q])
                continue;
                vis[q] = 1;
                sum++;   
                for(int j:rooms[q]){
                    if(!vis[j])
                        que.push(j);
                }
            
            }
        }
        
    return sum==n;
    }
};
```