### 解题思路
看了一些题解，发现代码写了好多，有点晕~ 所以用回溯写了一个简单点的算法。回溯算法基本上是按照模板来。
1、定义结果变量和状态变量
2、确定终止递归条件
3、在当前状态下，考虑如何得到下一个状态（这里就是在当前分割位置下，如何确定下一个分割位置）
### 代码

```python3
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        # 回溯算法
        res = [] # 结果变量
        state = [] # 状态变量

        def backward(state, i): # i，当前分割位置
            # 终止条件
            if i == len(s):
                res.append(state)
                return 
            
            for j in range(i+1, len(s)+1): # j，下一个分割位置
                temp = s[i:j] # 两个分割位置确定的字符串
                if temp == temp[::-1]: # 判断是否为回文
                    backward(state+[temp], j)
            
        backward([], 0)
        return res
```