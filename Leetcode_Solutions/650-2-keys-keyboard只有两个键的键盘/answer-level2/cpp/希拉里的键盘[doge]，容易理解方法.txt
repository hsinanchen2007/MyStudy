# 分析过程

首先，最后一步一定是Paste操作。

对于1个数$n$有如下几种情况：

1. $n$为偶数，$n/2$ 时复制之后粘贴,$cnt[n] = cnt[n/2] + 2$
2. $n$为奇数时，分析过程如下

设倒数第k步骤为Copy操作

|步骤|操作|画布|剪切板|
|:--:|:--:|:--:|:---:|
|k| Copy| n-(k-1)*j| j|
|k-1| Paste|n-(k-1)*j + j| j|
|...|....|...|...|
|1|Paste|n-(k-(k-1))*j+j|j|

则有$n-(k-1)*j = j$, 即
$$
n=k \times j
$$

则可知道
1. 若k为质数，则$j=1, k = n$
2. 若k为奇数且是合数，则

$$
j = maxfactor\ of\ n\\
k = n/j\\
cnt[n] = cnt[n/j]
$$

# 代码优化

**需要将判断质数和因子分解结合起来**，
则将遍历过程改为
$$
j = n-1 \to \sqrt{n}
$$


```
class Solution {
public:
    int primeDecompose(int x) {
        // 返回 0 不是质数和合数
        // 在这里实际上没有进入
        if(x == 0 || x == 1) {
            return 0;
        }
        // 不是质数，返回最大的因子, 从后面往前面遍历
        
        for(int j = x-1; j >= sqrt(x); --j) {
            if(x % j == 0) {
                return j;
            }
        }
        // 质数 返回本身
        return x;
    }
    int minSteps(int n) {
        // 边偶数为奇数
        if(n == 1) {
            return 0;
        }
        int cnt = 0;
        while((n & 0x1) == 0) {
            cnt += 2; // 复制+粘贴
            n >>= 1; 
        }

        while(1) {
            int maxfactor = primeDecompose(n);
            if(maxfactor == n) {
                cnt += n;
                break;
            } else if(maxfactor != 0){
                cnt += n / maxfactor;
                n = maxfactor;
            } else {
                break;
            }
        }

        return cnt;

        
    }
};
```
