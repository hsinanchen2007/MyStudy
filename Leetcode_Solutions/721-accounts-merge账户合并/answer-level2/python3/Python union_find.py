```python
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        # Use Union find
        dic = {}
        def find(x):
            dic.setdefault(x, x)
            if x != dic[x]:
                dic[x] = find(dic[x])
            return dic[x]

        def union(a, b):
            dic[find(a)] = find(b)

        res = collections.defaultdict(list)
        email_to_name = {}
        for account in accounts:
            for i in range(1, len(account)):
                email_to_name[account[i]] = account[0]
                if i < len(account) - 1: union(account[i], account[i + 1])
        for email in email_to_name:
            res[find(email)].append(email)
        
        return [[email_to_name[value[0]]] + sorted(value) for value in res.values()]

```
