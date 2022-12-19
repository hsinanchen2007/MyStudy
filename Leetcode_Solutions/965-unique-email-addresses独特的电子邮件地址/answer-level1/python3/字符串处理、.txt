### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        emails_lis = [i.split("@") for i in emails]
        email_con = []
        for lis in emails_lis:
            lis1 = lis[0].split('+')
            email_fwd = lis1[0].replace('.','') + "@" + lis[1]
            email_con.append(email_fwd)
        return len(set(email_con))



            

```