### 解题思路
![TIM图片20200403111230.png](https://pic.leetcode-cn.com/d1ac6cf63b4d9242f3376126484837cca3ce6ffab11e9a13ddda3802b0f3cfa2-TIM%E5%9B%BE%E7%89%8720200403111230.png)

### 代码

```python3
class Solution:
    def permutation(self, S: str) -> List[str]:
        def combation(s):
            tem_result = []
            if len(s) == 1:  #一个字符的情况
                tem_result.append(s)
                return tem_result
            first_str = s[0]
            comb = combation(s[1:])  #取出第一个字符，递归剩余字符
            for j in comb:
                for i in range(len(j) + 1):
                    tem_result.append(j[:i] + first_str + j[i:])
            return tem_result
        
        result = combation(S)
        return result
        
        
        
```