
![image.png](https://pic.leetcode-cn.com/ce9abf4e7fee82210d3e8ab88906ee59be3aaf0c1e349b405fa8ee0d3368ae74-image.png)

因为该题在 bfs 探索中，看到题目直接奔 bfs 思路。提交后发现耗时短的代码有新思路，优化部分逻辑。

- 寻找可达目标数字的 8 个状态
- 可达目标的数字排除掉死亡数字
- 剩余的即是合法数字，从 0000 到这些合法的数字旋转最少次数即为结果

```java
// 解题思路：寻找目标数对应的 8 个状态
class Solution {
    public int openLock(String[] deadends, String target) {
        final List<String> deals = Arrays.asList(deadends);
        if (deals.contains("0000")) return -1;

        final List<String> options = new ArrayList<>(); // 可达目标数的 8 个状态
        for (int i = 0; i < 4; i++) {
            char[] cs = target.toCharArray();
            char c = cs[i];
            cs[i] = (char) ((c - 48 + 1) % 10 + 48);
            options.add(new String(cs));
            cs[i] = (char) ((c - 48 + 9) % 10 + 48);
            options.add(new String(cs));
        }

        options.removeAll(deals); // 可达数字中移除死亡数字
        if (options.isEmpty()) return -1; // 可达目标数的 8 个状态都在死亡数字中直接返回

        int step = Integer.MAX_VALUE;
        for (String option : options) { // 判断可达状态中最短转动次数
            int curStep = 1;
            char[] cs = option.toCharArray();
            for (int i = 0; i < 4; i++) {
                int num = cs[i] - 48; // '0' 为 48 减少隐式转换
                if (num > 5) curStep += 10 - num; // 判断正转，倒转
                else curStep += num;
            }
            step = Math.min(curStep, step); // 记录最小旋转次数
        }
        return step;
    }
}
```