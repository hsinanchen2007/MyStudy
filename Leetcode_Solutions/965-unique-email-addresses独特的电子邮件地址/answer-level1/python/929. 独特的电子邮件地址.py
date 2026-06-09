- 解构
- list/string.split('匹配内容')
- string.replace('旧', '新')
```
class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        S = set()
        for i in emails:
            name, domain = i.split('@')
            S.add(name.split('+')[0].replace('.', '') + '@' + domain)
        return len(S)
```

- 执行用时 :48 ms, 在所有 Python 提交中击败了83.97%的用户