### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def dailyTemperatures(self, T):
        len_T=len(T)
        ans=[0 for _ in range(len_T)]
        stack=[]
        for i in range(len_T):
            if stack==[]:
                stack.append(i)
            else:
                while stack!=[]:
                    cur=stack[-1]
                    if T[i]>T[cur]:
                        ans[cur]=i-cur
                        stack.pop()
                    else:
                        break
                stack.append(i)
        return ans
```