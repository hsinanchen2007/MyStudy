![image.png](https://pic.leetcode-cn.com/df325c51fb1a17808ff603e8ddd7ecb5b6dc5655b57e0d3c6edd56432752a899-image.png)

### 解题思路
思路明确一点，就是说逐层打印，每行每列进行，采用嵌套递归，话不多说，上代码。

### 代码
```cpp
class Solution {
public:
    void spril(int x,int y,int num,int n,vector<vector<int>> &ans)
    {
        if(n==0)return ;
        if(n==1){
            ans[x][y]=num;
            return;
        }
        for(int i=x;i<n+x-1;i++)  ans[y][i]=num++;
        for(int i=y;i<n+y-1;i++) ans[i][n+y-1]=num++;
        for(int i=x+n-1;i>x;i--) ans[n+y-1][i]=num++;
        for(int i=n+y-1;i>y;i--) ans[i][x]=num++;

        spril(x+1,y+1,num,n-2,ans);
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n);
        for (int i = 0; i < ans.size(); i++)
            ans[i].resize(n);
        spril(0,0,1,n,ans);
        return ans;
    }
};
```