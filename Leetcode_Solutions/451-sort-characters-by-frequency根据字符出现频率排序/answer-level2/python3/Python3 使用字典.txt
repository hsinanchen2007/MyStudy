#### 使用字典实现
主要思路：
1. 使用字典记录字符的出现次数`{key:value}={字符:出现次数}`
2. 利用列表`l1`按顺序记录字符,`l1[value]=key`。
3. 倒序遍历`l1`,实现降序排列

代码如下：
```
from collections import Counter
class Solution:
    def frequencySort(self, s: str) -> str:
        dic = dict(Counter(s))# 使用Counter函数迅速生成字典{字母:出现次数}
        l1 = ['' for e in range(len(s)+1)]
        for key,value in dic.items():
            l1[value] += key * value# 将key*value填入l1中索引等于value的位置
        res = ''
        for i in range(-1,-len(l1)-1,-1):# 对l1倒序遍历，即为排序后的字符
            if l1[i] != '':
                res += l1[i]
        return res
```

![白色背景关注.jpg](https://pic.leetcode-cn.com/47d1b5430e869ed420bb0c6e8a90250773528ccf1bf6d4d43aef80dd326eeef9-%E7%99%BD%E8%89%B2%E8%83%8C%E6%99%AF%E5%85%B3%E6%B3%A8.jpg)
