### 解题思路
f[i] 表示由i个点(这i个点递增排列)组成的二叉搜索树个数
若 i=0或1 则f[i] = 1
若 i>=2时 则可在1~i个点中,选第k个点作为根 1~k-1作为左子树 k+1~i作为右子树
          则在选第k个点为根的情况下的种类为 左子树种类*右子树种类 =  f[k-1]*f[i-k]
        因此 f[i] = sum f[k-1]*f[i-k] 其中 k属于1~i

### 代码

```cpp
int numTrees(int n) {
    vector<int> f(n+1,0);
    f[0] = f[1] = 1;
    for(int i = 2; i <= n; i++)
        for(int k = 1; k <= i; k++) f[i]+=f[k-1]*f[i-k];
    return f[n];
}

```