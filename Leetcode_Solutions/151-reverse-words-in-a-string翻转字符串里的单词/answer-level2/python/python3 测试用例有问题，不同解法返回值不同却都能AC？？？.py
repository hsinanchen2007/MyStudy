看着好像很简单，为什么这么难呢
到底要这么处理\xa0
题目说明明明说了
`A word is defined as a sequence of non-space characters.`
<br/>
```python3
    def reverseWords(self, s: str) -> str:
        re = " ".join(reversed(s.split()))
        return re

    def reverseWords2(self, s: str) -> str:
        s = s.strip()                               # 删除首尾空格
        i = j = len(s) - 1
        res = []
        while i >= 0:
            while i >= 0 and s[i] != ' ': i -= 1    # 搜索首个空格
            res.append(s[i + 1: j + 1])             # 添加单词
            while s[i] == ' ': i -= 1               # 跳过单词间空格
            j = i                                   # j 指向下个单词的尾字符
        return ' '.join(res)
```
  
<br/>
上面2个都可以AC，
但是测试发现同一个字符串，却可以得到不同的返回值，那测试用例到底是怎么写的呢？？？
![14.jpg](https://pic.leetcode-cn.com/7d9bb3610e6607210f733c3e0ab6fcc1751807a5cc78488b86f2800f37f3d984-14.jpg)
<br/>
下面带这些字符串照个CT  
<br/>
![13.png](https://pic.leetcode-cn.com/2e6821e12e1e22f743483c6a222649d2dbc18b5a4a5156c360de276c4905d4d3-13.png)
<br/>
可以看到红框中的debug信息中，有些\xa0伪装成了“空格”，就是这些东西导致的结果不一致
但是测试用例到底怎么写的呢，尤其是”a good   example“，2个函数得到的返回值长度都不一样
正确姿势大概是这样，
```
    def reverseWords2(self, s: str) -> str:
        s = s.strip(' ')                               # 指定去除空格
        i = j = len(s) - 1
        res = []
        while i >= 0:
            while i >= 0 and s[i] != ' ': i -= 1    
            res.append(s[i + 1: j + 1])             
            while s[i] == ' ': i -= 1               
            j = i                                   
        return ' '.join(res)
```
<br/>
![15.png](https://pic.leetcode-cn.com/a4f2c17bc56f13b83cc57c961e5f1f71f4d633c5293a1c34266d11bcca18a3f9-15.png)
<br/>
差异的原因是s.strip(),默认移除 ASCII 空白符
移除空格需要指定s.strip(' ')