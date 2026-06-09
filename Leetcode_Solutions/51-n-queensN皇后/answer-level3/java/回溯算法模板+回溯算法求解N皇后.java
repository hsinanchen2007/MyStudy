
## 回溯算法简介

### 回溯算法对问题的要求

当一个问题满足：

1. 多步：需要多步来完成
2. 多选：每一步有多种决策选择，并且你无法预见哪个选择会使你得到解，哪个选择会使你得不到解
3. 瞻前：后续步骤会依赖于先前步骤的选择

这个问题就可以用回溯算法来解决。

拿求解迷宫路径的问题进行比对：

- 要求1：寻找迷宫路径时，每一步操作就确定路径上的一个点，需要多步来确定一条完整的路径
- 要求2：当你在当前步骤确定路径的下一个节点时，你可能有很多节点可选，并且你不知道选哪个节点才是可以求得最终解的
- 要求3：你在当前步骤的候选节点是由你之前步骤确定的路径决定的  

所以求解迷宫问题可以通过回溯算法来解决。读者可以怎么样可以让N皇后问题也符合回溯算法的要求，没有思路可以看下文使用回溯算法求解N皇后问题”的部分

### 回溯算法的思想

回溯算法用到的思想是：从一条路往前走，能进则进，不能进则退回来，换一条路再试，以此来把所有的可能性都考虑一遍。总结起来也就是深度优先搜索。

### 回溯算法的模板

回溯算法是由递归函数实现的，这个递归函数的基本骨架如下：

```java
void backtrack(resultStack, arg1, arg2, ...){
    // 当满足题目的某种要求时，说明此时找到了问题的一个解
    if (some condition){
        // 在这里根据题目要求做出相关操作
        // 这里的操作一般是将resultStack复制一份，加入到所有解的集合中
        some operations;
        
        // 直接返回
        return;
    }
    
    // candidates 表示"要求2"中提到的多种候选决策
    // 在这里通过for循环遍历所有的候选决策
    for (candidate : candidates){
        // 当候选条件不符合要求时，跳过这个条件
        if (candidate does not satisfy some requirements){
            continue;
        }
        
        // 下面三行是这个函数的核心，体现了回溯算法能进则进的思想
        // 先把当前候选条件加入结果栈中，然后进入下一步，
        // 从下一步中返回后，将当前候选条件出栈，把结果栈恢复到之前的状态，
        // 以便考虑下一个candidate（for循环的下一个元素）
        resultStack.push(candidate);
        backtrack(resultStack, arg1, arg2);
        resultStack.pop();
    }
}
```


## 使用回溯算法求解N皇后问题

**如何确定思路呢**？可以从回溯算法的要求出发：多步、多选、瞻前。首先要把问题分解成一个多步可解的情形，我们可以这样想：棋盘的每行只能而且必须放一个皇后，只要把所有行都放上一个皇后，放置方案就出来了，所以此时回溯算法的每一步就是：在当前行中放置一个皇后。然后我们就可以看这样满不满足回溯算法的要求2和要求3了，每一行有N列，每一列都是一个决策选择，所以满足要求2；在选择当前行要在哪一列放置皇后时，要保证该位置不会和之前放置的皇后在同一列、或者同一斜线上，所以满足要求3。

这样一来解决方案其实很简单了，只要套上面的模板就可以了：

```java
import java.util.*;

class Solution {
    // 用二维数组表示棋盘
    private char[][] board;
    // N皇后问题的N
    private int n;
    // 所有可行的放置方案的集合
    private List<List<String>> solutions = new ArrayList<>();
    
    // 主函数
    public List<List<String>> solveNQueens(int n) {
        this.n = n;
        // 初始化棋盘，并且把每一个单元格都设置为'.'，表示棋盘是空的，没有皇后
        this.board = new char[n][n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                board[i][j] = '.';
            }
        }
        
        // 进入回溯函数
        backtrack(new ArrayList<>(), new ArrayList<>(), new ArrayList<>(), 0);
        return solutions;
    }
    
    // 实现回溯算法的函数
    // usedCols 表示使用过的列号，列号从0开始
    // usedDianonals1 表示使用过的、方向为从左上到右下的 斜线号
    // usedDianonals2 表示使用过的、方向为从右上到左下的 斜线号
    // row 表示当前步骤的行号，行号从0开始
    private void backtrack(List<Integer> usedCols, List<Integer> usedDiagonals1, List<Integer> usedDiagonals2, int row){
        // 行号从0开始，所以棋盘的最后一行的标号是n-1，
        // 当行号为n时，说明所有的行都已经放置了正确位置的皇后，可以添加解了。
        if (row == n){
            addSolution();
            return;
        }
        
        // 遍历当前行的所有列
        for (int j = 0; j < n; j++){
            if (usedCols.contains(j) || usedDiagonals1.contains(row - j) || usedDiagonals2.contains(row + j)){
                continue;
            }
            
            board[row][j] = 'Q';
            usedCols.add(j);
            usedDiagonals1.add(row - j);
            usedDiagonals2.add(row + j);
            backtrack(usedCols, usedDiagonals1, usedDiagonals2, row + 1);
            board[row][j] = '.';
            usedCols.remove(usedCols.size() - 1);
            usedDiagonals1.remove(usedDiagonals1.size() - 1);
            usedDiagonals2.remove(usedDiagonals2.size() - 1);
        } 
        
    }
    
    private void addSolution(){
        List<String> solution = new ArrayList<>();
        for (int i = 0; i < n; i++){
            StringBuilder builder = new StringBuilder();
            for (int j = 0; j < n; j++){
                builder.append(board[i][j]);
            }
            solution.add(builder.toString());
        }
        
        solutions.add(solution);
    }
}
```

