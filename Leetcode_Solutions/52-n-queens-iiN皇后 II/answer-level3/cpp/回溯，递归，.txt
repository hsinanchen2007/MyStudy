用一维数组存放皇后位置，x[i]表示存放到第几列，i表示第i行的皇后
皇后必须摆放在：不同行,不同列，不同对角线上

```
class Solution {
public:
    int n;
    int sum=0;
    vector<int> (x);
    
    int plant(int k)       //判断是否能摆放
    {
        for(int j=1;j<k;j++)
        {
            if(x[j]==x[k] || abs(x[j]-x[k])==abs(j-k))  //如果在同一列或同一对角线上
                return 0;
        }
        return 1;
    }
        
    void BackTrace(int u,int n)
    {
        if(u>n)
        {
            sum++;
        }
        for(int i=1;i<=n;i++)
        {
            x[u]=i;
            if(plant(u)) BackTrace(u+1,n);  //可以放在当前位置处，则继续搜索
        }
    }
    
    int totalNQueens(int _n) {
        n=_n;
        if(n==1) {    //当只有一个格子，只有一种方法
            return 1;
        }
        x=vector<int> (n*2);   //
        BackTrace(1,n);
        
        return sum;
    }
};
```
