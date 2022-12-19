``` python []
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        sett = set()
        for s in emails:
            s = s.split('@')
            s = s[0].replace('.', '') + '@' + s[1]
            s = re.sub(r'\+.*@', '@', s)
            sett.add(s)
        return len(sett)
```