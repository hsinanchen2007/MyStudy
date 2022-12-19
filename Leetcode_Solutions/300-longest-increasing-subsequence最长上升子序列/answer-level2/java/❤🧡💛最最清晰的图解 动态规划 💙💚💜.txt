## 解法

思考一下，很容易想到使用动态规划来做这道题目
<br>

1. 定义 `dp[i]` 来保存前 `i` 个元素中的最长上升子序列的元素的个数

2. 每次需要判断 `nums[i]` 时，和 `nums[0] ~ nums[i-1]` 进行比较，通过 `dp[0] ~ dp[i-1]` 得到前 `i` 个元素的最长子序列，根据前边的元素判断当前元素的最长子序列长度是多少

## 图解
<![幻灯片1.PNG](https://pic.leetcode-cn.com/08e9ca63769b4b3ee24709b53017e39731326e6e0c517fa80c67865f9c824b35-%E5%B9%BB%E7%81%AF%E7%89%871.PNG),![幻灯片2.PNG](https://pic.leetcode-cn.com/73996e509ac2bd3c3c4ea2b1deefcbc358faec481c1dcad6d3a36595a4da33d2-%E5%B9%BB%E7%81%AF%E7%89%872.PNG),![幻灯片3.PNG](https://pic.leetcode-cn.com/0ff032b59e96622daa4783961732f9c59d44f3a4990da664cc125aad749f7f78-%E5%B9%BB%E7%81%AF%E7%89%873.PNG),![幻灯片4.PNG](https://pic.leetcode-cn.com/1caa0379a4cd4dc9656c847ea70fc4d7c689df33364ed07d4333b10a03863625-%E5%B9%BB%E7%81%AF%E7%89%874.PNG),![幻灯片5.PNG](https://pic.leetcode-cn.com/0002222a518428e7fbd845fae4e12ad0f4990804b43a50bea41157c0d41afa72-%E5%B9%BB%E7%81%AF%E7%89%875.PNG),![幻灯片6.PNG](https://pic.leetcode-cn.com/8d200e457babc42213dced5dbd68e5c0e9430b85a2f8590d43883646089a4b3a-%E5%B9%BB%E7%81%AF%E7%89%876.PNG),![幻灯片7.PNG](https://pic.leetcode-cn.com/3aadbd7d1e7db3c32b9cfd3928fecbd7c81869b22d496938e40fe56148ef0213-%E5%B9%BB%E7%81%AF%E7%89%877.PNG),![幻灯片8.PNG](https://pic.leetcode-cn.com/86953331972de0f455cc2d486afc14e7a613461d804e623d08dbcc5d1eb19ec9-%E5%B9%BB%E7%81%AF%E7%89%878.PNG),![幻灯片9.PNG](https://pic.leetcode-cn.com/3bdc3bc11304e63e4a57438d49c2dee010fe9fb961e215949cbf36de09db43f2-%E5%B9%BB%E7%81%AF%E7%89%879.PNG),![幻灯片10.PNG](https://pic.leetcode-cn.com/55d4d8c053a5e09cecb84c88499cda31755fe1a07e1a21244158418c00df492e-%E5%B9%BB%E7%81%AF%E7%89%8710.PNG),![幻灯片11.PNG](https://pic.leetcode-cn.com/cdb76665523f3b34ba7e55d8b8c84e39cb5158e77d230edf1f72d5acc7fe97a4-%E5%B9%BB%E7%81%AF%E7%89%8711.PNG),![幻灯片12.PNG](https://pic.leetcode-cn.com/9750fbac3be642b8d25e0178572e63c6161f49eef24c9e676976eec9ece2f313-%E5%B9%BB%E7%81%AF%E7%89%8712.PNG),![幻灯片13.PNG](https://pic.leetcode-cn.com/670c6214841b10d5a09d13f31dfe834a5e5366a70e31143cd613c66d0fc46295-%E5%B9%BB%E7%81%AF%E7%89%8713.PNG),![幻灯片14.PNG](https://pic.leetcode-cn.com/3b42d36a2a92c26887b9bc0fa2ecca062b51f8c32fdc59faf47cefee7e1a35fb-%E5%B9%BB%E7%81%AF%E7%89%8714.PNG),![幻灯片15.PNG](https://pic.leetcode-cn.com/febaa1382b7987a4b40db34aa41387f5145399a160d8513d2fcc866d06d60cc3-%E5%B9%BB%E7%81%AF%E7%89%8715.PNG),![幻灯片16.PNG](https://pic.leetcode-cn.com/d5491758a8c8079cacd26b394761af44e9017a28f566683a6dc04ec2ac927e18-%E5%B9%BB%E7%81%AF%E7%89%8716.PNG)>

## 代码
```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int len = nums.length; 
        if (len == 0) return 0;
        int[] dp = new int[len];
        dp[0] = 1; 
        int res = dp[0];
        for (int i = 1; i < len; i++) {
            int max = dp[0];
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    max = dp[j] + 1 > max ? dp[j] + 1 : max;
            }
            dp[i] = max;
            res = dp[i] > res ? dp[i] : res;
        }
        return res;
    }
}
```

## 最后

![下载.jfif](https://pic.leetcode-cn.com/d0612995c5acc3bc44465e0223b754c636d624bb23bafa9338effc2348ff1fa2-%E4%B8%8B%E8%BD%BD.jfif)
