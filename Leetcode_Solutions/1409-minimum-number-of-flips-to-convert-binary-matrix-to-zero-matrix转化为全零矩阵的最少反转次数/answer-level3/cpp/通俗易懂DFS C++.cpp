一开始拿到这题，觉得有点难，但看到m和n的范围觉得还是有希望的，至少可以往暴力点的方向想。
### 几个重要的推论
#### 1. 反转两次等于没有什么都没做
这个很显然。
#### 2. 反转的顺序并不影响反转的结果
##### 示例
$\begin{bmatrix}0&0\\
0&1\end{bmatrix}\to\begin{bmatrix}1&0\\
1&0\end{bmatrix}\to\begin{bmatrix}0&1\\
1&1\end{bmatrix}\to\begin{bmatrix}0&0\\
0&0\end{bmatrix}$
反转的顺序：$(1,0)\to(0,1)\to(1,1)$
如果反转的顺序完全颠倒：$(1,1)\to(0,1)\to(1,0)$
$\begin{bmatrix}0&0\\
0&1\end{bmatrix}\to\begin{bmatrix}0&1\\
1&0\end{bmatrix}\to\begin{bmatrix}1&0\\
1&1\end{bmatrix}\to\begin{bmatrix}0&0\\
0&0\end{bmatrix}$
可见最终结果还是一样的
##### 简单证明：
2.1 设两次反转$f_1,\:f_2$分别反转了 $P=[p_1,p_2\cdots p_{k_1}]$和$Q=[q_1,q_2\cdots q_{k_2}]$，其中 $p\in P,q\in Q$ 表示矩阵中的某个元素，即二元组。
则 $P\land Q,\:P-Q,\:Q-P$ 分别表示$P,Q$均反转的那些元素，$P$反转而$Q$不反转，$Q$反转而$P$不反转。（$P\land Q$可能为空集）
对于不同顺序的反转$f_1\:f_2$和$f_2\:f_1$，$P\land Q$被反转两次不变，$P-Q,\:Q-P$被反转一次，结果是一致的。 可见交换相邻两次反转的顺序不影响结果
2.2 考虑三次反转 $abc$，由 2.1 知 $abc\to bac\to bca \to cba$ 则 $a,c$ 也可以交换
结合 2.1，2.2 可知反转的顺序对结果无影响
#### 3. 结合1、2，可以推出反转的结果只和进行了哪些种类的反转有关。
对于2阶方阵，有四种可能的反转，每一种都可以进行或者不进行，则情况总数为$2^4$。则对于3阶方阵，也是题目的最复杂情形，情况总数为$2^9$，这个计算量是可以接受的。
### 思路
由上面的推论可知，我们只需要对不同种类的反转进行深度优先搜索即可。
![arrow4.png](https://pic.leetcode-cn.com/7d4f5681b497eaf4cb70248ea74674fb6524d359d8e25321a59acf8405f7d0e3-arrow4.png)
### 代码
``` C++
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int steps=INT_MAX;
        // 进行深度优先搜索 并修改最少次数 否则返回-1
        dfs(mat,m,n,steps,0,0);
        if(steps==INT_MAX)
            return -1;
        return steps;
    }

    void dfs(vector<vector<int>>& mat, int& m, int& n, int& steps, int cur, int temp){
        int i,j,sum=0;
        // 判断全0
        for(i=0;i<m;++i)
            for(j=0;j<n;++j)
                sum+=mat[i][j];
        if(sum==0){
            steps=min(steps,temp);
            return;
        }
        // 判断每个种类的反转已经搜索
        if(cur==m*n)
            return;
        // 不进行当前反转
        dfs(mat,m,n,steps, cur+1, temp);
        // 进行当前反转
        i=cur/n;j=cur%n;
        mat[i][j]=!mat[i][j];
        if(i>0)
            mat[i-1][j]=!mat[i-1][j];
        if(i<m-1)
            mat[i+1][j]=!mat[i+1][j];
        if(j>0)
            mat[i][j-1]=!mat[i][j-1];
        if(j<n-1)
            mat[i][j+1]=!mat[i][j+1];
        dfs(mat,m,n,steps, cur+1, temp+1);
        // 回溯
        mat[i][j]=!mat[i][j];
        if(i>0)
            mat[i-1][j]=!mat[i-1][j];
        if(i<m-1)
            mat[i+1][j]=!mat[i+1][j];
        if(j>0)
            mat[i][j-1]=!mat[i][j-1];
        if(j<n-1)
            mat[i][j+1]=!mat[i][j+1];
    }
};
```
