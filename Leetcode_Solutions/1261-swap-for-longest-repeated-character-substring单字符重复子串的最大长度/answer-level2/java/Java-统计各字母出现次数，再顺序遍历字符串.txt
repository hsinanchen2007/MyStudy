# 思路
先**统计** **各个字符**出现的个数。
然后从左到右顺序遍历：
若上1个字符(`last_ch`)与当前遍历到的字符(`text.charAt(i)`)**相等**时，
计数`count  = count + 1`；
若**不相等**，由于有**1次交换**的机会，说不定当前遍历到的字符(`text.charAt(i)`)的右侧又存在每个字符与`last_ch`相等的连续子串呢？哪怕该子串长度为1也好~因此接下来判断  **当前遍历**到的**字符**(`text.charAt(i)`)的右侧是否存在
字符为`last_ch`的连续子串，有则继续保持`count = count + 1`。

举个例子：`aaabab`，一共有4个`a`，2个`b`。
从左到右开始遍历，当遍历到下标为`3`时，遇到了`1`个`b`，不要紧，继续查看`b`的右侧是否还存在连续的`a`，哪怕这个连续的`a`长度只为`1`也好，多多益善。
很幸运，下标为`3`的`b`右侧刚好有1个连续的`a`(它的长度还真只有`1`)。
此时`count = 3 + 1 = 4`，这个时候就开始利用开头统计的各个字符出现的个数。
已知`a`的个数为`4`，而此时`count`的个数也是`4`，说明已经把所有的`a`都计数出来了，此时只需要将下标为`4`的`a`与`3`的`b`交换位置即可，因此`count = 3 + 1 = 4`

若例子为`aaabaab`，只需要将下标为`5`的`a`跟下标为`3`的`b`交换位置即可，`count = 3 + 2 = 5`。

若例子为`aaababa`，此时`count = 3 + 1 = 4`，`a`的总个数为`5`，说明下标`4`的右侧还存在至少`1`个`a`，因此将 **下标`4`的右侧** 任意1个`a` 与 下标为`3`的`b`交换位置就好，
因此结果为`count = 3 + 1 + 1 = 5`，`3`代表`aaa`，`1`代表`a(下标为4)`，`1`代表`a(下标为7)`。

总而言之，如果`count`个数与该字符的总个数相等，则`count`不用再`+1`了，所有该字符已经被计数出来了；
若`count`个数`<`该字符的总个数，`count`还要再`+1`。

单纯用文字解说也只能解说到这了。

# 代码
```java
class Solution {
    public int maxRepOpt1(String text) {
        int len = text.length();
        int[] ch_count = new int[26];
        //统计26个小写字母各自出现的次数
        for (int i = 0; i < len; ++i)
            ++ch_count[text.charAt(i) - 'a'];
        char last_ch = text.charAt(0);
        int count = 1, res = 1;
        for (int i = 1; i < len; ++i) {
            if (last_ch != text.charAt(i)) {
                int temp_idx = i;
                while (temp_idx + 1 < len && last_ch == text.charAt(temp_idx + 1)) {
                    ++count;
                    ++temp_idx;
                }
                if (ch_count[last_ch - 'a'] > count)
                    ++count;
                res = Math.max(res, count);
                count = 1;
                last_ch = text.charAt(i);
            } else
                ++count;
        }
        if (count > 1 && ch_count[last_ch - 'a'] > count)
            ++count;
        return Math.max(res, count);
    }
}
```