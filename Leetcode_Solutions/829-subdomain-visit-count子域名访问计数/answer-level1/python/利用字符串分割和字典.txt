```
class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        d = {}
        for s in cpdomains:
            c, domain = s.split(' ')
            c = int(c)
            d[domain] = c+d.get(domain, 0)
            t, domain = domain.split('.', 1)
            d[domain] = c+d.get(domain, 0)
            domain = domain.split('.')
            if len(domain)>1:
                d[domain[-1]] = c+d.get(domain[-1], 0)
        ans = []
        for a,b in d.items():
            s = str(b)+' '+a
            ans.append(s)
        return ans
```

