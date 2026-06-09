### 解题思路
分享一下我的思路历程  
刚开始看到这个题目觉得毫无思绪，然后开始在草稿本上画图，如果拆分成两个数，两数相等乘积最大，三个数的话，三数相等乘积最大………… 最后进入大脑死胡同，此时觉悟肯定需要通过划分子模块或者动态规划来解题。  
所以最后尝试划分的时候，发现一个数如果划分成两部分，取最大乘积的时候，这两部分各自的乘积必须得是最大的。如此可以自顶向上的求出小数的最大乘积，然后根据它们去求得更大的数的最大乘积。    
由此得到一个状态方程，如下图  
![1ecdcb7fd258ce73be2514328c029dc.jpg](https://pic.leetcode-cn.com/fd331e0afebf8fc8f37d977f440e177a2c08e84ce65947d055fc651c1d81c02f-1ecdcb7fd258ce73be2514328c029dc.jpg)  
M(n)是指n的最大乘积，这里需要注意的是，存在一种情况，对于n-k和k，可以不对其进行划分  

### 代码

```cpp

class Solution {
public:
    int integerBreak(int n) {
        vector<int> record(n+1, 0);
        record[1]=1;
        record[2]=1;
        // record[3]=2;
        // record[4]=4;
        // record[5]=6;
        for(int i=3; i<=n; ++i){
            int m=0;
            for(int j=1; j<=i/2; ++j){
                m = max(m, j*record[i-j]);
                m = max(m, (i-j)*record[j]);
                m = max(m, record[j]*record[i-j]);
                m = max(m, j*(i-j));
            }
            record[i] = m;
        }

        return record[n];
    }
};
```