### 解题思路
维护一个递减的栈。
从左往右数，比栈顶小的元素直接入栈。如果元素A比栈顶大，栈顶pop，直到小于栈顶元素为止，计算此时A和栈顶之间的柱子能盛多少水，并将它们之间的柱子填平。最后，别忘了把A入栈。

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height)<=2:return 0
        i=1
        stack=[0]
        res=0
        while i<len(height):
            if stack and height[i]>=height[stack[-1]]:
                while stack and height[i]>=height[stack[-1]]:
                    tmpleft=stack.pop()
                if stack:
                    tmpleft=stack[-1]
                minedge=min(height[tmpleft],height[i])
                res+=(i-tmpleft-1)*minedge-sum(height[tmpleft+1:i])
                stack.append(i)
                for j in range(tmpleft+1,i):
                    height[j]=minedge
            else:
                stack.append(i)
            #print(i,'height',height[i],stack,res)
            i+=1
        return res
```