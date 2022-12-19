真实在超时的边缘徘徊，本来没有访问记录的，大概都是30%+的时间，把访问都记录了，一下就冲到了80%+了。

![image.png](https://pic.leetcode-cn.com/5624da444ab2f1ed8b3b2e46ad09406f47b4dcda01ce86bd866ef0279f4bdcf3-image.png)


```python []
class WordFilter:

    def __init__(self, words: List[str]):
        self.pre_d = {}         #前缀字典树
        self.words = words
        self.p_f_visit = {}     #前后缀记录，记录对应的答案
        self.p_visit = {}       #前缀记录，记录前缀对应单词降序排序的坐标
        for i, word in enumerate(words):
            t = self.pre_d
            for c in word:
                if c not in t:
                    t[c] = {}
                t = t[c]
            t['val'] = i        #前缀字典记录值
        
    def f(self, prefix: str, suffix: str) -> int:
        if (prefix, suffix) in self.p_f_visit:  #重复访问的直接返回
            return self.p_f_visit[(prefix, suffix)]
        if prefix not in self.p_visit:          #未访问过的前缀就把对应坐标降序生成
            t = self.pre_d
            for c in prefix:    #首先检索前缀是否存在于字典
                if c not in t:
                    return -1
                t = t[c]
            pre_list = []
            def pre_dfs(d):     #深搜生成坐标
                if 'val' in d:
                    pre_list.append(d['val'])
                for t in d:
                    if t != 'val':
                        pre_dfs(d[t])
            pre_dfs(t)
            self.p_visit[prefix] = sorted(pre_list, reverse = True)
        for i in self.p_visit[prefix]:
            if self.words[i].endswith(suffix):  #后缀匹配
                self.p_f_visit[(prefix, suffix)] = i
                return i
        self.p_f_visit[(prefix, suffix)] = -1
        return -1
```
