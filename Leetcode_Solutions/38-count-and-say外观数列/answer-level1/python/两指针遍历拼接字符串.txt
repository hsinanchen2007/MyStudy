### 解题思路
用两个指针遍历
拼接字符串

### 代码

```python
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        def Saynum(s):
            if s=='1':
                return "11"
            res=""
            n=len(s)
            front=0
            while front<n:
                back=front+1
                while back<n and s[back]==s[front]:
                    back+=1
                res+=str(back-front)
                res+=s[front]
                front=back
            return res

        res="1"
        for _ in range(n-1):
            res=Saynum(res)
        return res

                


            
```