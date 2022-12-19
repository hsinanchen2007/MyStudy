- 首先，根据列表长度不同分析一个普适的反转位数的参数n，
- 再根据反转次数将列表前后对应的值进行调换
例如：奇数长度的列表[a,b,c] 进行反转的次数有两种理解方式：
ac对调,b与自己对调（反转两次）;
仅仅ac对调（反转1次）（本题目采用的理解方式）;
而偶数长度的列表[a,b] 进行反转的次数为1：
所以得到反转次数为 列表长度除以2 且向下取整

根据索引的性质，列表第一个值与list[0]与list[-1]是对应的，即list[i]应该与list[-i-1]对调
```
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n = int(len(s)/2)
        for i in range(n):
            try:
                s[i],s[-i-1] = s[-i-1],s[i]
            except IndexError:
                break
```
