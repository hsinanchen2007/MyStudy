### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        #使用字典来存储各个元素及其出现次数
        aux={}
        for num in nums:
            if str(num) not in aux.keys():
                aux[str(num)]=1
            else:
                aux[str(num)]+=1
        #遍历value值为1的元素，即可求其值
        for key,value in aux.items():
            if value==1:
                return int(key)
```