### 解题思路
思路:1.首先统计每个字符的个数
     2.res=0,字符双数的直接加，单数的请客 有两种，一直接找到最大的单数加到res 二 大于1的 减一 然后直接
    加。注意一个 最大的单数可能有几个 取一个就好了。
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        if not s:
            return 0
        nums={}
        for i in s:
            nums[i]=s.count(i)
        res=0
        temp=[]
        max1=0
        for j in nums.values():
            # 单数判定
            if j & 1:
               temp.append(j)
               if j>max1:
                   max1=j
            else:
                res+=j

        flag=1
        for num in temp:
            if num==max1 and flag:
                flag=0
                continue
            if num>1:
                res+=num-1
        return res+max1
```