#### 哈希映射：

对于包含一个 `.` 的域名 `x.y`，我们需要统计的是 `x.y` 和 `y`；对于包含两个 `.` 的域名 `a.b.c`，我们需要统计的是 `a.b.c`，`b.c` 和 `c`。在统计这些字符串时，我们可以使用哈希映射（HashMap）。统计结束之后，我们遍历哈希映射并输出结果。

```Java [sol1]
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> counts = new HashMap();
        for (String domain: cpdomains) {
            String[] cpinfo = domain.split("\\s+");
            String[] frags = cpinfo[1].split("\\.");
            int count = Integer.valueOf(cpinfo[0]);
            String cur = "";
            for (int i = frags.length - 1; i >= 0; --i) {
                cur = frags[i] + (i < frags.length - 1 ? "." : "") + cur;
                counts.put(cur, counts.getOrDefault(cur, 0) + count);
            }
        }

        List<String> ans = new ArrayList();
        for (String dom: counts.keySet())
            ans.add("" + counts.get(dom) + " " + dom);
        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def subdomainVisits(self, cpdomains):
        ans = collections.Counter()
        for domain in cpdomains:
            count, domain = domain.split()
            count = int(count)
            frags = domain.split('.')
            for i in xrange(len(frags)):
                ans[".".join(frags[i:])] += count

        return ["{} {}".format(ct, dom) for dom, ct in ans.items()]
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组 `cpdomains` 的长度，这里假设 `cpdomains` 中每个元素的长度都是常数级别的。

* 空间复杂度：$O(N)$，用于存储哈希映射。