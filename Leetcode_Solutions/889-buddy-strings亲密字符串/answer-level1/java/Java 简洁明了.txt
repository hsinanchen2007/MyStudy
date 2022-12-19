#### *如果满足亲密字符串，前提如下*
- `A == B` : *A 中`至少有2个`重复元素*
- `A != B` : *AB中`只能有2对`不同索引 (元素互换相等)*

——————————————————————————————————————————————————

```java
class Solution {
    public boolean buddyStrings(String A, String B) {
        int len = A.length();
        if (len < 2 || len != B.length())
            return false;

        // A == B
        if (A.equals(B)) {
            Set<Character> set = new HashSet<>(len);
            for (int i = 0; i < len; i++) {
                if (set.contains(A.charAt(i)))
                    return true;
                else
                    set.add(A.charAt(i));
            }
            return false;
        }

        // A != B
        // 不等元素的索引
        int pre = 0, next = 0;
        // 这里可以优化成双指针，前后共同判断(不太方便理解，放后边了)
        for (int i = 0; i < len; i++) {
            if (A.charAt(i) == B.charAt(i))
                continue;
            if (pre > 0 && next > 0)
                return false;
            if (pre == 0)
                pre = i;
            else
                next = i;
        }
        if (next == 0)
            return false;
        return A.charAt(pre) == B.charAt(next) && A.charAt(next) == B.charAt(pre);
    }
}
```
————————————————————
`// 优化内容如下：`
```java
        // A != B
        // 不同元素的索引(pre、next最好是负数)
        int pre = -1, next = -1, count = 0;
        for (int i = 0; i < len; i++) {
            if (count > 2)
                return false;
            if (A.charAt(i) != B.charAt(i)) {
                count++;
                if (pre == -1)
                    pre = i;
                else if (next == -1)
                    next = i;
            }
            int tmp = len - 1 - i;
            // 奇数长度的字符串
            if (tmp == i)
                break;
            if (A.charAt(tmp) != B.charAt(tmp)) {
                count++;
                if (pre == -1)
                    pre = tmp;
                else if (next == -1)
                    next = tmp;
            }
            // 偶数长度的字符串
            if (tmp == i + 1)
                break;
        }
        if (count != 2)
            return false;
        return A.charAt(pre) == B.charAt(next) && A.charAt(next) == B.charAt(pre);
```

