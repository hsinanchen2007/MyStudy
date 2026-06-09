```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        num1 = len(strs)
        target = ""
        flag = ""
        i = 0
        try:
            curl = strs[0]
        except IndexError:
            return("")
        while True:
            for j in range(num1):
                try:
                    if curl[i] == strs[j][i]:
                        flag = 'true'
                    else:
                        flag = 'xx'
                        break
                except IndexError:
                    flag = 'xx'
                    break
            if flag == 'true':
                target += curl[i]
            elif flag == 'xx':
                break
            i += 1
        return(target)
```


![image.png](https://pic.leetcode-cn.com/c476e13404ad58f3f95d89146d27f019132b981bbc408b33351e823958a8e66a-image.png)
