### 思考

`O(m*n)`解法中关键一点，内层循环我们一直重复的在`[i, j]`之间加上`k`，怎么将这循环变成`O(1)`，成为问题的关键！

`[i, j]`之间加上`k`，这让我想到了等差数列，这不就是公差为`k`的等差数列吗？然后呢？

### 分析

设`answer[i]`表示第`i`个航班预订的座位数。定义一个差分数组`d[]`，`d[i]`表示第`i`个航班与第`i-1`个航班预订座位的差值，即`d[i] = answer[i] - answer[i - 1]`。

这样，我们每次遍历到`bookings[i] = [i, j, k]`，就只需要将`d[i]`增加`k`，`d[j + 1]`减少`k`即可，因为`i`到`j`之间，航班预订数量是没有变化的。

最后，计算`answer[i] = answer[i - 1] + d[i]`，返回`answer`即可。

### 推演

好吧，这样说可能有人没懂，我们按照题目的例子推演一次：
- 初始航班预订数量数组 `answer = [0,0,0,0,0]`，差分数组`d = [0,0,0,0,0]`
- 当遍历到`bookings[0] = [1,2,10]`的时候，差分数组第1位加10，第3位减10，变成`d = [10,0,-10,0,0]`
- 同理，当遍历到`bookings[1] = [2,3,20]`的时候，差分数组变成`d = [10,20,-10,-20,0]`
- 当遍历到`bookings[2] = [2,5,25]`的时候，差分数组变成`d = [10,45,-10,-20,0]`，第6位要减25，我们也不需要了
- 最后计算`answer`数组的值，`answer[0] = d[0] = 10`，`answer[1] = d[1] + answer[0] = 45 + 10 = 55`，`answer[2] = d[2] + answer[1] = -10 + 55 = 45`...
- 最最后发现，只申请一个数组表示`d[]`和`answer[]`就可以了，over！

### 代码
```Java
public int[] corpFlightBookings(
        int[][] bookings, int n) {

    int[] answer = new int[n];

    // 遍历bookings 计算航班i+1 对航班i 变化的预订数
    for (int[] b : bookings) {
        // 增加的预订数
        answer[b[0] - 1] += b[2];
        // 防止数组越界
        if (b[1] < n) {
            // 减少的预订数量
            answer[b[1]] -= b[2];
        }
    }

    // 航班i的预订数等于,i-1的预订数，加i时刻变化的预定数
    for (int i = 1; i < n; i++) {
        answer[i] += answer[i - 1];
    }
    return answer;
}
```

如果，还是不能理解，建议先看看 [拼车](https://leetcode-cn.com/problems/car-pooling/) 这题。

思路是一样的，但是更好理解。

**这篇题详细的题解我有在微信公众号写，欢迎大家阅读，并关注**[如逆水行舟](https://mp.weixin.qq.com/s/-q5kenfFikeHCGnABQtcWw)

![](https://pic.leetcode-cn.com/747ce292cd2617eb9ba30d4a73241a9486570333b14eabc737392f5eae5979f8-file_1584933189782)