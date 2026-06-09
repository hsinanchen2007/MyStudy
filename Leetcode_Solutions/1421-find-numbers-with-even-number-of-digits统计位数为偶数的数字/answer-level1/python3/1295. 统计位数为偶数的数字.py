### 解题思路
1  得知道每一个数字的 位数
2 数转成字符串很容易知道位数
3 判断奇数 偶数  修改统计结果

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        ii=0
        for  i in nums:
            if len(str(i))%2==0:
                ii+=1
        return ii
```