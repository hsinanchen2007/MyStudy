### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        num = N
        binaryNum = ""
        while num > 0:
            remainder = num % 2
            num = num // 2
            binaryNum = str(remainder)+binaryNum
        print(binaryNum)

        prevFound = False
        ans = 0
        for i in range(0,len(binaryNum)):
            #print(i)
            if binaryNum[i] == '1' and prevFound == False:
                prev = i
                prevFound = True
                #print('prev = {}'.format(prev))
            if binaryNum[i] == '1':
                ans = max(i-prev,ans)
                prev = i  
                #print('prev = {} |'.format(prev))

        return ans          
            

```