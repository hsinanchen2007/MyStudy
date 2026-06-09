### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numSquares(int n) {
    //贪心BFS
    queue<pair<int,int>> q;
    q.push(make_pair(n,0));
    //n为当前剩余数，0为需要的步数
    vector<bool> visit(n+1,false);
    //记录下可以减少重复计算
    visit[n]=true;
    while(!q.empty())
    {
        int num=q.front().first;
        int step=q.front().second;
        q.pop();
        for(int i=1;num-i*i>=0;i++)
        {
            int a=num-i*i;
            if(a<0) break;
            if(a==0) return step+1;
            if(!visit[a])
            {
                q.push(make_pair(a,step+1));
                visit[a]=true;
            }
        }
    }
    return 0;
    }
};
```