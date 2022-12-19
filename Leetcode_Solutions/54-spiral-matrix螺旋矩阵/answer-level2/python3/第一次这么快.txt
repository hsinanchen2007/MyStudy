![image.png](https://pic.leetcode-cn.com/1ec3351fc9dfd5e728877f4cb57608feb92e7604a35d56caba0991054c6f3335-image.png)



```
class Solution:
    def spiralOrder(self, martrix: List[List[int]]) -> List[int]:
        m=len(martrix)
        if m==0:
            return []
        n=len(martrix[0])
        if n==0:
            return []       
        ans=[]
        left=0
        right=n-1
        top=0
        button=m-1
        while left<=right and top<=button:
            print(top,button,left,right)
            for i in range(left,right+1):
                ans.append(martrix[top][i])
            top+=1
            if top>button:
                break
            for i in range(top,button+1):
                ans.append(martrix[i][right])
                
            right-=1
            if left>right:
                break
            for i in range(right,left-1,-1):
                ans.append(martrix[button][i])
            button-=1
            if button<top:
                break
            for i in range(button,top-1,-1):
                ans.append(martrix[i][left])
            left+=1                       
        return ans
```
