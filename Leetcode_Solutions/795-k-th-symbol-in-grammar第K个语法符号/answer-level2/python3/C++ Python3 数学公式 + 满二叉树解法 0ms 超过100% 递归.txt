![image.png](https://pic.leetcode-cn.com/dfa22f709630e119d0afd07005911d57fef380fb603fe979bb677d260f46a05f-image.png)


### 解法一，递归推导
这题关键是怎么推导第N行第K个数字与第N-1行的关系:

f(n, k) = 0 if f(n-1, ceiling(k/2)) == 0 && k为奇数 或 if f(n-1, ceiling(k/2)) == 1 k为偶数
f(n, k) = 1 if f(n-1, ceiling(k/2)) == 1 && k为偶数 或 if f(n-1, ceiling(k/2)) == 1 k为奇数

###  详细版（按照上述推论）

```cpp
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1 && K == 1)
            return 0;
        int pre = ceiling(K);
        cout << pre << endl;
        if(kthGrammar(N-1, pre) == 0)
            if(K%2 == 0)
                return 1;
            else
                return 0;
        else
            if(K%2 == 0)
                return 0;
            else
                return 1;
    }
    
    
    int ceiling(int k)
    {
        double val = k / 2.0;
        if(val > k/2)
            return (k+1)/2;
        else
            return k/2;
    }
};
```

###  简化版， 精简代码
```cpp
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1 && K == 1)
            return 0;
        int val = kthGrammar(N-1, (K+1) / 2) == 0 ? 1-K%2 : K%2;
        return val;
    }
};
```

### 解法二 满二叉树解法
所有行构成一个满二叉树，整个树的根节点为第一行N==1，值为0，第i行为第i-1行中的每个节点生成各自的左右子树。
每行K从1开始，若K为奇数，则说明K匙上一节点的左子树，若K为偶数，则说明K是上一节点的右子树。
前一节点为0，K为奇数(左子树)，则K处值为0，K为偶数(右子树)，则K处为1，前一节点为1类似。

### C++版

```cpp
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1)
            return 0;
        if(K%2==0) {
            int pre = kthGrammar(N-1, K>>1);
            return pre == 0 ? 1 : 0;
        }
        else if((K+1)%2 == 0) {
            int pre = kthGrammar(N-1, (K+1)>>1);
            return pre == 0 ? 0 : 1;
        }
        //不应该到这
        return -1;
    }
};
```

### Python3版

```python3
class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        if N == 1:
            return 0
        if K%2 == 0: # K是偶数，右子树
            pre = self.kthGrammar(N-1, K>>1) #前一个节点
            return 1 if pre == 0 else 0 #如果前一个节点是0，K为右子树为1, 若前一个值为1，K为0
        elif (K+1)%2 == 0: # K是奇数，左子树
            pre = self.kthGrammar(N-1, K+1>>1) 
            return 0 if pre == 0 else  1 #若前一个节点为0，K为左子树为0，否则K为1
```


