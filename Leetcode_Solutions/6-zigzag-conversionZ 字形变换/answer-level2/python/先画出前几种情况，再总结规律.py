```
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows==1:
           return s
        list1=[]
        for i in range(numRows):
            if i==0 or i==numRows-1 :
                list2 = []
                a = i
                while a in range(len(s)):
                    list2.append(s[a])
                    a += (numRows - 1 ) * 2
                list1.append(list2)

            else:
                list2=[]
                a=i
                t=1
                while a in range(len(s)):
                    list2.append(s[a])
                    if t%2:
                        a+=(numRows-1-i)*2
                    else:
                        a +=  i * 2
                    t+=1
                list1.append(list2)

        res=''
        for item in list1:
            for i in item:
                res+=i
        return res
```
