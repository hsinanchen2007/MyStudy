题目的意思是如果长度相等的两个字符串S和C，在奇数位置上的元素相同（字母相同、个数也相同，不考虑顺序），在偶数位置上的元素也相同，那么这两个的字符串是特殊等价字符串，给定字符串组A中所有跟S是特殊等价字符串的字符串构成一个组，题目要求返回这样的组的个数。
官方题解的思路是构造了一个52个元素的元组来区分组，就是52个特征（26个字母*奇偶位置）。
我的思路是用2个元素的元组（奇和偶），奇数位置上运算得到一个数，偶数位置上得到一个数，用指数函数构造这样的数：
每隔一个字母指数就加1，a的指数是1，b的指数是2，c是3，以此类推，这样可以避免a+d=b+c，导致不同的字母组合得到相同的数。底数用11，因为1 <= A[i].length <= 20，奇数（偶数）位置上相同字母最多11个，避免a*个数=b。
```python
class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        res=[]
        for word in A:
            oddnum=0
            evennum=0
            for i in range(len(word)):
                if i%2==0:
                    evennum+=21**(ord(word[i])-96)
                else:
                    oddnum+=21**(ord(word[i])-96)
            if (oddnum,evennum) not in res:
                res.append((oddnum,evennum))
        return len(res)
```
看结果，执行用时不行，内存消耗倒还可以。
![image.png](https://pic.leetcode-cn.com/7c4846924c3316f5c92243360e8e8742c6856b8904cc5174d5f8635886b1a8de-image.png)

