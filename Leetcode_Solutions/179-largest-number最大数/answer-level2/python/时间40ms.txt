### 解题思路
此处撰写解题思路   #时间40ms
# 1. 首先将nums转换为 str的列表ls
# 2. 然后将ls利用sorted函数排序，
# 3. 排序的时候 需要指定如何排序，
# 4. 设置一共10 位，将其重复到10 位，谁大排前面
# 5. 比如说 5 就变为 5555555555 51 就变成5151515151
# 6. 增加对0的判断
### 代码
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        ls = list(map(str,nums))
        ans = sorted(ls,key=lambda x:x*(10//len(x)),reverse=True)
        ans = ''.join(ans)
        if int(ans)==0:return '0'
        return ans
