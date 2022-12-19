记录下每个字符串中的不同字符及数目，比较一下
```
    def isAnagram(s: str, t: str) -> bool:
        def dic(st):
            d={}
            li=list(set(st))
            for i in range(len(li)):
                d[li[i]]=st.count(li[i])
            return d
        return dic(s)==dic(t)
```
![QQ截图20191111105051.png](https://pic.leetcode-cn.com/7f6d46f7e08f985099976928ae3b1e1e4a66c4e4c2f4d1e5beab99b3e25a6ec5-QQ%E6%88%AA%E5%9B%BE20191111105051.png)
