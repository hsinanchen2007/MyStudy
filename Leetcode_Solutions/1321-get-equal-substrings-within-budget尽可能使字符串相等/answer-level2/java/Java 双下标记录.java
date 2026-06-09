首先把问题转换成如下形式：
一个数组，其长度等于字符串 `s` 和 `t` 的长度（`s` 和 `t` 长度相同），数组中的每个元素等于 `s` 和 `t` 在该位置的字符的差的绝对值。计算该数组的最长子数组，满足该子数组的元素和不超过 `maxCost`。
从头开始遍历数组，记录 `begin` 和 `end` 两个下标，初始值都是 $0$，计算两个下标之间的数组元素和，当元素和不超过 `maxCost` 时，往后移动 `end`，更新最大长度，如果元素和超过 `maxCost`，则往后移动 `begin` 直到元素和不超过 `maxCost`。遍历完数组即可得到最大的子数组长度。
```java [-Java]
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int length = s.length();
        int[] differences = new int[length];
        for (int i = 0; i < length; i++)
            differences[i] = Math.abs(s.charAt(i) - t.charAt(i));
        int begin = 0, end = 0;
        int ret = 0;
        int sum = differences[0];
        if (sum <= maxCost)
            ret = 1;
        while (end < length - 1) {
            sum += differences[++end];
            while (sum > maxCost)
                sum -= differences[begin++];
            ret = Math.max(ret, end - begin + 1);
        }
        return ret;
    }
}
```
