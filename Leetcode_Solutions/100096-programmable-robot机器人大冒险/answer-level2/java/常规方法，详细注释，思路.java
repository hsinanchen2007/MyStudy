## 分析：
- 由于x和y最多10亿，一个一个遍历肯定不现实。
- 经过思考发现，我们可以找每一个要找的点的前一行或前一列的最后一个。
- 比如终点为`(x, y)`，我们可以找到x-1或者y-1时的最后一个位置。
- 然后再遍历一遍就能判断是否经过该点。因为`command`至少有一个U和R。

## 代码：
```java
class Solution {
    public boolean robot(String command, int[][] obstacles, int x, int y) {
        int dx = 0, dy = 0;
        char[] cmd = command.toCharArray(); // 把String转为数组，方便遍历。
        for (char c : cmd) { // 算出up和right各有多少个。
            if (c == 'U') dy++;
            else dx++;
        }
        int ans = isPassed(cmd, x, y, dx, dy); // 拿到走到终点的次数。
        // 先看isPassed函数再往下看。
        /*
            为什么isPassed要拿到走的总次数而不直接返回true或false呢
            比如你发现有一个obstacle是经过的，那么最终答案并不一定是false，
            因为如果终点在这个点的前面，那么机器人根本不会走到那个点。答案是true。
        */
        if (ans == -1) return false; // 终点都没经过，肯定false
        for (int[] obstacle : obstacles) {
            int cnt = isPassed(cmd, obstacle[0], obstacle[1], dx, dy);
            if (cnt != -1 && cnt < ans) return false; 
            //不等于-1，说明经过了，然后再看这个点和终点哪个次数多。ans多，说明这个点在ans前面，返回false。
        }
        return true;
    }
    // 判断是否经过该点，经过返回走的次数，没经过返回-1。
    public int isPassed(char[] cmd, int x, int y, int dx, int dy) {
        int round = Math.min(x / dx, y / dy); // 计算走到第x-1或y-1层需要多少轮
        int cnt = cmd.length * round;  // 前几轮的总次数
        dx *= round; dy *= round; // 在第x-1或y-1层时的位置。
        if (dx == x && dy == y) return cnt; // 正好就是要找的点，直接返回。
        for (char c : cmd) { // 遍历第x层或y层，如果经过，那么答案一定会遍历到。
            if (c == 'U') dy++; // 要按command的顺序走
            else dx++;
            cnt++; // 不要忘了每遍历一次，次数都要加1
            if (dx == x && dy == y) return cnt; // 一旦找到，直接返回所需要的次数。
        }
        return -1;
    }
}
```