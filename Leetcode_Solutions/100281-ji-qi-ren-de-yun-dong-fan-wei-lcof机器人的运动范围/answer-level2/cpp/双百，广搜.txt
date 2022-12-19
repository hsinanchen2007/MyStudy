### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution
{
public:
    int total=0;
    int movingCount(int m, int n, int k)
    {
        int a[100][100] = {0};
        bfs(a,0,0,m,n,k);
        return total;
    }
    void bfs(int a[100][100],int x,int y,int m,int n,int k)
    {
        if(x<0 || y<0 || x>=m || y>=n || a[x][y] == 1)
            return;
            a[x][y] = 1;

            if((x%10 + x/10 + y%10+y/10)<=k)
            {
                total++;
                //cout<<x<<' '<<y<<' '<<num1+num2<<endl;
            }
            else return;

        bfs(a,x,y+1,m,n,k);
        bfs(a,x,y-1,m,n,k);
        bfs(a,x+1,y,m,n,k);
        bfs(a,x-1,y,m,n,k);
    }
};
```