本质上是分组，把相同的分为一组，计算每组的长度。于是列表成为'每组长度'+'每组组别'+...，以此类推。

然后递归求解，初始输入的为1，如果是n，循环n-1次就可以了。

```python
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        self.num=1
        def one_two(n):
            start=0
            li=[]
            s=str(n)+'0'
            for i in range(0,len(s)):
                if s[i]!=s[i+1]:
                    delta=s[start:i+1].count(s[start])
                    li.append(str(delta))
                    li.append(s[start])
                    start=i+1
                if s[i+1]=='0':
                    break
            return int("".join(li))
        while n!=1:
            self.num=one_two(self.num)
            n-=1
        return str(self.num)
```

字符串后面加一个“0”是防止溢出，也可以表示最末尾的值。