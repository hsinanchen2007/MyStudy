### 解题思路
首先是采用分治的思想：假设x个节点的不同搜索二叉树的种类为f(x)。那么n个节点中，根节点的选取有n种；与之相应的左右子树的节点数量对为：(0,n-1),(1,n-2),...,(n-1,0)，那么f(n) = f(0)\*f(n-1) + f(1)\*f(n-2) + ... + f(n-1)\*f(0);
这是典型的卡特兰数问题，所以利用其中的公式：
$$
K(n) = C_{2n}^n - C_{2n}^{n-1};
$$
然后求解组合数时，使用杨辉三角来进行求解。

### 代码

```cpp
class Solution {
public:
    double C(int n, int k) {
		 if (k == n || k == 0) return 1;
		 vector<double> f(k + 1, 1);
		 int cnt = 2;
		 while (cnt <= n) {
			 int t = min(cnt-1, k);
			 for (int j = t; j >= 1; --j) {
				 f[j] = f[j - 1] + f[j];
			 }
			 cnt++;
		 }
		 return f[k]-f[k-2];
	 }
    int numTrees(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        return int(C(2*n-1,n));
    }
};
```