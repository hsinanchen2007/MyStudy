#### 方法 ： 模拟[Accepted]

**想法**

我们可以模拟每个指令后机器人所在的位置。

**算法**

一开始，机器人在 `(x, y) = (0, 0)`。如果指令是 `'U'`，机器人会走到 `(x, y-1)`，如果指令是 `'R'`，机器人会走到 `(x, y) = (x+1, y)`，以此类推。

```Python []
class Solution(object):
    def judgeCircle(self, moves):
        x = y = 0
        for move in moves:
            if move == 'U': y -= 1
            elif move == 'D': y += 1
            elif move == 'L': x -= 1
            elif move == 'R': x += 1

        return x == y == 0
```

```Java []
class Solution {
    public boolean judgeCircle(String moves) {
        int x = 0, y = 0;
        for (char move: moves.toCharArray()) {
            if (move == 'U') y--;
            else if (move == 'D') y++;
            else if (move == 'L') x--;
            else if (move == 'R') x++;
        }
        return x == 0 && y == 0;
    }
}
```

**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 是`moves` 指令的长度。我们需要遍历字符串一遍。

* 空间复杂度： $O(1)$。在 Java 中，我们字符串数组的长度是 $O(N)$。
