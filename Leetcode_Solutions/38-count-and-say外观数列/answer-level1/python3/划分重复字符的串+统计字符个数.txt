思路：
1.将字符串s划分为若干个字串，每个子串只包含一个字符，该字符重复构成子串
2.将每一个子串转换为“len(字串)+字串中的重复字符”的格式得到字符串ss
3.将所有子串对应的ss字符串合并，即得到对字符串s的描述
4.迭代步骤1-3
代码：
```
    def countAndSay(self, n: int) -> str:
        def num_word(s):
            return str(len(s))+s[0]
        def split(s):
            start=0
            end=0
            result=''
            for i in range(1,len(s)):
                if s[i]!=s[i-1]:
                    end=i
                    temp=s[start:end]
                    result+=num_word(temp)
                    start=i
            temp=s[start:]
            result+=num_word(temp)
            return result
        if n==1:
            return '1'
        s='1'
        for i in range(n-1):
            s=split(s)
        return s

```
