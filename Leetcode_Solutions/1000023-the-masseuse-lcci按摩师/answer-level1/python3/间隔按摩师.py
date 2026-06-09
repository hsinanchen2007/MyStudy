### 解题思路
（1）题目要求
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

示例 1：
输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。

（2）代码思路
参考这个代码
        last,now=0,0
        for num in nums:
            last,now=now,max(last+num,now)
        return now
此时now赋值中的last是间隔后赋值，也就是说每次循环中last新值不会被用到，而用到上轮中last值

（3）注意点
Python 给多个变量赋值
a = 3
a, b = 1, a
如果按照正常的思维逻辑，先进行a = 1，在进行b = a，最后b等于1，但是这里b其实等于3，因为在连续赋值语句中等式右边其实都是局部变量，而不是真正的变量值本身，比如，上面例子中右边的a，在python解析的时候，只是把变量a的指向的变量3赋给b，而不是a=1之后a的结果

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        else:
            last,now = 0,0
            for i in range(n):
                last,now = now,max(last+nums[i],now)
            return now 


```