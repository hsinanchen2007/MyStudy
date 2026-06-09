### 解题思路
记忆化搜索

### 代码

```cpp
class Solution {
private:
    int findNum(int n, vector<int> &memo)
    {
        if(n==0)
            return 0;
        if(memo[n]!=-1)
            return memo[n];
        int res = INT_MAX;
        for(int i = 1;n-i*i>=0;i++)
        {
            int j = n-i*i;
            res = min(res, findNum(j, memo)+1);
        }
        memo[n]=res;
        return memo[n];
    }
public:
    //Memory search    
    int numSquares(int n) {
        if(n==0)
            return 0;
        vector<int> memo(n+1, -1);
        return findNum(n,memo);

    }
};
```
### 解题思路
DP

### 代码

```cpp
class Solution {

public:
    //DP    
    int numSquares(int n) {
        if(n==0)
            return 0;
        vector<int> memo(n+1, INT_MAX);
        memo[0]=0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; i-j*j>=0; j++)
            {
                memo[i] = min(memo[i],1+memo[i-j*j]);
            }
        }
        return memo[n];

    }
};
```


### 解题思路
BFS

### 代码

```cpp
class Solution {
public:
        
    int numSquares(int n) {
        if(n==0)
            return 0;
        queue<int> q;
        vector<int> dist(n+1, INT_MAX);
        vector<bool> vis(n+1, false);
        vis[n]=true;
        dist[n]=0;
        q.push(n);
        while(q.size())
        {
            int t = q.front();
            q.pop();

            for(int i=1;t-i*i>=0;i++)
            {
                int j = t-i*i;
                if(!vis[j])
                {
                    if(j==0)
                        return dist[t]+1;
                    q.push(j);
                    dist[j]=dist[t]+1;
                    vis[j]=true;
                }
            }
        }
        return 0;
    }
};
```