存在以下几种情况：
1）pattern和value都为空，返回True
2）仅pattern为空： 返回False
3）仅value为空，这时候分两种情况：如果pattern中只存在a或者b一种，那么令a或者b为空，符合条件，返回True；否则，由于不同pattern不能表示同一字符串，返回False
4）都不为空的情况下：如果pattern中只有a或者b一种，那意味这value全由一种字符串构成。它需满足以下两个条件：首先，value的长度需要被pattern的长度整除；其次，value中的每一个字符串需要都是a，根据value长度和pattern长度很容易计算出a的长度，然后顺次取出看是否相同即可。
5）如果pattern中同时含有a和b，也有两种情况。第一种，其中一个pattern只有一个，假设a只有一个，那么只需要令a= value， b=“”,即可，所以直接返回True
6）另一种情况，同时含有a， b且个数都大于1。这时候，我们先统计pattern中a, b各有多少个，然后遍历a的所有可能长度，对于某个确定的a的长度，结合a的个数和b的个数以及value的长度，我们即可以确定b的长度。这时候需要满足以下条件：首先b的长度也必须是整数；其次，value只能由a， b结合而成。

```

class Solution:
    def patternMatching(self, pattern: str, value: str) -> bool:
        if not value and not pattern: return True
        if not pattern: return False
        if not value:
            if len(pattern)==1: return True
            else: return False
        if len(set(pattern))==1: # 如果只有一种pattern
            if len(value)%len(pattern)!=0:
                return False
            length = len(value) // len(pattern)
            return all([value[i:i+length]==value[0:length] for i in range(0, len(value),length)])

        if pattern.count('a')==1 or pattern.count('b')==1:# 两种pattern但是其中一种只有一个，只需要另这个为value，另外一个为空即可
            return True
        
        cnt_a = pattern.count('a')
        cnt_b = pattern.count('b')
        for i in range(len(value)//cnt_a): # 遍历a的所有可能长度
            remain = len(value) - i * cnt_a 
            if remain % cnt_b != 0:
                continue
            j = remain // cnt_b
            set_a = set()
            set_b = set()
            p = 0
            for s in pattern:
                if s=='a':
                    set_a.add(value[p:p+i])
                    p += i
                else:
                    set_b.add(value[p:p+j])
                    p += j
            if len(set_a)==len(set_b)==1:
                return True
        return False    
```
