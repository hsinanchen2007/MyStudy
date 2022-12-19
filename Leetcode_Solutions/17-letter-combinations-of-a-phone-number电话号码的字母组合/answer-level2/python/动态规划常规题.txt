### 解题思路
此处撰写解题思路
动态规划思路编写
### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dictory={'2':['a','b','c'],'3':['d','e','f'],'4':['g','h','i'],'5':['j','k','l'],'6':['m','n','o'],'7':['p','q','r','s'],'8':['t','u','v'],'9':['w','x','y','z']}
        pre_list=[]
        List=[]
        if digits=='':
            return List
        for i in dictory[digits[0]]:
            List.append(i)
        for i in digits[1:]:
            pre_list=List
            List=[]
            for j in dictory[i]:
                for z in pre_list:
                    List.append(z+j)
        return List
```