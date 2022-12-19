### 解题思路
递归调用。
第N,K的值等于第(N-1)层的第(K+1)/2个值，与当前值相等，无论K为奇数还是偶数。
当K为偶数时返回的值需做取补码。（K为奇数时直接返回)。
分析：这组数据可看做二叉树。相邻两层的规律可理解成每个节点左孩子的值，等于其父节点的值，右孩子等于父节点的补码。

![Capture.PNG](https://pic.leetcode-cn.com/5898f95d9f75cb18af62965bae0ec67c3922297e278a680a176e47c833552545-Capture.PNG)

### 代码

```cpp
    class Solution {
    public:
        int kthGrammar(int N, int K) {
            if(N==1)
                return 0;
            int ans = kthGrammar(N-1, (K+1)>>1);
            return(K%2==1 ? ans:(1-ans));
        }
    };
```
注：本方法参考自trsteel的解法“N层第k个节点由N-1层由第(k+1)/2推导出来”。
