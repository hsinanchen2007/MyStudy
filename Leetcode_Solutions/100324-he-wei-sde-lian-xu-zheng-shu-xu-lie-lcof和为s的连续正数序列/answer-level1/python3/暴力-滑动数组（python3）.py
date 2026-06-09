### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        #暴力枚举
        # start = 1
        # end = 1
        # L1 = []
        # flag = True
        # while(flag):
        #     sum = 0
        #     for i in range(start, target):
        #         sum+=i
        #         end = i
        #         if(sum==target):
        #             start+=1
        #             break
        #         if(sum>target):
        #             if (end-start)==1:
        #                 flag = False
        #             start+=1
        #             break
        #     if(sum==target):
        #         L1.append(list(range(start-1, end+1)))    
        #         if (end-start+1)==1:    
        #             flag = False
        # return L1

        #滑动数组
        start = 1
        end = 2
        L = []
        while start<end:
            sum = (start+end)*(end-start+1)//2
            if(sum>target):
                start+=1
            elif(sum==target):
                L.append(list(range(start, end+1)))
                start+=1
            else:
                end+=1
        return L

```