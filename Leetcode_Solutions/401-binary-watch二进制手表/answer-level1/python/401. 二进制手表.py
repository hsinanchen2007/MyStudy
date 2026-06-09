### 解题思路
第一次接触灰度算法，学习阶段，感谢作者 **jawhiow**

### 代码

```python
class Solution(object):
    #初始化变量
    def __init__(self):
        self.nums = [1,2,4,8,1,2,4,8,16,32]
        self.ans = None
        self.visit = None

    def readBinaryWatch(self, num):
        #用来存放满足条件的结果 最后输出
        self.ans = []
        #表示灯的亮暗情况 亮：visit = 1 暗：visit = 0
        self.visit = [0]*len(self.nums)
        #findsolution(num,start,step) step:表示循环层次 临界条件 step == num start:表示指示灯起始查看位置 不断更新start值 
        self.findsolution(num,0,0)
        return self.ans

    def findsolution(self,num,start,step):
        #step == num时，需要在ans中加入满足条件的结果
        if step == num:
            #加入满足条件的结果后，回退到上一步，继续寻找可行解
            return self.ans.append(self.time_cal(self.visit))
        else:
            #需要将nums完全遍历找到所有可行解
            for i in range(start,len(self.nums)):
                #灯亮，但还需要看是否满足hour在[0,11]minute在[0,59]内
                self.visit[i] = 1
                #超出范围，进行剪枝
                result = self.time(self.visit)
                #如果解不满足条件，此处不能是灯亮的情况
                if not result:
                    #把他灭掉！
                    self.visit[i] = 0
                    continue
                #继续前进，此处也是上面回退的位置
                self.findsolution(num,i+1,step+1)
                #满足条件的一组解求出后，将灯灭掉，看接下来一盏灯亮时是否满足条件
                self.visit[i] = 0

    #该函数的作用是为了判断亮着的灯是否满足范围条件
    def time(self,visit):
        sum_hour = 0
        sum_minute = 0
        for i in range(len(visit)):
            #若该位为0，则终止
            if visit[i] == 0:continue 
            #若该位为1，则计算时间
            if i < 4:
                sum_hour += self.nums[i]
            else:
                sum_minute += self.nums[i]
        return 0 <= sum_hour <= 11 and 0 <= sum_minute <= 59

    #该函数的作用是当存在可行解时用来计算时间
    def time_cal(self,visit):
        sum_hour = 0
        sum_minute = 0
        res = ""
        for i in range(len(visit)):
            #若该位为0，则终止
            if visit[i] == 0:continue 
            #若该位为1，则计算时间
            if i < 4:
                sum_hour += self.nums[i]
            else:
                sum_minute += self.nums[i]
        if  0 <= sum_minute <= 9:
            res += str(sum_hour) + ':' + str(0) + str(sum_minute)
        else:
            res += str(sum_hour) + ':' + str(sum_minute)
        return res
        







       
        
         


```