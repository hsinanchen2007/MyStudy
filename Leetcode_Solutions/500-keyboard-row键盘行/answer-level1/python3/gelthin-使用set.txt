### 解题思路
集合也是 hash 表的一种，以 O(1) 的时间来判断是否存在，以及额外信息。

下面代码参考 [键盘行+python3+集合求交集](https://leetcode-cn.com/problems/keyboard-row/solution/jian-pan-xing-python3ji-he-qiu-jiao-ji-by-pandawak/)

``` python3 
class Solution(object):
    def findWords(self, words):
        set1 = set('qwertyuiop')
        set2 = set('asdfghjkl')
        set3 = set('zxcvbnm')
        res = []
        for i in words:
            x = i.lower()
            setx = set(x)
            if setx<=set1 or setx<=set2 or setx<=set3:
                res.append(i)
        return res
```


我自己的代码写的冗余冗长，不好。 没必要建 dict, 更没必要同时在 dict 中存大、小写字母
应该在后面使用 lower() 函数



### 代码

```python3
class Solution:
    def findWords(self, words: List[str]) -> List[str]:

        D = dict()
        for x in "QWERTYUIOP":
            D[x] = 1
            D[x.lower()] = 1
        for x in "ASDFGHJKL":
            D[x] = 2
            D[x.lower()] = 2
        for x in "ZXCVBNM":
            D[x] = 3
            D[x.lower()] = 3
        
        result = []
        for word in words:
            if len(word) <= 1:
                result.append(word)
            else:
                flag = True
                for x in word[1:]:
                    if D[x] != D[word[0]]:
                        flag = False
                        break
                if flag:
                    result.append(word)
        return result

                    

                
```