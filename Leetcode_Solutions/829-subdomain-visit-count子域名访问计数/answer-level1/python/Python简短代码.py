split函数可以指定最大切割次数，正好可以应用在本题：
```
# 不指定次数则切割所有
"google.mail.com".split('.') 
# ['google', 'mail', 'com'] 
```
长度为3， 正好对应了需要统计的域名个数:
1. google.mail.com
2. mail.com
3. com

而上面的三个单词，正好可以通过指定最大切割次数来获得(最后一个值)：
```
In [41]: "google.mail.com".split('.', 0)
Out[41]: ['google.mail.com']

In [38]: "google.mail.com".split('.', 1)
Out[38]: ['google', 'mail.com']

In [39]: "google.mail.com".split('.', 2)
Out[39]: ['google', 'mail', 'com']
```


代码如：
```
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        if not cpdomains:
            return []
        
        res = {}
        for case in cpdomains:
            time, domain = case.split()
            length = len(domain.split('.'))
            for num in range(length):
                dm = domain.split('.', num)[-1]
                res[dm] = res.get(dm, 0) + int(time)
        return [str(v)+' '+k for k, v in res.items()]

```