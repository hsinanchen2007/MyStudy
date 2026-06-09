### 解题思路
该题使用暴力解法不会通过，据说用C语言的暴力解法双循环可以通过，使用单循环如果使用单指针就会错过正确解，因此需要使用双指针，挪动高度小的指针，这样保证不会错过最大值。

### 代码

```python3
class Solution:
    def  clcarea(self,r,rh,c,ch): #求面积函数
        if rh > ch :
            return (c-r) * ch
        else:
            return (c-r) * rh

    def maxArea(self, height: List[int]) -> int: 
        max1=0
        area = 0
        r=0                         #左指针
        c=len(height)-1             #右指针  
        while r < c:
            area = self.clcarea(r,height[r],c,height[c]) #求面积
            if height[r] <= height[c]:                 #比较高度
                r+=1                                 #挪动左指针
            else:c -= 1                              #挪动右指针
            max1 = max(max1,area)                     #保存最大值
        return max1


```