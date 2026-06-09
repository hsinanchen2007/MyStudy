### 题意分析
典型的BFS题目。

题目做得多了，看到类似于“向上、下、左、右移动”之类的字眼，就会自然而然地想到BFS。

而且必有除方格临界值外的限制条件：“行坐标和列坐标的数位之和大于`k`”。

所以，本题大致可以划分为以下几个关键点：

- 位数和的计算
- 四周方向的遍历
- 限制条件
- 格子数的统计

### 逻辑梳理
##### 位数和计算
1. 利用字符串

将数值划分成由位数组成的数组，然后累加每个位数上的值。
```
function getSum(num) {
    let stringAry = num.toString().split('');

    return stringAry.reduce((a, b) => Number(a) + Number(b), 0);
}
```
2. 数学公式

- 对数值进行基于10的取余，得到该位数上的值
- 更新数值（更新后的数值 = 更新前的数值 / 10），就移除了之前的位数
- 对更新后的数值进行相同的操作（取余，更新）
- 当数值为0时，得出计算结果
```
function getSum(num) {
    let answer = 0;

    while(num) {
        answer += num % 10;
        // 向下取整，因为可能出现小数
        num = Math.floor(num / 10);
    }

    return answer;
} 
```

##### 四周方向的遍历
很自然地可以想到使用**方向数组**来进行遍历辅助。
```
// 方向数组
const directionAry = [
    [-1, 0], // 上
    [0, 1], // 右
    [1, 0], // 下
    [0, -1] // 左
];
```
至于方向数组的由来，我之前的多篇题解都已经分析过了，有兴趣查看类似思路的同学，请移步[这里](https://leetcode-cn.com/problems/available-captures-for-rook/solution/javascriptguan-fang-ti-jie-de-xiang-xi-bu-chong-to/)和[这里](https://leetcode-cn.com/problems/game-of-life/solution/javascripttong-su-yi-dong-zhu-shi-xiang-jin-yi-k-2/)查看。

按照惯例，本处还是会再分析一遍，便于那些没有看过我类似题解的同学阅读。

首先，我们将方格抽象成由X（行）和Y（列）组成，则X（行）设定为西——>东方向，Y（列）设定为北——>南方向。即上北，下南，左西，右东，则x表示在X上的位置，y表示在Y上的位置。

很轻易地可以总结出：
- `(-1 + x, 0 + y)`：`x`坐标后退一格，`y`不变，犹如由南向北移动，即当前单元格的**上方**。
- `(0 + x, 1 + y)`：`x`坐标不变，`y`前进一格，犹如由西向东移动，即当前单元格的**右方**。
- `(1 + x, 0 + y)`：`x`坐标前进一格，`y`不变，犹如由北向南移动，即当前单元格的**下方**。
- `(0 + x, -1 + y)`：`x`坐标不变，`y`后退一格，犹如由东向西移动，即当前单元格的**左方**。

当然，本题可以简化成仅进行“**向右**”和“**向下**”的遍历操作。

##### 限制条件
每道的BFS题目，都有其限制（边界）条件，本题也不例外。

很显然，单元格坐标`[i, j]`不能超过其方格的边界:
- `i >= 0`
- `j >= 0`
- `i < m`
- `j < n`

并且本题还需要满足“行坐标和列坐标的数位之和大于`k`”这一条件： `getSum(offsetX) + getSum(offsetY) > k`。

除此之外，最关键的是，**已经到达过的单元格，是不需要再纳入到达个数统计的范畴内的**。

判断类似于这种"是否存在"的问题，最便捷的方法就是使用Set数据结构。

因为Set这一数据结构满足了**项的唯一性**，比Map来得更加的方便，并且在本题中，使用Set数据结构还有个小优点，暂先按下不表。

所以，上述的限制条件，可以使用以下伪代码来实现：
```
// 方向数组
const directionAry = [
    [-1, 0], // 上
    [0, 1], // 右
    [1, 0], // 下
    [0, -1] // 左
];

// 已经走过的坐标，本题明确从坐标[0, 0]开始
let set = new Set(['0,0']);

遍历 {
    if(不满足限制条件) {
        // 跳过
        continue;
    } 
    // 满足的后续操作
    ...
}
```
##### 格子数的统计
一般来说，为了进行数量的统计，都会声明一个`amount`变量，在满足条件时，进行累加操作，最后再返回它。

当在本题中，我们使用了Set来存储走过的单元格，那么，Set的长度，就是单元格的个数（Set内元素唯一），即起到了`amount`变量的作用。

这也就是前文说到的小优点。

### 代码实现
以下是具体的代码实现，结合注释食用更佳~
```
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
    // 位数和
    function getSum(num) {
        let answer = 0;

        while(num) {
            answer += num % 10;
            num = Math.floor(num / 10);
        }

        return answer;
    } 
    // 方向数组
    const directionAry = [
        [-1, 0], // 上
        [0, 1], // 右
        [1, 0], // 下
        [0, -1] // 左
    ];

    // 已经走过的坐标
    let set = new Set(['0,0']);

    // 将遍历的坐标队列，题意要求从[0,0]开始走
    let queue = [[0, 0]];

    // 遍历队列中的坐标
    while(queue.length) {
        // 移除队首坐标
        let [x, y] = queue.shift();

        // 遍历方向
        for(let i = 0; i < 4; i++) {
            let offsetX = x + directionAry[i][0];
            let offsetY = y + directionAry[i][1];


            // 临界值判断
            if(offsetX < 0 || offsetX >= m || offsetY < 0 || offsetY >= n || getSum(offsetX) + getSum(offsetY) > k || set.has(`${offsetX},${offsetY}`)) {
                continue;
            }

            // 走过的格子就不再纳入统计
            set.add(`${offsetX},${offsetY}`);

            // 将该坐标加入队列（因为这个坐标的四周没有走过，需要纳入下次的遍历）
            queue.push([offsetX, offsetY]);
        }
    }

    // 走过坐标的个数就是可以到达的格子数
    return set.size;
};
```



