### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        dict={}
        for i in nums:
            dict[i] = dict.get(i,0)+1
        #print(dict)
        '''
        for i in nums:
            if dict.get(i)==1:
                return i
        '''
        for k,v in dict.items():
            if v==1:
                return k

```