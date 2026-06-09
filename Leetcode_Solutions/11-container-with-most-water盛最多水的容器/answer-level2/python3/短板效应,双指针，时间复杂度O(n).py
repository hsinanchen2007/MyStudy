### 解题思路
此处撰写解题思路
面积=短板高*长度；
水槽板位置固定；
因此想到算法思路：
（1）双指针法
（2）短板一边向中间靠拢
（3）每次判断是否更新最新解
### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0 #最左指针
        right = len(height)-1 #最右指针
        def calArea(left,right,height): # 计算水容量公式
            return min(height[left],height[right]) * (right - left)
        area = calArea(left,right,height) #初始化面积
        while(left != right):
            #短板一边向中间靠拢
            if(height[left] <= height[right]):  left +=1
            else: right-=1
            #重算面积，获取最大值
            midArea = calArea(left,right,height)
            if(midArea >= area): 
                area = midArea
        return area

        
```