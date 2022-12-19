#### 方法一：模拟

我们首先判断 `S` 是邮箱还是电话号码。显然，如果 `S` 中有字符 `'@'`，那么它是邮箱，否则它是电话号码。

如果 `S` 是邮箱，我们将 `S` 的 `'@'` 之前的部分保留第一个和最后一个字符，中间用 `'*****'` 代替，并将整个字符串转换为小写。

如果 `S` 是电话号码，我们只保留 `S` 中的所有数字。首先将最后 `10` 位本地号码变成 `'***-***-abcd'` 的形式，再判断 `S` 中是否有额外的国际号码。如果有，则将国际号码之前添加 `'+'` 号并加到本地号码的最前端。

```Java [sol1]
class Solution {
    public String maskPII(String S) {
        int atIndex = S.indexOf('@');
        if (atIndex >= 0) { // email
            return (S.substring(0, 1) + "*****" + S.substring(atIndex - 1)).toLowerCase();
        } else { // phone
            String digits = S.replaceAll("\\D+", "");
            String local = "***-***-" + digits.substring(digits.length() - 4);
            if (digits.length() == 10) return local;
            String ans = "+";
            for (int i = 0; i < digits.length() - 10; ++i)
                ans += "*";
            return ans + "-" + local;
        }
    }
}
```

```Python [sol1]
class Solution(object):
    def maskPII(self, S):
        if '@' in S: #email
            first, after = S.split('@')
            return "{}*****{}@{}".format(
                first[0], first[-1], after).lower()

        else: #phone
            digits = filter(unicode.isdigit, S)
            local = "***-***-{}".format(digits[-4:])
            if len(digits) == 10:
                return local
            return "+{}-".format('*' * (len(digits) - 10)) + local
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是字符串 `S` 的长度。

* 空间复杂度：$O(1)$。