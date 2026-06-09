
根据王树禾的`<<图论>>`， 可以知道，较长的括好号可以由较短的好括号列获得，即下图中的 2，3点。而且根据4，这是充分的，不会漏掉的

![image.png](https://pic.leetcode-cn.com/a2f4d6904ef31e4686260cc359b10b19414b5a0192e13537e99124cf0952b96a-image.png)

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dic = {0:set([""])}
        for length in range(1,n+1):
            dic[length] =set()
            for l1 in range(1,length):
                l2 = length-l1
                for left in dic[l1]:
                    for right in dic[l2]:
                        dic[length].add(left+right)
            for one in dic[length-1]:
                dic[length].add('('+one+')')
        return list(dic[n])
```
