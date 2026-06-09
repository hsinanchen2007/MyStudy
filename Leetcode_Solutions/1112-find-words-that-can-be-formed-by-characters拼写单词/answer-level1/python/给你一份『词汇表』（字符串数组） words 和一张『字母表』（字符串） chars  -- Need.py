### 解题思路
1. 采用字典、hash表计数并比较； 没有什么技巧

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        nsize = len(chars)
        if nsize < 1:
            return 0
        
        di = dict()
        res = 0

        for ele in chars:
            di[ele] = di.get(ele, 0) + 1
        '''
        ## 所有单词只能使用一次
        f = True
        for eles in words:
            for ele in eles:
                if di.get(ele, 0) <= 0:
                    f = False
                    break 
            if f :
                res += len(eles)
                for ele in eles:
                    di[ele] = di.get(ele, 0) - 1
        '''
        f = True 
        tmp = dict()
        for eles in words:
            for ele in eles:
                tmp[ele] = tmp.get(ele, 0) + 1
                if di.get(ele, 0) < tmp.get(ele, 0) :
                    f = False
                    break 
            if f :
                res += len(eles)
            tmp.clear()
            f = True 
        return res 
```