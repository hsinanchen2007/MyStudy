### 解题思路
1.按照从左到右，从上到下，从右到左，从下到上的顺序给矩阵赋值。
2.以遍历一个外圈（四边形）为周期，设置判断条件中s的值。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> num(n,0);
        vector<vector<int>> matrix(n,num);
        int t=n-1;
        int s=0;
        int a=0,b=0;
        matrix[a][b]=1;
        for(int i=2;i<=n*n;i++)
        {
            if(a==s&&b<t-s)
            b++;
            else if(a<t-s&&b==t-s)
            a++;
            else if(a==t-s&&b>s)
            b--;
            else if(b==s&&a>s)
            a--;
            if(a==s+1&&b==s)
            s++;
            matrix[a][b]=i;
        }
        return matrix;
    }
};
```