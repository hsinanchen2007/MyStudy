**# 方法1 暴力枚举**
# 时间复杂度O（target*sqrt(target))
```python []
def sum_of_target1(target):
    result = []
    limit = (target+1)//2
    for i in range(1,limit+1):
        num = i
        for j in range(i+1,limit+1):
            num += j
            if num>target:
                break
            elif num == target:
                result.append([k for k in range(i,j+1)])
    return result
```
**采用方法1，Python提交超时**

**# 方法2 数字优化＋枚举**
sum([x,x+1,...,y]) = (y-x-1)(y+x)/2
在每个起点x，可以计算出满足条件的y的值
所以每次枚举只需要找1个y值就可以，时间复杂度为O(target)
```python []
def sum_of_target2(target):
    result =[]
    limit = (target-1)//2
    for i in range(1,limit+1):
        delta = 1-4*(i - i*i-2*target)
        if delta<0:continue
        delta_sqrt =int(delta **0.5)
        if delta_sqrt*delta_sqrt == delta and (delta_sqrt-1)%2==0:
            y = (delta_sqrt-1)//2
            result.append([k for k in range(i,y+1)])
    return result
```
**方法2性能一般，148ms**

**# 方法3 双指针法（滑动窗口法）**
搜索[l,r]区间，利用求和公式对该区间的序列求和，结果为t
如果t<target，说明区间端点要右移，r++
如果t>target,说明区间端点要左移,l++
如果t==target,记录该值，l++从下一个开始搜索
从头开始搜索，l=0开始
结束标志是l==r,表示走到了末尾
```python []
def sum_of_target3(target):
    result =[]
    left,right = 1,2 # 因为至少包括2个连续正整数
    while left<right:
        t = (left+right)*(right-left+1)/2
        if t<target:
            right +=1
        elif t>target:
            left +=1
        else:
            result.append([k for k in range(left,right+1)])
            left +=1
    return result
```
**# 方法4 间隔计算法**
在[x,x+i]区间的数字和t = x(i+1)+i(i+1)/2
则x =( t-i(i+1)/2 )/(i+1)
根据间隔，可以计算出x，x必须得是正整数
x>0，即t>i(i+1)/2
x是整数，则(t-i*(i+1)/2) % (i+1) ==0
因为要求输出序列按照首个数字从小到大排列，即间隔从大到小
```python []
def sum_of_target4(target):
    result=[]
    limit = (target-1)//2
    for i in range(limit,0,-1):
        temp = i*(i+1)//2
        first = target - temp
        if first>0 and first%(i+1)==0:
            x = first//(i+1)
            result.append([k for k in range(x,x+i+1)])
    return result
```
**方法3和方法4性能差不多，运行时间都是80ms**