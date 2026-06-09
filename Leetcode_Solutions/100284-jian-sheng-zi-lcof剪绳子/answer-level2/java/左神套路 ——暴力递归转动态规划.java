```
    public int cuttingRope_init(int n) {
        int result = 1;
        for (int i = 1; i < n; i++){
            result = Math.max(result, Math.max(i * cuttingRope_init(n - i), i * (n - i)));
        }
        return result;
    }
    /**
     * 1.写出递归尝试版本，可以看出，分为两种思路
     *      1.如果绳子不用切了，那么乘积即i * (n - i)
     *      2.如果之后还需要之后区间的切绳子，那么乘积即为i * 函数（ n - i)
     *      3.如果要切之前区间的绳子，不用额外判断，因为切前面区间的绳子已经出现在result中，如果其不为最大值，已经舍去了。
     * 2.分析可变参数n，构建出一个一维数组，这里需要长度为n + 1的数组，因为包含长度为0的绳子最大乘积，还需要包括4的
     * 3.在dp中找到终状态，为dp[n]
     * 4.找到baseCase，确定哪些值完全不依赖，这里为dp[0],dp[1],dp[2]
     * 5.看一个普通位置需要哪些信息
     *      分析一个例子
     *      i = 3， j = 1 |||   0, 1 * dp[2] , 1* 2
     *             j = 2 |||   2, 2 * dp[1] , 2* 1
     *      第一列即为当前的dp[i]的值，比较是因为在第二个for中j是变化的
     *      第二列为j之后的部分还是可以分的
     *      第三列为j之后的数组不可以再分
     *      因为这里j从1开始，所以覆盖了所有的切分情况。
     * 6.逆回去就是DP填表的过程，这里没有用到。
    * */
    public int cuttingRope(int n) {

        int[] dp = new int[n + 1];//dp[i]表示长度为i的绳子最大乘积
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;//因为题目已经给出  2< n 的，不用判定，动态规划为了后面的计算，所以初始化了三个值
        for (int i = 3; i <=n;i++){
            for (int j = 0; j < i; j++){
                dp[i] = Math.max(dp[i] , Math.max(j * (i - j), j * dp[i - j]));
            }
        }
        return n;
    }
```
