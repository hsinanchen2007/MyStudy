### 解题思路
将数字和字母转为1、-1，res字典记录下前n项和的值（tmp）及第一个下标的位置，如果最后的结果为前m项和值为0,表示前面m项就是题目要求。

### 代码

```python3
class Solution:
    def findLongestSubarray(self, array: List[str]) -> List[str]:
        res,tmp,length,right = {0:0},0,0,0
        for index,s in enumerate(array):
            tmp += 1 if s.isalpha() else -1
            if tmp not in res:
                res[tmp] = index
            else:
                if tmp == 0:
                    length = index +1
                    right = index+1
                elif index - res[tmp] > length:
                    length = index - res[tmp]
                    right = index +1
        return array[right-length:right]
```