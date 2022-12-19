**方法一：找规律**
思路：
    由题有效括号字符串就是指成对出现的"("和")"。

题目要求将有效括号字符串 seq 拆分成 A 和 B ，使得 max(depth(A), depth(B)) 的可能取值最小。
    其实就是要重新组合 seq 为新的有效括号字符串，使得新有效括号字符串嵌套深度最小。

因为两个相同方向的括号相连（无论左右）就代表嵌套深度 +1 ，
    所以只要遇到相同方向括号就拆分，最终得到 A + B 的有效括号字符串嵌套深度最小。
```
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int len = seq.length();
        // 创建数组记录原字符串每个字符在拆分后的归属。
        int[] ans = new int[len];
        // 默认第一个括号 "(" 属于 A 。
        ans[0] = 0;
        // 从字符串第二位开始遍历归属。
        for (int i = 1; i < len; i++) {
            // 记录当前括号前一个括号方向。
            char curr = seq.charAt(i - 1);
            // 只要当前括号和前一个方向不同，就分给同一组。
            ans[i] = seq.charAt(i) != curr ? ans[i - 1] : 1 - ans[i - 1];
        }
        return ans;
    }
}
```

**方法二：找奇偶**
思路：
将有效括号字符串中 "(" 按照奇偶分配给 A、B ，对应的 ")" 则按偶奇分配。
```
public class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        // 创建数组记录原字符串每个字符在拆分后的归属。
        int[] ans = new int [seq.length()];
        // 数组角标指针。
        int i = 0;
        for(char c: seq.toCharArray()) {
            ans[i++] = c == '(' ? i & 1 : ((i + 1) & 1);
        }
        return ans;
    }
}
```
