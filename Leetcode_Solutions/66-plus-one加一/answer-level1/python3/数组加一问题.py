### 解题思路
三种情况：
1、末位无进位：直接+1
2、末位有进位，但在中间位置停止：进位的变成0，停止处+1
3、类似999、99999999:将list置为全0数组，表头插入1

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        nums_str = ""
        for i in digits:
            nums_str =nums_str+str(i)
    
        nums_int = int(nums_str)+1
        res = []
        for i in str(nums_int):
            res.append(int(i))
        return res

```