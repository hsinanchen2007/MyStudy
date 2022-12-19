### 思路

- 标签：动态规划
- 假设n个节点存在二叉排序树的个数是G(n)，令f(i)为以i为根的二叉搜索树的个数，则

$G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n)$

- 当i为根节点时，其左子树节点个数为i-1个，右子树节点为n-i，则

$f(i) = G(i-1)*G(n-i)$

- 综合两个公式可以得到 [卡特兰数](https://baike.baidu.com/item/%E5%8D%A1%E7%89%B9%E5%85%B0%E6%95%B0 "卡特兰数") 公式

$G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)$

### 代码

```Java []
class Solution {
    public int numTrees(int n) {
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i < n + 1; i++)
            for(int j = 1; j < i + 1; j++) 
                dp[i] += dp[j-1] * dp[i-j];
        
        return dp[n];
    }
}
```

### 画解

<![frame_00001.png](https://pic.leetcode-cn.com/211b23ff4c8d336e04cca5960c92ebe7d5274d93bc99b41477d030f7056ec90d-frame_00001.png),![frame_00004.png](https://pic.leetcode-cn.com/9edafc7a19d279c8456381b574dfa83ff6f8030cc03a62f050adb36e3c4e8cc8-frame_00004.png),![frame_00007.png](https://pic.leetcode-cn.com/5e13a34a242ad4a1a509b1c54fc17d2e4c81add7d8c5104f96b5f91293af8031-frame_00007.png),![frame_00010.png](https://pic.leetcode-cn.com/96bb714d079c7aef72465216b1f205cbf78865f6bcc3cf69691f7d46096196e0-frame_00010.png),![frame_00013.png](https://pic.leetcode-cn.com/e37104d5c9db70f7126fd20d117eb4841b4759a59addcf4cd795a2968dc2b096-frame_00013.png),![frame_00016.png](https://pic.leetcode-cn.com/69509ce7a83c6c57bc6fb611db21ef1a83c552cc4237e75fb338162c8e128c12-frame_00016.png),![frame_00019.png](https://pic.leetcode-cn.com/79d1b9afd3eab754adaa5f54f2a203b17c9e3fd6c74aa54cf73ad01a6db5344f-frame_00019.png)>


