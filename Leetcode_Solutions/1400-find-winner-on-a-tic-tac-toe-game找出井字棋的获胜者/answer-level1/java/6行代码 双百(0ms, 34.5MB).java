### 解题思路
moves数组结束可能有3种情况 Draw, Pending, A/B获胜
Draw和Pending一样 都是没分出胜负 区别在于是否已经不能再走下一步了
所以我们直接判断判断最后一手 最后一手要么是导致某人获胜要么还是未分出胜负
取出最后一人的前几手与最后一手进行比较 如果有直线那么就是其获胜 反之未分出胜负


### 代码

```java
class Solution {
    public String tictactoe(int[][] moves) {
        // 我们只需要判断最后一个即可
        int end = moves.length - 1;
        for (int i = end - 2; i > 1 ; i -= 2) 
            // 判断3个点是否在一条线 x1*y2 = x2*y1
            for (int j = i - 2; j >= 0; j -= 2)
                if ((moves[i][0] - moves[end][0]) * (moves[j][1] - moves[end][1]) == 
                    (moves[j][0] - moves[end][0]) * (moves[i][1] - moves[end][1]))
                    return end % 2 == 0 ? "A" : "B";
        return moves.length == 9 ? "Draw" : "Pending";
    }
}
```