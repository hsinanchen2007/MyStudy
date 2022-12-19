[toc]

# 题目

```
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
```

```
示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
```

# 思路

这题简单的一批，五分钟ac。

是非常经典的**滑动窗口**（不知道是不是这个名字）问题

指针`i j`分别指向滑动窗口的首尾，每次操作都维护窗口中值的和`S`，`i`增加会减少`S`，`j`增加会增加`S`

（注：也可以偷懒，因为**等差数列**有求和公式，也是`O(1)`级别的）

操作过程中对比`target`，相等就记录结果，小于就增加`j`，大于就增加`i`

注意循环中止条件可以设为`j + j - 1`也就是`j`和`j`的前一项相加大于`target`，因为这样的话后边无论怎样组合都不可能等于`target`了

# 代码
```javascript
var findContinuousSequence = function(target) {
    let s = 0;
    let pi = 1;
    let pj = 2;
    const result = [];
    const sum = (x, y) => (x + y) * (y - x + 1) / 2;
    const spread = (x, y) => new Array(y - x + 1).fill().map((ele, i) => x + i);
    while(2 * pj - 1 <= target) {
        s = sum(pi, pj);
        if(s === target) result.push(spread(pi, pj)),pj += 1;
        else if(s < target) pj += 1;
        else pi += 1;
    }
    return result;
};
```

# 复杂度分析

时间复杂度： 核心操作是和与target的比较，最多比较`target/2`次，所以是`O(N)`

空间复杂度：不算结果的空间是`O(1)`

# 运行时间

[无效的图片地址](C:%5CUsers%5CMax%5CAppData%5CRoaming%5CTypora%5Ctypora-user-images%5Cimage-20200306091339215.png)