```
class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        result = []
        for i in emails:
            pre, end = i.split('@')
            pre_1 = pre.split('+',1)[0]     
            pre_2 = pre_1.replace('.','')
            temp = pre_2 + '@'+ end
            print(temp)
            if temp not in result:
                result.append(temp)
        return len(result)
```
