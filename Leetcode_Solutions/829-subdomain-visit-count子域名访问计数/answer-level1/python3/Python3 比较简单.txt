![捕获11.PNG](https://pic.leetcode-cn.com/8ec581adaac0823fbd3d45a0905611dbff27e6cba283f7a2b077e1581f9e0240-%E6%8D%95%E8%8E%B711.PNG)
```
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        d = {}
        for domain in cpdomains:
            times = int(domain.split(' ')[0])
            domain_list = domain.split(' ')[1].split('.')
            for i in range(len(domain_list)):
                domain_real = '.'.join(domain_list[i:])
                if domain_real not in d:
                    d[domain_real] = times
                else:
                    d[domain_real] += times
        return ['%s %s'%(val,key) for key,val in d.items()]
```