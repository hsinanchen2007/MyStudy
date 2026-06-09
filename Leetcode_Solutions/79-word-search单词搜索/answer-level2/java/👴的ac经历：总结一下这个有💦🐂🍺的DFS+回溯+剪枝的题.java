// ## 心路历程：
// 给大🔥看看👴的通过本题的流程，这个题很能反映出为什么要回溯，要剪枝，还是有💦东西的。
// ### 1.这tm不就是岛问题吗
// 👴一开始把这个题当成岛问题（leetcode200、695）来做了，既然要搜一个字符串在矩阵里存不存在，那不就是DFS就完事了？为了避免每次DFS的时候被搜过的地方再重复搜索，每次搜的地儿给改一下状态，这也太tm简单了。因此👴最开始的代码是这样的：
// ```java
class Solution {
    public boolean exist(char[][] board, String word) {
        if(board == null || board.length == 0 || board[0].length == 0 ) {
            return false;
        }
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                if(dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, int i, int j, String word, int cur) {
        if(cur == word.length()) {
            return true;
        }
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length 
        || board[i][j] != word.charAt(cur)) {
            return false;
        }
        //改变一下搜索过的地儿的状态，避免重复搜索
        board[i][j] = '.';
        return dfs(board, i + 1, j, word, cur + 1) || dfs(board, i - 1, j, word, cur + 1)
                || dfs(board, i, j + 1, word, cur + 1)
                || dfs(board, i, j - 1, word, cur + 1);
    }
}
// ```
// 然后一提交，一个大大的❌，分析了一下这个case：
// ```java
[["C","A","A"],["A","A","A"],["B","C","D"]]
"AAB"
=> 
C A A
A A A
B C D
// ```
// 通过人肉DEBUG，可以发现，👴的代码第一波DFS后，这个case就变成这样了
// ```java
C . A
A . A
B C D
// ```
// 这矩阵变成这🐦样了，本来有AAB的矩阵被我DFS了一波后，矩阵发生变化，AAB没了。。

// 找到❌的原因了，咋改呢？如果我在DFS的过程中不改矩阵的状态，那我就会出现重复搜索的情况啊，这可不行，因此矩阵是必须得改的。那就只剩下一个办法了，每次DFS的过程中修改矩阵，DFS完了再把矩阵给改回去呗，**这就是回溯！**

// 贴一段官方点的说法：DFS前后必须要保证执行前后程序面对问题的状态是相同的，因此当前问题缩小为子问题时所做的对当前问题状态产生影响的事情应该全部失效，这就是所谓的回溯时还原现场。

// ### 2. 为啥👴加上回溯了还不能AC？
// 加上了回溯后代码是这样的：
// ```java
class Solution {
    public boolean exist(char[][] board, String word) {
        if(board == null || board.length == 0 || board[0].length == 0 ) {
            return false;
        }
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                if(dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, int i, int j, String word, int cur) {
        if(cur == word.length()) {
            return true;
        }
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length 
        || board[i][j] != word.charAt(cur)) {
            return false;
        }
        char c = board[i][j];
        //改变一下搜索过的地儿的状态，避免重复搜索
        board[i][j] = '.';
        boolean ret1 = dfs(board, i + 1, j, word, cur + 1);
        boolean ret2 = dfs(board, i - 1, j, word, cur + 1);
        boolean ret3 = dfs(board, i, j + 1, word, cur + 1);
        boolean ret4 = dfs(board, i, j - 1, word, cur + 1);
        //对于这个分支的DFS已经完成了，需要回溯还原现场
        board[i][j] = c;
        return ret1 || ret2 || ret3 || ret4;
    }
}
// ```
// 一提交，给👴返回一个超时的❌，然后再一看case，发现一个这样的case：
// ```java
[["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a"],["a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","a","b"]]
"baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
// ```
// 👴做到这的时候怒了，这不是在坑👴？然后仔细分析一下，之前的代码的确还能再优化啊。我在dfs的时候，如果已经找到一个正确的路径了，换句话说已经得到结果了，其实就没必要继续DFS了，直接返回结果即可。**这就是剪枝**。
// 给一下官方的说法：剪枝，就是减小树的规模，尽早排除搜索树中不必要的分支的一种手段（DFS其实逻辑上是对应一棵搜索树的，相信大🔥都知道吧，这都不知道建议先看看DFS的理论再刷题）

// ### 终于AC，👏🎉
// 再原来代码基础上加上剪枝，👴终于AC了，如下：

// ```java
class Solution {
    //用于标记是否已经找到了解
    private boolean flag;

    public boolean exist(char[][] board, String word) {
        if(board == null || board.length == 0 || board[0].length == 0 ) {
            return false;
        }
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length; j++) {
                if(dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, int i, int j, String word, int cur) {
        if(cur == word.length()) {
            flag = true;
            return true;
        }
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length 
                || board[i][j] != word.charAt(cur)) {
            return false;
        }
        //如果没有找到解，则继续DFS
        if(!flag) {
            char c = board[i][j];
            board[i][j] = '.';
            boolean ret1 = dfs(board, i + 1, j, word, cur + 1);
            boolean ret2 = dfs(board, i - 1, j, word, cur + 1);
            boolean ret3 = dfs(board, i, j + 1, word, cur + 1);
            boolean ret4 = dfs(board, i, j - 1, word, cur + 1);
            board[i][j] = c;
            return ret1 || ret2 || ret3 || ret4;
        }else {
            //找到解了，直接结束DFS并返回，这就是剪枝
            return true;
        }
    }
}
// ```
// 希望对大🔥有帮助，如果有对回溯和剪枝甚至DFS都有疑问的👶👶👧👧，建议首先学一下理论。