本题利用栈的性质去维护一个栈，不断将栈顶的值和现在的比较

### 代码

```python
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n=len(height)
        a=[]
        ans=0
        current=0
        while(current<n):
            while len(a)!=0 and height[a[-1]]<height[current]:
                tmp=a.pop()
                if len(a)==0:
                    break
                distance=current-a[-1]-1
                bounded_height=min(height[current],height[a[-1]])-height[tmp]
                ans+=distance*bounded_height
            a.append(current)
            current=current+1
        return ans
                
            



        

```