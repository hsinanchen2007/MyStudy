```
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        res=set()
        for email in emails:
            local,domain=email.split('@')

            idx=local.find('+')
            if idx==-1:
                idx=len(local)

            ls=local[:idx].split('.')
            res.add(''.join(ls)+'@'+domain)

        return len(res)
```
