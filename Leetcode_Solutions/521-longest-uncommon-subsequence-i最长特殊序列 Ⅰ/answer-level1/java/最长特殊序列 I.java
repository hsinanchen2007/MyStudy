#### 方法一：暴力解法 【超出时间限制】

暴力解法中，生成两个字符串所有的子序列共 $2^n$ 个，将其存储在 hashmap 中，并记录每个子序列出现的次数。然后找出出现次数为 $1$ 的最长子序列。如果不存在这样的子序列，返回 $-1$。 

```java [solution1-Java]
public class Solution {
    public int findLUSlength(String a, String b) {
        HashMap < String, Integer > map = new HashMap < > ();
        for (String s: new String[] {a, b}) {
            for (int i = 0; i < (1 << s.length()); i++) {
                String t = "";
                for (int j = 0; j < s.length(); j++) {
                    if (((i >> j) & 1) != 0)
                        t += s.charAt(j);
                }
                if (map.containsKey(t))
                    map.put(t, map.get(t) + 1);
                else
                    map.put(t, 1);
            }
        }
        int res = -1;
        for (String s: map.keySet()) {
            if (map.get(s) == 1)
                res = Math.max(res, s.length());
        }
        return res;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(2^x+2^y)$，其中 $x$ 和 $y$ 是字符串 $a$ 和 $b$ 的长度，子序列的数量为 $2^x+2^y$。

* 空间复杂度：$O(2^x+2^y)$，共生成 $2^x+2^y$ 个子序列。


#### 方法二：简单解法 【通过】

**算法**

字符串 $a$ 和 $b$ 共有 3 种情况：

* $a=b$。如果两个字符串相同，则没有特殊子序列，返回 -1。

* $length(a)=length(b)$ 且 $a \ne b$。例如：$abc$ 和 $abd$。这种情况下，一个字符串一定不会是另外一个字符串的子序列，因此可以将任意一个字符串看作是特殊子序列，返回 $length(a)$ 或 $length(b)$。

* $length(a) \ne length(b)$。例如：$abcd$ 和 $abc$。这种情况下，长的字符串一定不会是短字符串的子序列，因此可以将长字符串看作是特殊子序列，返回 $max(length(a),length(b))$。

```java [solution2-Java]
public class Solution {
    public int findLUSlength(String a, String b) {
        if (a.equals(b))
            return -1;
        return Math.max(a.length(), b.length());
    }
}
```

**复杂度分析**

* 时间复杂度：$O(min(x,y))$，其中 $x$ 和 $y$ 是字符串 $a$ 和 $b$ 的长度。方法 equals 的时间复杂度为 $min(x,y)$。

* 空间复杂度：$O(1)$，无需额外空间。