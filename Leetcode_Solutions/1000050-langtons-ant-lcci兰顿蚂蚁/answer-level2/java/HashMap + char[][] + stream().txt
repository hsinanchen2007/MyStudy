# 思路
模拟即可。
HashMap存储走过的路，再用4个int变量存储边界。
关键在于将模拟的坐标  映射到创建的数组下标。

题外话：既然有兰顿蚂蚁，是不是也有贪欲九头蛇大象？无尽猴子？岚切甲壳虫？黑切蛋糕？
![微信图片_20200221000836.png](https://pic.leetcode-cn.com/e34c0626e3c690bb5d85b02ea52e6ee10223ee936d6c850b4f300ed98d2e2b03-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200221000836.png)


# 代码
```java
class Solution {
    private char[] dir_char = new char[]{'R', 'D', 'L', 'U'};
    private int[] position = new int[2];
    private int direction = 0, left_bound = 0, right_bound = 0,
            up_bound = 0, down_bound = 0;  //0 -> 'R', 1 -> 'D', 2 -> 'L', 3 -> 'U'

    public List<String> printKMoves(int K) {
        if (K < 1) return Arrays.asList("R");
        HashMap<List<Integer>, Boolean> map = new HashMap<>();  //true为右，false为左
        while (--K > -1) {
            List<Integer> key = Arrays.asList(position[0], position[1]);
            if (map.containsKey(key)) {
                boolean isRight = map.get(key);
                direction = isRight ? (direction + 1) & 3 : (direction + 3) & 3;
                map.put(key, !isRight);
            } else {
                direction = (direction + 1) & 3;
                map.put(key, false);
            }
            move();
            left_bound = Math.min(left_bound, position[0]);
            right_bound = Math.max(right_bound, position[0]);
            down_bound = Math.min(down_bound, position[1]);
            up_bound = Math.max(up_bound, position[1]);
        }
        char[][] res = new char[up_bound - down_bound + 1][right_bound - left_bound + 1];
        for (char[] row : res)
            Arrays.fill(row, '_');
        for (Map.Entry<List<Integer>, Boolean> entry : map.entrySet()) {
            List<Integer> pos = entry.getKey();
            boolean isWhite = entry.getValue();
            if (!isWhite)
                res[up_bound - pos.get(1)][pos.get(0) - left_bound] = 'X';
        }
        res[up_bound - position[1]][position[0] - left_bound] = dir_char[direction];
        return Arrays.stream(res).map(String::valueOf).collect(Collectors.toList());
    }

    private void move() {
        switch (direction) {
            case 0:
                ++position[0];
                break;
            case 1:
                --position[1];
                break;
            case 2:
                --position[0];
                break;
            default:
                ++position[1];
        }
    }
}
```
