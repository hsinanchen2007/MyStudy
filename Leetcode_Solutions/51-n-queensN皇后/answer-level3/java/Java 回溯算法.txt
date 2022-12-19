之前对递归和回溯一直不熟悉，打算从今天开始把专题攻克一下，搞了好久才想通八皇后问题，差点就要放弃了。
写完这个题的代码感觉好长，想看一下大佬们怎么优化来着，发现我的竟然算短的了，那就献丑了分享一下。

其实回溯过程比较清晰，可以优化的点是校验坐标是否能存放皇后，**可以用斜率为 1 这个特性简化判断**，就不用再分左右斜线来处理。

另外一个点是要考虑什么时候删除字符串。
当我们遍历完一行仍未找到位置放置皇后，说明上一行的皇后需要移动，就需要删除已经存放的上一行的字符串


```java
public class Solution {
    int max;
    int[] position;

    public List<List<String>> solveNQueens(int n) {
        position = new int[n];
        max = n;
        List<List<String>> res = new ArrayList<>();
        // 存储结果中一种情形的列表
        List<String> situation = new ArrayList<>();
        place(0, situation, res);
        return res;
    }

    private void place(int rowN, List<String> situation, List<List<String>> res) {
        if (rowN == max) {
            res.add(new ArrayList<>(situation));// 说明找到一种解，加入 res
            situation.remove(rowN - 1);// 移除最后一个元素，继续向下遍历
            return;
        }
        for (int column = 0; column < max; column++) {
            position[rowN] = column;// 将第 row 行的皇后放置于  position[row] 处
            if (judge(rowN)) {
                // 该位置可以放置,存放该行的情况
                char[] chars = new char[max];
                Arrays.fill(chars, '.');
                chars[position[rowN]] = 'Q';
                situation.add(new String(chars));
                place(rowN + 1, situation, res);//继续放下一行的皇后
            }
        }
        // 如果遍历完该行未找到位置，说明上一行的皇后需要继续向右移，删除上一行中已经放入 situation 的字符串
        if (rowN != 0) {
            situation.remove(rowN - 1);
        }
    }

    private boolean judge(int rowN) {
        // 遍历已经摆放过皇后的行
        for (int row = 0; row < rowN; row++) {
            // 如果 (row,position[row]) 于 (rowN,position[rowN]) 位于一列或者两点斜率为 1，则不能放置
            if (position[row] == position[rowN] || rowN - row == Math
                    .abs(position[rowN] - position[row])) 
                return false;
        }
        return true;
    }
}
```
