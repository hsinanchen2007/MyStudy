### 解题思路
我现在的想法是, 肯定用双指针法
1. 从两边到中间,显然宽度是逐渐变小的, 要使得体积变大,必要条件是高度变大(高度变大也不一定体积就会变大)
2. 高度变大, 要求肯定是min{left,mid,right}>min{left,right}, 也就是这个mid的进来必须促使高度变大
3. 那么我们肯定是要从min{left,right}的那一端开始找
 (不然mid不论取何值高度都不会变大,这个可以证明一下,我是纯粹脑补了一下)
4. 然后一定要使得这个mid值比min{left,right}要大,和max{left,right}谁大谁小应该无所谓

### 关键步骤
1. 左右比较得到较小值 -> 
2. 较小值的索引向对方走若干步 -> 
3. (若干步中包括一个循环判断,新位置必须比老位置高才可以) -> 
2. 当前面积与最大面积进行比较,更新或保持最大面积

### 易错点
1. maxArea的更新位置要很小心! 好几次都是更新的时候搞不清楚!
2. 从循环中"break出来"和"不满足循环条件退出"是两种情况, 要分别阐述!
### 代码

```python3
class Solution:
    def maxArea(self,heights):
        if len(heights)==2:
            return min(heights[0],heights[1])
        else:
            left,right=0,len(heights)-1
            maxArea=-1
            while left!=right:
                left_val,right_val=heights[left],heights[right]
                if maxArea==-1:
                    maxArea=(right-left)*min(left_val,right_val)
                if min(left_val,right_val)==left_val: # 左小,那么就从左边开始找起
                    while left!=right:
                        left += 1
                        old_left_val=left_val
                        left_val=heights[left]
                        if left_val>old_left_val:
                            old_left_val=left_val
                            break
                    if left==right: # 没找到, 脑补下像不像一个盆地?
                        area=left_val*(right-left)
                        if area>maxArea:
                            maxArea=area
                    else:
                        area=(right-left)*min(left_val,right_val)
                        if area>maxArea:
                            maxArea=area
                elif min(left_val,right_val)==right_val: # 右小, 那么就从右边开始找起
                    while right!=left:
                        right -= 1
                        old_right_val=right_val
                        right_val=heights[right]
                        if right_val>old_right_val:
                            old_right_val=right_val
                            break
                    if right==left:
                        area=right_val*(right-left)
                        if area>maxArea:
                            maxArea=right_val*(right-left)
                    else:
                        area=(right-left)*min(left_val,right_val)
                        if area>maxArea:
                            maxArea=area
            return maxArea

```