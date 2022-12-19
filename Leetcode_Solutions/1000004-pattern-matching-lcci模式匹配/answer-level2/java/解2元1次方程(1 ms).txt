# 思路
简单说就是统计a和b的数量，比如统计到`3`个`a`和`2`个`b`。
然后就是解方程：`3 * str_a.length() + 2 * str_b.length() = value.length()`
其中：`str_a`是指代表`a`的字符串，`str_b`是指代表`b`的字符串，`value`是指`patternMatching(String pattern, String value)`方法的第2个参数。
至于怎么解呢？穷举就完事了。
需要注意的是，str_a或str_b可以为空字符串`""`，同时题目要求：str_a不能与str_b相同。

# 代码
```java
class Solution {
    private char[] global_pattern, global_value;
    private int value_len;

    public boolean patternMatching(String pattern, String value) {
        value_len = value.length();
        if (value_len == 0) return pattern.length() < 2;
        global_pattern = pattern.toCharArray();
        global_value = value.toCharArray();
        int pattern_len = pattern.length();
        if (pattern_len == 0) return false;
        int count_a = 0, count_b = 0;
        for (char ch : global_pattern) {
            if (ch == 'a') ++count_a;
            else ++count_b;
        }
        if (count_a == 0) return single_count(count_b);
        if (count_b == 0) return single_count(count_a);
        return count_a < count_b ? muti_count(count_a, count_b, 'a') : muti_count(count_b, count_a, 'b');
    }

    private boolean single_count(int count) {
        if (value_len % count != 0) return false;
        String base = new String(global_value, 0, value_len / count);
        int base_len = base.length(), idx = base_len;
        while (idx < value_len) {
            if (!check(base, idx)) return false;
            idx += base_len;
        }
        return true;
    }

    private boolean muti_count(int small_count, int big_count, char small_ch) {
        int small_sum = 0;
        search:
        while ((small_sum += small_count) < value_len) {
            int remain = value_len - small_sum;
            if (remain % big_count != 0) continue;
            int big_len = remain / big_count, small_len = small_sum / small_count;
            String small_str = null, big_str = null;
            int value_idx = 0;
            for (char cur_ch : global_pattern) {
                if (cur_ch == small_ch) {
                    if (small_str == null)
                        small_str = new String(global_value, value_idx, small_len);
                    else if (!check(small_str, value_idx)) continue search;
                    value_idx += small_len;
                } else {
                    if (big_str == null)
                        big_str = new String(global_value, value_idx, big_len);
                    else if (!check(big_str, value_idx)) continue search;
                    value_idx += big_len;
                }
            }
            return true;
        }
        return single_count(small_count) || single_count(big_count);
    }

    private boolean check(String str, int value_idx) {
        int idx = 0;
        for (char ch : str.toCharArray())
            if (ch != global_value[value_idx + idx++])
                return false;
        return true;
    }
}
```
