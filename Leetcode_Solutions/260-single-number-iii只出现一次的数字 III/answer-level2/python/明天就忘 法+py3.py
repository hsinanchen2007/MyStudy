### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        # 先异或 相同为0 不同为1  
        # 异或出 剩余不重复的的异或值
        x=0
        for num in nums:
            x^=num
        # 然后找到从左到右的第一位为1  类似010 用来区分不重复的两个数
        # n&-n 表示只剩下从右到左的第一位为1 其余都是0 -n=~n+1 
        #n&(-n) 等于 n&(~n+1)
   
        # 获取一个划分点，类似变成了 有一个元素不重复
        x&=-x
        res=[0,0]
        for num in nums:
            if num &x==0:
                res[0]^=num
            else:
                res[1]^=num
        return res

```