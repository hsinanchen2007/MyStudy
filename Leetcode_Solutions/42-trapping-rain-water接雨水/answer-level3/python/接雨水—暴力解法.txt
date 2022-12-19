### 解题思路
**（1）文字思路**
**第一步**，判断数组是否存有空间进行雨水收集
**第二步**，找出最高值highest
通过索引最高点为h
以最高点为分界点
分为左右两部分
分别收集雨水
雨水集中在最高和次高之间的空间
**第三步**，左右合计为雨水数
**（2）代码思路**
**第一步**，判断能否收集雨水
![image.png](https://pic.leetcode-cn.com/2737a4cde06f11a5de5a7887df484c762d5809688e157c239db1e3c508787515-image.png)
**第二步**，找到最高点
![image.png](https://pic.leetcode-cn.com/fe13dd90f571a1d272eb5d88188d0ad122ed7e55849215665ef4dbe95359d4df-image.png)
**第三步**，找出次高位置点higher，逐步遍历与更替，左部分代码如下，
![image.png](https://pic.leetcode-cn.com/f7154ac24792e8f60de79342ac8ba0c2142380185254cfb621d93b5a375b7a63-image.png)
其中ini是确保起点值不为0（这一步可以不要）
且判断左半部分是否为空
**第四步**，右半部分算法与左部分算法区别在于：
右半部分从后往前遍历
其中起始值应为列表的长度-1
![image.png](https://pic.leetcode-cn.com/11945fe91a0323b8b61ca7b51ffd656bdc8c7ea59570afb7ed290f41e326d0b3-image.png)
也需判断右半部分是否为空
**第五步**，返回drop


### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        highest = 0
        ini = 0
        drop = 0
        lhigher = 0
        rhigher = 0
        total = len(height) 
        if total <= 1:
            return drop
        for num in height:
            if num > highest:
                highest = num
        h = height.index(highest)
        if h != 0: 
            for i in range(h):
                if height[i] != 0:
                    ini = i
                    break
            if ini != h:
                for i in range(ini,h):
                    if height[i] < lhigher:
                        drop +=lhigher - height[i]
                    else:
                        lhigher = height[i]
        if h != total -1:
            for i in range(total-1,h-1,-1):
                if height[i] < rhigher:
                    drop += rhigher - height[i]
                else:
                    rhigher = height[i]
        return drop
            
        



```