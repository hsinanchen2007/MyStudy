参考题解中c++位运算思路，写出python代码：
1. 直接跳过与target长度不一致的单词。两个单词长度不一样，缩写一定不一样。
2. 运用位运算遍历所有可能的缩写索引组合情况，如果与字典里的单词缩写相同则跳过，否则计算缩写的长度，如果比当前最小长度更小，则更新最小的缩写形式。
3. generateAbbr是帮助函数，接受两个输入：1.target单词，2.list数组。返回单词缩写形式和其长度。
如输入 "apple", [1, 3] 输出 "1p1l1"; 输入 "apple", [2, 3] 输出 "2pl1"。

```
class Solution:
    def generateAbbr(self, target: str, indices):
        if not indices : return str(len(target)), 1
        
        str_, cnt = '', 0
        cur = 0
        for i in indices:
            if i > cur:
                str_ += str(i-cur)
                cnt += 1
            str_ += target[i]
            cnt += 1
            cur = i + 1
        
        if i < len(target)-1:
            str_ += str(len(target) - i - 1)
            cnt += 1
            
        return str_, cnt

    def minAbbreviation(self, target: str, dictionary) -> str:
        n = len(target)
        m = 1 << n
        result, result_cnt = '', float('inf')
        dictionary = [dictionary[i] for i, bool_ in 
                      enumerate(map(lambda x: len(x) == n, dictionary)) if bool_]
        
        if not dictionary : return str(n)
        
        for i in range(m):
            indices = []
            for j in range(n):
                if i & (1 << j):
                    indices.append(j)
            
            match = True
            for w in dictionary:
                all_same = True
                for k in indices:
                    if target[k] != w[k]:
                        all_same = False
                        break
                if all_same:
                    match = False
                    break
                    
            if not match : continue
            str_, cnt = self.generateAbbr(target, indices)
            if cnt < result_cnt:
                result = str_
                result_cnt = cnt
                
        return result
```
