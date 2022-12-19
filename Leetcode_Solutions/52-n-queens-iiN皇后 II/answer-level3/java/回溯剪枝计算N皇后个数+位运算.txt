# 集合存储
**思路: 枚举每一层皇后所在的位置**
**剪枝: 只要纵轴、左斜面、右斜面存在皇后就不生成皇后**
**重点: 利用下标r、c判断当前位置所在的左、右斜角**
```
class Solution {
    //统计数量
    private int count;
    public int totalNQueens(int n) {
        queenHelper(0, n, new HashSet<>(), new HashSet<>(), new HashSet<>());
        return count;
    }
    private void queenHelper(int level, int n, Set<Integer> col, Set<Integer> lb, Set<Integer> rb) {
        //所有层生成完毕
        if (level == n) {
            ++count;
        } else {
            //生成该层的所有可能性
            for (int i = 0; i < n; ++i) {
                //左斜角、右斜角、列不存在皇后时生成皇后
                if (!col.contains(i) && !lb.contains(level - i) && !rb.contains(level + i)) {
                    col.add(i);lb.add(level - i);rb.add(level + i);
                    queenHelper(level + 1, n, col, lb, rb);
                    col.remove(i);lb.remove(level - i);rb.remove(level + i);
                }
            }
        }
    }
}
```
时间复杂度:O(n!)
空间复杂度:O(n)
# 位存储
**思路: 集合的插入、删除开销很大, 可以利用位来存储列、左斜角、右斜角信息**
**存储列信息: **
1. 将棋盘的每一行看作是二进制的位, 初始化时全为0
2. 每次填入皇后视为将该位置为1, 并传递给下一行
3. 下一行通过查看对应列的值判断是否占用
**存储左斜角、右斜角信息: **
与存储列信息相同, 将左、右斜角的下标视为列下标进行同样操作即可
```
class Solution {
    private int cnt;
    public int totalNQueens(int n) {
        helper(0, n, 0, 0, 0);
        return cnt;
    }
    private void helper(int level, int n, int cols, int lb, int rb) {
        if (level == n) {
            ++cnt;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (((1 << i) & cols) == 0 && ((1 << (level + i)) & lb) == 0 && ((1 << (level - i + n - 1)) & rb) == 0) {
                helper(level + 1, n, cols | (1 << i), lb | (1 << (level + i)), rb | (1 << (level - i + n - 1)));
            }
        }
    }    
}
```
# 最优版本
最优版本的位运算更多, 非常巧妙, 需要理解
```
class Solution {
    private int cnt;
    public int totalNQueens(int n) {
        dfs(0, 0, 0, 0, n);
        return cnt;
    }

    private void dfs(int levels, int cols, int lb, int rb, int n) {
        if (levels == n) {
            ++cnt;
        } else {
            //0表示空位, 取反变成1方便位操作
            int p = ~(cols | lb | rb) & ((1 << n) -1);
            while (p != 0) {
                int last = p & -p;
                dfs(levels + 1, cols | last, (lb | last) << 1, (rb | last) >> 1, n);
                p = p & (p - 1);
            }
        }
    }
}
```
