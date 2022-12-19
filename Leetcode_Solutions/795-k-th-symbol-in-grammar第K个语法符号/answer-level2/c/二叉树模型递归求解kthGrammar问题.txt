### 解题思路

根据问题，上一层的bit会在下一层被两个bit代替，显然这是一个典型的满二叉树。上层的0在下层变为01，上层的1在下层变为10；这样下层第K个bit的取值既与其双亲bit的取值有关，又与其为左右bit有关，我们把这个关系列出下面这张表：

- parent    left/right      value
-   0           0             0
-   0           1             1
-   1           0             1
-   1           1             0

很明显，K处值由前两者异或运算得出。如此我们就把求解第 N 层的问题递归转换为求解第 N-1 层的问题。由于 K 从 1 开始计数，因此 left/right 取 (k + 1) % 2；而其父bit K值应取 (k + 1) / 2。这样我们就可以在 N > 1 层时递归调用 kthGrammar(N-1, (K+1)/2) ^ ((K+1) % 2) 来求解。提交截图和具体代码如下：

![leetcode_kthGrammar.PNG](https://pic.leetcode-cn.com/5f3c64af0f410e63b85e6c02231899f71eb2c82cf7e34043924460658a87a262-leetcode_kthGrammar.PNG)


```c
int kthGrammar(int N, int K){
    if(N <= 1) return 0;
    else {
        return (kthGrammar(N-1, (K+1)/2) ^ ((K+1) % 2));
    }
}
```