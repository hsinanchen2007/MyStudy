本题使用数组res来模拟分数
从数组尾部遍历到数组头部，在每次循环中：当前元素与上次迭代的结果res之和为分母，相加后做倒数(交换分子分母的位置)；但要注意，最后一轮也就是a0只需做加法即可
注意：因为题目中已声明无需约分
```
from collections import deque
class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        q=deque(cont)
        top=q.pop()
        res=[1,top]
        if(len(q)==0):
            res.reverse()   #如果只有a0，那就直接倒数输出
        while q:
            top=q.pop()
            res[0]+=top*res[1]  #分数相加，分母不变，分子做加法
            if(len(q)>=1):
                res.reverse()  #加法结果作倒数，注意最后一步不能作倒数
        return res
```
![2.PNG](https://pic.leetcode-cn.com/24a84fc540f4be43c3208e4e64b31495a8cf9374563e5b48481591bf24bcbeb5-2.PNG)

