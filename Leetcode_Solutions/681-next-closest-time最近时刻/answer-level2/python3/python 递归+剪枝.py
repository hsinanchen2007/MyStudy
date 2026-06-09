
更多Leetcode题解以及算法面试经验：[Mereder博客](https://mereder.github.io/archives/)

递归思路：就是枚举四个数字出现在每一个位置时候的情况，四个位置，4个数字，最差就是 4！
剪枝策略：对于小时位置不满足[0,24)，对于分钟位置不满足[0,60)

!!!注意一个问题：对于'00:00' '11:11'的处理。
原有逻辑遇到 其本身会直接return 返回空结果，这样导致上面出现的case不能很好的覆盖
我们可以先将其赋值到`self.result`上，如果最后没有找到最小的时间，那么说明出现了上面这样的情况（全是重复数字）
最后直接返回`self.result`

 如何计算时间差？ 可参考官方题解给的计算方法
（minutes_new_time - minutes_origin_time） % (24\*60)
举例：12；01对应  12\*60+1 = 720
那么‘11：02’时间对应  11\*60+2 = 662
（662-720） % 1440 = -58 % 1440 = 1382 是一个很大的值
主要就是这个思想来判断新生成的时间是否是距离最近的。

```python
class Solution:
    def __init__(self):
        self.result = ''
        self.min_time = 1440
        self.time = 0
    def nextClosestTime(self, time: str) -> str:
        self.result = time  # 直接赋值到结果上 
        self.time = int(time[:2])*60+int(time[3:])
        digit = time[:2]+time[3:]
        stack = ''
        self.backtrace(0,stack,digit)
        return self.result

    # dfs+剪枝
    def backtrace(self,depth,stack,digit):
        # 剪枝
        if depth == 2 and int(stack[:2])>=24:
            return 
        if depth == 4 and int(stack[2:])>=60:
            return
        elif depth == 4:
            tmp_time = self.cal_time(stack)
            if tmp_time == 0:
                return
            elif tmp_time < self.min_time: # 如果出现更小的时间，更新最小时间差以及结果
                self.min_time = tmp_time
                self.result = stack[:2]+':'+stack[2:]
            return
        
        for i in range(len(digit)):
            
                stack += digit[i]
                self.backtrace(depth+1,stack,digit)
                stack = stack[:-1]
                

    def cal_time(self,new_time):
        hour = int(new_time[:2])
        minutes = int(new_time[2:])
        time = hour*60+minutes
        return (time-self.time)%(24*60)   #  小trick  -1 % 100 的结果是 99
```

更多Leetcode题解以及面试经验：[Mereder博客](https://mereder.github.io/archives/)