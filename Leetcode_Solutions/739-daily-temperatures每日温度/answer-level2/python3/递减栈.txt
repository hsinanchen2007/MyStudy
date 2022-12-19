### 解题思路
本来以为是dp问题，但是看了官方题解才发现是栈。其实特征也挺明显，这种求第一次的问题确实比较适合栈，以后做数组题可以多一个思考方向。

### 代码

```python3 []
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack=[]
        res=[0 for _ in range(len(T))]
        for i in range(len(T)):
            while stack and T[stack[-1]]<T[i]:
                s=stack.pop()
                res[s]=i-s
            stack.append(i)
        return res

```