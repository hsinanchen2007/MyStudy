### 解题思路
这是我的第一个算法，自己只会暴力的方法，两个for循环，匹配加和，但是运行的耗时太大，于是看各位大佬的方法和思路，python超级方便，利用enumerate直接将数组组合成有序的索引序列，我只说下我的思路：
    用一个dict将原本的key-value转变成value-key，这样就可以去查找另外一个数字，根据value作为key去匹配，直接用target-value的差值进行寻找对应的value作为key去读取这个数字在有序索引序列中的的位置信息，也就是了，大概就是这么个意思，我觉得这样理解我是可以超级理解的
谢谢大家!!

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        tzp_dict = {}
        for i,value in enumerate(nums):
            tzp_dict[value] =i
        for i,value in enumerate(nums):
            j = tzp_dict.get(target-value)
            if j is not None and j != i:
                return(i,j)

```