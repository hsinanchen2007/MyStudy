### 逻辑梳理
这道题目，在题意上没什么拗口的，很轻松就可以梳理出如下的解题步骤：
1. 构造新数组，存放每个细胞（一次更新后）的状态
2. 统计`board`中每个细胞周围的其他细胞（未更新）状态
3. 更新每个细胞的状态，即一次更新后的细胞（新数组）
4. 返回新数组

这是作者一开始的解题思路，不过在提交时才发现，有个小限制在题目中没有明确指出——**需要原地**，换句话说，LeetCode判断的是`board`，所以不能返回一个新数组。

这也很容易解决，直接构造一个与原始数组`board`状态一致的数组副本，然后遍历时参考副本状态，改变board状态，就可以轻松解决。

所以需要改造下解题步骤：
1. 构建`board`副本数组
2. 统计**副本数组**中每个细胞周围的其他细胞（未更新）状态
3. 更新每个细胞的状态，即一次更新后的细胞（`board`数组）

现在来以此解决这三个子问题：

##### 副本构造
最简单粗暴的方法，就是利用双层循环来遍历。

不过在JavaScript世界中，有个更巧妙的方法：

由于`board`数组中，每个值非`0`即`1`，都是基本类型（`Number`），不存在指针引用问题，所以可以使用数组解构来快捷实现。即：

```
// 数组副本
const CopyBoard = board.map(ary => {
    // 值是基础类型（Number），不存在引用问题，直接解构比较方便
    return [...ary];
});
```
##### 状态统计
状态统计的关键，其实就是周边位置如何确定。

在之前的“每日一题”活动中，这类的问题非常常见，比如[车的可用捕获量](https://leetcode-cn.com/problems/available-captures-for-rook/)，一般常见的做法，都是利用坐标数组进行遍历，提高解题的灵活性。

坐标数组的确定，我在[题解](https://leetcode-cn.com/problems/available-captures-for-rook/solution/javascriptguan-fang-ti-jie-de-xiang-xi-bu-chong-to/)中已经分析过一次了。当然，本次还是会重新分析一遍，供没做过类似题目的同学提供参考~

首先，将`board`抽象成由X（行）和Y（列）组成，则X（行）设定为西——>东方向，Y（列）设定为北——>南方向。即上北，下南，左西，右东，则`x`表示在X上的位置，`y`表示在Y上的位置。

很轻易地可以总结出：
`(0 + x, 1 + y)`：x坐标不变，y前进一格，则是由**西向东**移动。
`(1 + x, 0 + y)`：x坐标前进一格，y不变，则是由**北向南**移动。
`(0 + x, -1 + y)`：x坐标不变，y后退一格，则是由**东向西**移动。
`(-1 + x, 0 + y)`：x坐标后退一格，y不变，则是由**南向北**移动。
`(-1 + x, -1 + y)`：x，y各后退一格，即向**西北方向**的对角线移动。
`(-1 + x, 1 + y)`：x坐标后退一格，y坐标前进一格，即向**东北方向**的对角线移动。
`(1 + x, 1 + y)`：x，y各前进一格，即向**东南方向**的对角线移动。
`(1 + x, -1 + y)`：x坐标前进一格，y坐标后退一格，即向**西南方向**的对角线移动。

把上述的坐标由上到下，将加号“`+`”视为分割线，你会发现，x的位置移动，由数组`[0, 1, 0, -1, -1, -1, 1, 1]`构成，y的位置移动，由`[1, 0, -1, 0, 1, -1, 1, -1]`构成，这样一来，方向坐标就确立了。

方向数组的确定，给解题带来极大的便利，无需手动判断八个位置，只需要遍历坐标数组一次，就可以统计出坐标`(i, j)`细胞周边的细胞存活量。

```
// 方向数组
const idx = [0, 1, 0, -1, -1, -1, 1, 1];
const jdx = [1, 0, -1, 0, 1, -1, 1, -1];

// 利用双重循环保证每个细胞都走一遍
for(let i = 0; i < CopyBoard.length; i++) {
    for(let j = 0; j < CopyBoard[i].length; j++) {
        
        // 遍历方向坐标数组
        for(let index = 0; index < 8; index++) {
            let x = i + idx[index];
            let y = j + jdx[index];
            ...
        }
    }
}           
```
##### 细胞状态更新
这点没什么好深入讲解的，直接依据题意就行：
```
// 该位置细胞死活状态决策
if(liveAmount < 2 || liveAmount > 3) {
    board[i][j] = 0;
} else if (liveAmount <= 3 && CopyBoard[i][j]) {
    board[i][j] = 1;
} else if (liveAmount === 3 && !CopyBoard[i][j]) {
    board[i][j] = 1;
}
```
值得一提的是，在JavaScript中，进行布尔类型的判断时，0为假值，1为真值，故可以省略掉一些全等判断的代码。

### 代码实现
以下是具体代码实现，结合注释食用更佳~
```
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    // 八个方向的偏移量
    const idx = [0, 1, 0, -1, -1, -1, 1, 1];
    const jdx = [1, 0, -1, 0, 1, -1, 1, -1];

    // 数组副本
    const CopyBoard = board.map(ary => {
        // 值是基础类型（Number），不存在引用问题，直接解构比较方便
        return [...ary];
    });


    // 遍历每个细胞
    for(let i = 0; i < CopyBoard.length; i++) {
        for(let j = 0; j < CopyBoard[i].length; j++) {
            
            // 周边活细胞统计
            let liveAmount = 0;

            // 八个方向都走一遍
            for(let index = 0; index < 8; index++) {
                let x = i + idx[index];
                let y = j + jdx[index];

                // 边界规避
                if(x < 0 || y < 0 || x >= CopyBoard.length || y >= CopyBoard[i].length) continue;
                
                // 活细胞则计数加1
                liveAmount += CopyBoard[x][y] ? 1 : 0;
            }

            // 该位置细胞死活决策
            if(liveAmount < 2 || liveAmount > 3) {
                board[i][j] = 0;
            } else if (liveAmount <= 3 && CopyBoard[i][j]) {
                board[i][j] = 1;
            } else if (liveAmount === 3 && !CopyBoard[i][j]) {
                board[i][j] = 1;
            }
        }
    }
};
```


