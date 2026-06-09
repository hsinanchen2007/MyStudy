### 解题思路
矩阵快速幂

### 代码

```cpp
class Solution {
private:
    struct matrix{
        long long mat[3][3];
    };
    matrix zero;
public:
    Solution()
    {
        zero.mat[0][0] = 1 , zero.mat[0][1] = 1 , zero.mat[0][2] = 1;
        zero.mat[1][0] = 1 , zero.mat[1][1] = 0 , zero.mat[1][2] = 0;
        zero.mat[2][0] = 0 , zero.mat[2][1] = 1 , zero.mat[2][2] = 0;
    }
    matrix mulit_fac(matrix a,matrix b)
    {
        matrix ans;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                ans.mat[i][j] = a.mat[i][0]*b.mat[0][j] + a.mat[i][1]*b.mat[1][j] + a.mat[i][2]*b.mat[2][j];
            }
        }
        return ans;
    }
    //矩阵快速幂
    matrix quick(int b)
    {
        matrix ans;
        ans.mat[0][0] = 1 , ans.mat[0][1] = 0 , ans.mat[0][2] = 0;
        ans.mat[1][0] = 0 , ans.mat[1][1] = 1 , ans.mat[1][2] = 0;
        ans.mat[2][0] = 0 , ans.mat[2][1] = 0 , ans.mat[2][2] = 1;
        while(b)
        {
            if(b&1) ans = mulit_fac(ans,zero);
            zero = mulit_fac(zero,zero);
            b>>=1;
        }
        return ans;
    }
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        matrix Mat = quick(n-2);
        return Mat.mat[0][0] + Mat.mat[0][1];
    }
};
```