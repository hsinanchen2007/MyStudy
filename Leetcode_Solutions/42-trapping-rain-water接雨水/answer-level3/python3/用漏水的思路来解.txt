![图片.png](https://pic.leetcode-cn.com/f937d73f990213291b4934b66aaddc58eeac004a0b73d3ef27a8a947e8d3a24c-%E5%9B%BE%E7%89%87.png)
```
class Solution:
    def trap(self, height: List[int]) -> int:
        if height==[]:return 0
        length = len(height)
        head,i,tail,j,over = 0,0,length-1,length-1,max(height)
        rain = length*over-sum(height)
        while(head<tail):
            if height[i]>height[head] or height[i]==over:
                rain -= (height[i]-height[head])*i
                head=i
            if height[j]>height[tail] or height[j]==over:
                rain -= (height[j]-height[tail])*(length-1-j)
                tail=j
            i+=1
            j-=1 
        return rain
```

