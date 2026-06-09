### 解题思路
* 当输入类似于'aabc'时需要去重,因为调换两个a的顺序不算新的字符串.

### 代码

```py
class Solution:
    def permutation(self, s: str) -> List[str]:
        ans = []
        s = list(s)    #序列化字符串
        begin = 0
        n = len(s) 
        def fuc(char, begin):   #从指定的字符开始,全排列其后续的字符
            if n - begin > 1:     #保证当前考略的全排列至少含有2个字符
                for i in range(begin, n):
                    char[i], char[begin] = char[begin], char[i]  #begin与i相同时相当于不改变
                    fuc(s, begin + 1)
                    char[i], char[begin] = char[begin], char[i]  #计算完之后恢复顺序
            else:
                ans.append(''.join(char))   #保存字符串
        fuc(s,begin)
        ans = set(ans)      #去重
        return list(ans)
```