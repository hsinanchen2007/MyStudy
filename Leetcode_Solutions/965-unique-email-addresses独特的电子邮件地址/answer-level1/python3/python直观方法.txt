```
class Solution:
    def numUniqueEmails(self, emails: list):
        ans = []
        for i in range(len(emails)):
            tmp_first = emails[i].split("@")[0].replace(".","")
            tmp_second = emails[i].split("@")[1]
            first = ""
            for j in range(len(tmp_first)):
                if tmp_first[j] != "+":
                    first = first + tmp_first[j]
                else:
                    break
            ans.append(first+"@"+tmp_second)
        return len(set(ans))
```
