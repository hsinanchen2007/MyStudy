### 解题思路
暴力方法：超时，有很多不必要的重复的遍历
滑动窗口：减少遍历的次数，左右双指针，排除掉不可能的结果。

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        l = []
        # for i in range(1,target//2+1):
        #     for j in range(i+1,target//2+2):
        #         if (i+j)*(j-i+1)==target*2:
        #             l.append([x for x in range(i,j+1)])
        i,j = 1,2
        while i<j:
            if (i+j)*(j-i+1)<target*2:
                j+=1
            if (i+j)*(j-i+1)>target*2:
                i+=1
            if (i+j)*(j-i+1)==target*2:
                l.append([x for x in range(i,j+1)])
                i +=1
        return l
                    
```