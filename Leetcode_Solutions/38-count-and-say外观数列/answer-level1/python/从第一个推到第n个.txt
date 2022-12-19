```
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        tempstr="1"
        for _ in range(n-1):
            num = 1 #记录出现的次数
            tempstr2 = ""
            j = 0
            while j < len(tempstr):
                while j+1<len(tempstr) and tempstr[j] == tempstr[j+1]:
                    num +=1
                    j+=1
                tempstr2 += str(num)
                tempstr2 += tempstr[j]
                num = 1
                j+=1

            tempstr = tempstr2

        return tempstr



sol = Solution()
print(sol.countAndSay(6))
```
