#### 方法：自定义排序

**思路和算法**

我们按照指定的自定义顺序进行排序，而不是按默认顺序排序。

排序规则如下：

* 字母日志先于数字日志；
* 字母日志按字母数字顺序排列，先按内容排序，再按标识符排序；
* 数字日志的顺序保持不变。

这些想法很容易转化为代码。

```Java [solution1]
class Solution {
    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, (log1, log2) -> {
            String[] split1 = log1.split(" ", 2);
            String[] split2 = log2.split(" ", 2);
            boolean isDigit1 = Character.isDigit(split1[1].charAt(0));
            boolean isDigit2 = Character.isDigit(split2[1].charAt(0));
            if (!isDigit1 && !isDigit2) {
                int cmp = split1[1].compareTo(split2[1]);
                if (cmp != 0) return cmp;
                return split1[0].compareTo(split2[0]);
            }
            return isDigit1 ? (isDigit2 ? 0 : 1) : -1;
        });
        return logs;
    }
}
```

```Python [solution1]
class Solution(object):
    def reorderLogFiles(self, logs):
        def f(log):
            id_, rest = log.split(" ", 1)
            return (0, rest, id_) if rest[0].isalpha() else (1,)

        return sorted(logs, key = f)
```

**复杂度分析**

* 时间复杂度：$O(\mathcal{A}\log \mathcal{A})$，其中 $\mathcal{A}$ 是 `logs` 的内容总和。

* 空间复杂度：$O(\mathcal{A})$。