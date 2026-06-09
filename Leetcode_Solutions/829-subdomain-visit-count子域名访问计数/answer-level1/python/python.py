```
class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        dc = {}
        for s in cpdomains:
            str1,str2 = s.split(" ")
            count = int(str1)
            idx = str2.find(".")
            while idx != -1:
                if str2 in dc:
                    dc[str2] = dc[str2]+count
                else:
                    dc[str2] = count
                str2 = str2[idx+1:]
                idx = str2.find(".")
            if str2 in dc:
                dc[str2] = dc[str2]+count
            else:
                dc[str2] = count
        res = []
        for key,count in dc.items():
            res.append(str(count)+" "+key)
        return res
```