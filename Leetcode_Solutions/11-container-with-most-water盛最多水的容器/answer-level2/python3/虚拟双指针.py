- - 面积等于长*宽，先固定长为最长，进行循环：
    计算面积，存储到列表
    长：逐渐减小长，-1
    宽：木桶原理，每次循环增加最短的宽边；选取较短的宽边，进行收缩left+=1 or right-=1
```
class Solution:
    def maxArea(self, height) -> int:
        water = []
        head=0
        tail=len(height)-1
        while head<tail:
            s=self.get_Area(head,tail,height)
            water.append(s)
            if height[head]<height[tail]:
                head+=1
            else:
                tail-=1

        return max(water)
    def get_Area(self,i,j,height):
        if height[i]<height[j]:
            return height[i]*(j-i)
        else:return height[j]*(j-i)

if __name__ == '__main__':

    s = [1,8,6,2,5,4,8,3,7]
    print('input=', s)
    print(Solution().maxArea(s))
```

