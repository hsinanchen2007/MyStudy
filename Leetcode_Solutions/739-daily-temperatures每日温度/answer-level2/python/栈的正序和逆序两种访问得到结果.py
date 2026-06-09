### 解题思路
此处撰写解题思路

### 代码
逆序
```python3
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n=len(T)
        result=[0]*n
        stack=[]
        for i in range(n-1,-1,-1):
            while stack and T[stack[-1]]<=T[i]:
                stack.pop()
            if stack:
                result[i]=stack[-1]-i
            stack.append(i)
        return result
```


# 正序快些
![image.png](https://pic.leetcode-cn.com/943447bdf5812da394d9cf7d03d957c0943308a6f6a9b383a1bc8e9737a0f76d-image.png)

```
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n=len(T)
        result=[0]*n
        stack=[]
        for i in range(n):
            while stack and T[stack[-1]]<T[i]:
                index=stack.pop()
                result[index]=i-index
            stack.append(i)
        return result
```

