最基本的暴力和累加

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        lst=[]
        for i in range (1,int(target/2)+1):
            temp=[]
            sum=0
            now=i
            while 1:
                sum=sum+now
                temp.append(now)
                if sum>target:
                    break
                if sum==target:
                    lst.append(temp)
                    break
                if sum<target:
                    now=now+1
```

然后是升级版，暴力和数学解法，唯一的就是判断结果是不是整数
```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        '''数学公式的方法，只是在暴力的基础上不采用暴力叠加，用数学公式的方法
        '''
        lst=[]
        for i in range(1,int(target/2+1)):
            a=(-1+(1+8*target+4*i**2-4*i)**0.5)/2
            if int(a)==a:
                lst.append(list(range(i,int(a+1))))


        return lst
```
最后还有一个个滑窗的方法，这个方法的复杂度和前面的差不多，也很直观。
创建一个滑窗，如果窗内sum小，滑窗右边界左移，如果窗内数多滑窗左边界右移，和双指针是一个意思
直到床边到达边界
```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        '''滑窗的方法，创建两个指针。然后不停的滑m
        '''
        left=0
        right=0
        sum=0
        lst=[]
        while 1:
            #print(right,left)
            if sum<target:
                right+=1
                sum=sum+right
            elif sum==target:
                
                lst.append(list(range(left+1,right+1)))
                right+=1
                left+=1
                sum=right+sum-left

            elif sum>target:
                left+=1
                sum=sum-left
            if right>int(target/2+1):
                break
        return lst
```

