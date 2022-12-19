### 解题思路
1.思路1:BFS
2.思路2：DFS
3.思路3:并查集

### 代码

```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if(n == 0) return 0;
        int res=0;
        vector<bool> visited(n, false); //学生是否被归入某一朋友圈

        for(int i = 0; i < n; i++)
        {
            if(visited[i] == true) 
                continue;
            find(M,i,visited);
            res++;
        }
        return res;
    }

    //查找和第i个学生为同一朋友圈的学生 
    void find(vector<vector<int>>& M,int i, vector<bool>& visited)
    {
        visited[i] = true;

        for(int j = 0; j< M.size(); j++)
        {
            if(M[i][j] ==0 || visited[j] == true) 
                continue; //这句话是关键
            find(M,j,visited);
        }
    }
};
```