### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        '''
        dict={}
        for i,v in enumerate(numbers):
            if target-v in dict:
                return [dict[target-v]+1,i+1]
            else:
                dict[v]=i
        '''

        left = 0
        right = len(numbers)-1
        while left<right:
            if numbers[left]+numbers[right]<target:
                left+=1
            elif numbers[left]+numbers[right]>target:
                right-=1
            else:
                return [left+1,right+1]
```