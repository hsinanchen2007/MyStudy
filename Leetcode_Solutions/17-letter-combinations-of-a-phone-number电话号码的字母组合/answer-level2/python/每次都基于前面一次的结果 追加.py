### 解题思路
此处撰写解题思路
示例：“23”
round     resutls:
2          ['a','b','c']
3            ['ae','be','ce','ad','bd','cd','af','bf','cf']
### 代码

```python3
import copy
class Solution:
    def letterCombinations(self, digits):
        lookup={'2':"abc",'3':"def",'4':"ghi",'5':"jkl",'6':"mno",'7':"pqrs",'8':"tuv",'9':"wxyz"}
        results=[]
        for d in digits:
            if len(results)==0:
                for w in lookup.get(d):
                    results.append(w)
            else:
                new_results=copy.deepcopy(results)
                results.clear()
                for w in new_results:
                    for w1 in lookup.get(d):
                        results.append(w+w1)
        return results

```