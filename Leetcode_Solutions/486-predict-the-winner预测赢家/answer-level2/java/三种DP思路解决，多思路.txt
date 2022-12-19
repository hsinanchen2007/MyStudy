**如果觉得写得有帮助的话希望可以给点个赞或是评论，有反馈写的才感觉有动力，有什么错误希望也能够指正，谢谢各位**

## 手稿
### [LeetCode笔记-Java-Py](http://note.youdao.com/noteshare?id=383f28fda2c91ea9736e71a189c80718&sub=09A29EF846D4455EA2C67845DD054759)
### [LeetCode笔记-Java版-专题篇](https://note.youdao.com/ynoteshare1/index.html?id=e3152a4cf9f16867c36adce45bc134cb&type=note)

### 486. 预测赢家 Medium
#### 方法1：DP loop version1
- 初始化时，`dp[i][i]` =`nums[i]`; 意味着如果只有一个`nums[i]`可以拿，先手玩家拿走了，`nums[i]` 也就是多出来的分数
- `dp[i][j]`表示先手玩家从`nums[i]`拿到`nums[j]`时，比后手玩家多的最大分数
- 对于`dp[i][j]`来说，先手玩家有两种拿法，一种是拿开头的数，一种是拿结尾的数
- 如果先拿了nums[i]，也就是意味着先手玩家目前的分数是`nums[i]`+后手玩家获得的最大分数的相反值，也就是`dp[i][j] = nums[i]+（-dp[i+1][j]`）这里的`dp[i+1][j]`表示是后手玩家比先手玩家多的最大分数，
- 同理如果先拿了nums[j]，也就是意味着先手玩家目前的分数是nums[j]+后手玩家获得的最大分数的相反值，也就是`dp[i][j] = nums[j]+（-dp[i][j-1]）`这里的`dp[i][j-1]`表示是后手玩家比先手玩家多的最大分数
而每一步，先手玩家都想拿到最大的分数，最后才有机会赢，所以最终的转移方程是：`dp[i][j] =max{nums[i]+（-dp[i+1][j]）, nums[j]+（-dp[i][j-1]）}`
- 最后要求的值时`dp[0][n-1]`也就是dp的右上角的数，判断这个数是否大于0，大于0意味着先手玩家比后手玩家多，会赢
- 注意`for loop`的顺序，解释参加下图


![cf77d6b62fee7a7600b4db53d511a7a.jpg](https://pic.leetcode-cn.com/3643a0bbf2ca4170bd6d89acce429568980dcafb950d77c7819944b0154c4e54-cf77d6b62fee7a7600b4db53d511a7a.jpg)
```
public boolean PredictTheWinner(int[] nums) {
    if (nums == null || nums.length == 0) return false;
    int n = nums.length;
    int[][] dp = new int[n][n];
    for (int i = 0; i < n; i++) dp[i][i] = nums[i];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1] >= 0;
}
```





#### 方法2：DP loop version2
- 思路同方法1，只是遍历的顺序不同，
- nums=[1,5,233,7]
![2.png](https://pic.leetcode-cn.com/844de16edd29d5f14d6a0b9618de6f91a61652a855690d9533df6df8a3452435-2.png)

- loop的时候处理了一个step
```
public boolean PredictTheWinner2nd(int[] nums) {
    if (nums == null || nums.length == 0) return false;
    int n = nums.length;
    int[][] dp = new int[n][n];
    for (int i = 0; i < n; i++) dp[i][i] = nums[i];
    for (int step = 2; step <= n; step++) {
        for (int i = 0; i < n - step + 1; i++) {
            int j = i + step - 1;
            dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1] >= 0;
}
```





#### 方法3：DP
- 思路来源于 `wzc1995`大神
- `dp[i][j]`表示先手玩家的在[i,j]范围内获取到的最大分数
- 通过turn来控制本轮是先手玩家选还是后手玩家选，在`for loop`的时候记下来sum也就是总的分数，比较`2*dp[0][n-1]`与`sum`的大小，`dp[0][n-1]`为先手玩家获取到的最大的分数在整个`0`到`n-1`范围内
- 如果本轮是先手玩家pick，其当然希望能最大化地获取到分数，也就是`dp[i][j] = max(nums[i] + dp[i + 1][j], nums[j] + dp[i][j - 1])`，
- 如果本轮是后手玩家pick，其当然是希望留给先手玩家的分数越少越好，`dp[i][j] = min( dp[i + 1][j],dp[i][j - 1])`,分别对应是后手玩家pick走头尾的元素，也就是`nums[i]`或者`nums[j]`
- 此解法难点大概有三个：
1. `dp`的含义，其不同于上面的两种方法，表示的是先手玩家获取到的最大分数，转移方程不容易想到
2. 如何控制先手玩家和后手玩家的`pick`，通过`turn`来控制
3. `loop`的顺序

- nums=[1,5,233,7]

![3.1.png](https://pic.leetcode-cn.com/56aa34cf7f52251fb63e4f0cd94688dcb0fdfce9fd5754f7a16eeeb58b04e9f2-3.1.png)

- nums=[1,233,5,7,230]
![3.2.png](https://pic.leetcode-cn.com/8259ad4c5955f30b4f719c3d3696912257295d9994cea2cbebb8d4d197876437-3.2.png)



```
public boolean PredictTheWinner3rd(int[] nums) {
    if (nums == null || nums.length == 0) return false;
    int n = nums.length;
    int[][] dp = new int[n][n];
    int turn = n & 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (turn == 1) dp[i][i] = nums[i];
        sum += nums[i];
    }
    for (int step = 2; step <= n; step++) {
        turn ^= 1;
        for (int i = 0; i < n - step + 1; i++) {
            int j = i + step - 1;
            if (turn == 1) dp[i][j] = Math.max(nums[i] + dp[i + 1][j], nums[j] + dp[i][j - 1]);
            else dp[i][j] = Math.min(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return 2 * dp[0][n - 1] >= sum;
}
```


---
---

#### **更多内容，欢迎订阅**
- **微信公众号:阿飞算法**
- **github(求个star):[geek-algorithm-leetcode](https://github.com/wat1r/geek-algorithm-leetcode)**
![qrcode_for_gh_76cb721bf802_258.jpg](https://pic.leetcode-cn.com/3a58c16558d9218298013dac7197caa816120e478f0f0ed1be2e2bd205395d56-qrcode_for_gh_76cb721bf802_258.jpg)