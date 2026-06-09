### 解题思路
参考点赞数最多的大佬：前缀和+单调栈 Python3写的注解，转换为上坡路问题理解更简单

### 代码

```python3
class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        length = len(hours)
        """ 
        将最初的时间转化为是否是劳累的一天存储于数组score中（劳累记为1，不劳累记为-1）
        原问题转化为寻找连续和 >0 的最长子串长度
        """
        score = [0] * length
        for i in range(length):
            if hours[i] > 8:
                score[i] = 1
            else:score[i] = -1
        
        """
        计算前缀和，通过前缀和的差值来判断是否是良好的表现时间段
        问题转化为：寻找一对i,j;使presum[j] > presum[i],并且j-i最大，即转化为求最长上坡路问题
        """
        presum = [0] * (length + 1)
        for i in range(1,length + 1):
            presum[i] = presum[i - 1] + score[i - 1]

        """
        用单调递减栈存储presum中的元素的位置，如果理解为上坡问题的话，单调栈中维护的元素从底到顶高度依次降低，
        即越来越深入谷底，遍历完成后的栈顶位置的元素即所有元素中谷底的高度
        """
        stack = []
        for i in range(length + 1):
            if not stack or presum[i] < presum[stack[-1]]:
                stack.append(i)      

        """
        从尾部遍历presum，如果该位置元素比stack中存储的位置的元素高，则表明为上坡路，弹出栈顶元素，并记录坐标差，
        该坐标差即为上坡路的长度
        """
        ans = 0
        for i in range(length , -1, -1):
            while stack and presum[i] > presum[stack[-1]]:
                ans = max(ans,i - stack[-1])
                stack.pop()
        return ans
```