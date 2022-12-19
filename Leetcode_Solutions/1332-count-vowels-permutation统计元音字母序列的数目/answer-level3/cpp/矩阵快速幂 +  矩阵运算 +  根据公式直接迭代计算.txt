求出来对应的次序然后直接计算就行
根据题意可画出对应的转移图, 然后根据对应关系进行转移即可
![image.png](https://pic.leetcode-cn.com/ceac9043066c14c19a974cf7785d67345a8540fab8d15472d996cefbc94acf9f-image.png)
```C++ []
    int countVowelPermutation(int n) {
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        long long res = 0, mod = 1e9+7;
        for(int j=1; j<n; j++) {
            long long a1, e1, i1, o1, u1;
            a1 = (e + i + u) % mod;
            e1 = (a + i) % mod;
            i1 = (e + o) % mod;
            o1 = i;
            u1 = (i + o) % mod;
            a = a1, e = e1, i = i1, o = o1, u = u1;
        }
        res = (a + e + i + o + u) % mod;
        return res;
    }
```

这个题数据量再大一些就应该采用 矩阵来做运算，并可以通过矩阵快速幂来加速运算
下面是通过矩阵进行运算的算法

```C++ []
    int countVowelPermutation(int n) {
        // 矩阵的公式
        int mode = 1e9 + 7;
        vector<vector<int>> grid{{0,1,0,0,0}, {1,0,1,0,0}, {1,1,0,1,1}, {0,0,1,0,1}, {1,0,0,0,0} };
        vector<long long> arr(5, 1);
        for(int i=1; i<n; i++) {
            vector<long long> tem(5, 0);
            for(int j=0; j<5; j++)
                for(int k=0; k<5; k++)
                    tem[j] = (tem[j] + grid[j][k] * arr[k]) % mode;
            swap(tem, arr);
        }
        for(int i=1; i<5; i++) arr[i] += arr[i-1];
        return arr.back() % mode;
    }
```

通过矩阵快速幂进行计算的代码, 里面的矩阵相乘 multiply 以及矩阵幂运算 pow 函数是封装好的 
碰到类似的问题, 可以直接套用
```C++ []
class Solution {
public:
    typedef long long ll;
    typedef vector<ll> vec;
    typedef vector<vec> mat;
     
    const int MODE = 1e9 + 7;
     
    mat multiply(mat& A, mat& B) {
        int m = A.size(), n = B[0].size();
        mat res(m, vec(n, 0));
     
        // 两个矩阵相乘的算法
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<A[i].size(); k++)
                    res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MODE;
     
        return res;
    }
     
    mat pow(mat& A, long long n) {
        // 初始为单位矩阵
        mat res(A.size(), vec(A.size(), 0));
        for(int i=0; i<A.size(); i++)
            res[i][i] = 1;
     
        // 通过快速幂算法快速计算矩阵的 n 次方
        while(n > 0){
            if((n&1) == 1) res = multiply(A, res);
            n >>= 1;
            A = multiply(A, A);
        }
     
        return res;
    }
    int countVowelPermutation(int n) {
        // 矩阵的公式
        mat grid{{0,1,0,0,0}, {1,0,1,0,0}, {1,1,0,1,1}, {0,0,1,0,1}, {1,0,0,0,0} };
        grid = pow(grid, n-1);
        // 初始值
        mat res{{1}, {1}, {1}, {1}, {1}};
        res = multiply(grid, res);
        for(int i=1; i<5; i++) res[i][0] += res[i-1][0];
        return res.back().back() % MODE;
    }
};
```