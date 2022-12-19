#### 方法一：规范化表示

对于每个电子邮件地址，我们求出它的规范化表示（即根据 `'.'` 和 `'+'` 的规则进行处理后得到的，本地名称中仅包含小写字母的电子邮件地址）。我们对每一个地址依次进行如下的操作：

* 将电子邮件地址根据 `'@'` 分成本地名称和域名两部分，其中域名部分包含 `'@'`，且不需要进行额外的处理；

* 如果本地名称中有 `'+'`，那么移除 `'+'` 以及它后面出现的所有字符；

* 移除本地名称中的所有 `'.'`；

* 处理完成的本地名称和域名进行连接，得到电子邮件地址的规范化表示。

在得到了所有电子邮件地址的规范化表示后，我们将它们放入集合（set）中，就可以获知不同地址的数目。

```Java [sol1]
class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> seen = new HashSet();
        for (String email: emails) {
            int i = email.indexOf('@');
            String local = email.substring(0, i);
            String rest = email.substring(i);
            if (local.contains("+")) {
                local = local.substring(0, local.indexOf('+'));
            }
            local = local.replaceAll(".", "");
            seen.add(local + rest);
        }

        return seen.size();
    }
}
```

```Python [sol1]
class Solution(object):
    def numUniqueEmails(self, emails):
        seen = set()
        for email in emails:
            local, domain = email.split('@')
            if '+' in local:
                local = local[:local.index('+')]
            seen.add(local.replace('.','') + '@' + domain)
        return len(seen)
```

**复杂度分析**

* 时间复杂度：$O(C)$，其中 $C$ 是电子邮件地址的数目。

* 空间复杂度：$O(C)$。