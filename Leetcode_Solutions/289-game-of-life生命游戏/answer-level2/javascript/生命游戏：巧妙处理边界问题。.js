### 解题思路
其实这道题，大家看到第一眼应该就知道很简单了。

同时更新的意思就是让我们拷贝一份数据备用嘛，

根据原版备份数据去更新新的细胞阵列。

1. boardBak = copy(board)

然后看看核心思路

1. 统计8个位置的1的个数
2. ==3 那肯定要活着， ==2 自生自灭，其他情况都嗝屁


```

            boardBak[y-1][x-1] + 
            boardBak[y+1][x+1] + 
            boardBak[y-1][x] + 
            boardBak[y][x-1] + 
            boardBak[y-1][x+1] + 
            boardBak[y+1][x-1] + 
            boardBak[y][x+1] + 
            boardBak[y+1][x];


            if (sum === 3) {
                board[y][x] = 1;
            } else if(sum !== 2) {
                board[y][x] = 0;
            }

```
so 核心的部分就是这些，一点难度都没有。

然后假定m为行数，n为列数，将下面的循环包裹在核心代码外，就ok了

for (y=0, y < m)
  for (x=0, x < n)

是不是很简单！！

但是可恶的是，报错了。。因为边边上的细胞不够8个。。

那怎么办呢。。

我是这个样子处理的。

```
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]

====>

[
  [0,0,1,0,0],
  [0,0,1,0,0],
  [0,0,0,1,0],
  [0,1,1,1,0],
  [0,0,0,0,0],
  [0,0,0,0,0],
]

```

看粗来了吗

我用了一圈死细胞（0）把我们的目标组织包裹起来了，这样不管是边界细胞还是里面的细胞，大家都可以统一的按照8个周边处理咯

当然我们不要直接改造目标细胞，而是改造备份细胞。

改造完之后，只需要改变一下循环条件，目的是为了从(1,1)坐标的细胞开始遍历到(m-1,n-1)，不去遍历我们包裹的边界。

for (y=1, y < m-1)
  for (x=1, x < n-1)
     
     同样的现在我们的原阵列跟备份阵列的坐标存在不同咯。

     备份阵列因为多了一层，所以，需要-1之后才是备份细胞在原阵列中的位置。

     if (sum === 3) {
            board[y-1][x-1] = 1;
        } else if(sum !== 2) {
            board[y-1][x-1] = 0;
        }

到此就完事儿了。

下面是具体实现。
### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */

var gameOfLife = function(board) {
    let boardBak = [];
    let n = board[0].length;
     board.map((row)=>{
        boardBak.push([0, ...row, 0]);
    })
    boardBak = [new Array(n + 2).fill(0), ...boardBak, new Array(n + 2).fill(0)]
    
    let m = boardBak.length;
    n = boardBak[0].length;
    
    for (let y = 1; y < m - 1; y++) {
        for (let x = 1; x < n - 1; x++) {
            let sum = 0;
            sum = boardBak[y-1][x-1] + 
            boardBak[y+1][x+1] + 
            boardBak[y-1][x] + 
            boardBak[y][x-1] + 
            boardBak[y-1][x+1] + 
            boardBak[y+1][x-1] + 
            boardBak[y][x+1] + 
            boardBak[y+1][x];
            if (sum === 3) {
                board[y-1][x-1] = 1;
            } else if(sum !== 2) {
                board[y-1][x-1] = 0;
            }
        }
    }
    return board;
};
```