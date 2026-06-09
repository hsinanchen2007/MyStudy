这题其实和求和最大子序列很相似，问题就是当遇到负数的时候比较麻烦，因为碰到两次负数会变正，最小的有可能直接变成了最大的，所以不但要记录curmax,还要记录curmin。
curmax意思是从下标0到目前位置的最大乘积
curmin意思是从下标0到目前位置的最小乘积
1.正数的处理
直接将curmax,curmin分别乘以num再根据筛选要求取大或取小就好了，因为正数不改变正负性，该是正的还是正的，该是负的。如果你看到这还没明白，请看下一段的分解过程，如果你已经懂了可以跳过直接看负数的处理。

已知num为正的情况下
当curmax为正，curmax*num>num,最大乘积应该用前面的累计乘数乘以num获取，curmax=curmax*num
当curmax为负, curmax*num<0<num,最大乘积应该舍弃前面的累计数，直接替换成num,curmax=num

当curmin为正, curmin*num<num，用前面的最小乘积乘以这个数会得到一个更小的累计乘积,curmin=curmin*num
当curmin为负, curmin*num>0>num，累计乘数乘num得到了一个正数，因此应该舍弃前面的乘积,curmin=num

2.负数的处理
以[2,3,-2,4]为例
curmin取到下标1的时候存储的是curmin=3如果继续按curmin=min(curmin*num,num)的方法去取下标2的话，下标0这个2就丢失了，此时真正的curmin应该是-12，而我们得到的是-6，这显然是不行的。但是幸运的是curmax刚好包括了我们需要的信息。

详细版
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curmax=1
        curmin=1
        recomax=float('-inf')
        for num in nums:
            if num<0:
                a=curmin
                b=curmax
                if b>0:
                    curmin=b*num
                else:
                    curmin=num
                if a>0:
                    curmax=num
                else:
                    curmax=a*num
            else:
                curmax=max(curmax*num,num)
                curmin=min(curmin*num,num)
            recomax=max(curmax,recomax)
        return recomax
```

简洁版
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curmax=1
        curmin=1
        recomax=float('-inf')
        for num in nums:
            if num<0:
                a=curmin
                b=curmax
                curmin=min(b*num,num)
                curmax=max(a*num,num)
            else:
                curmax=max(curmax*num,num)
                curmin=min(curmin*num,num)
            recomax=max(curmax,recomax)
        return recomax
```
极简版
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curmax=1
        curmin=1
        recomax=float('-inf')
        for num in nums:
            tmp=curmax
            curmax=max(curmax*num,curmin*num,num)
            curmin=min(tmp*num,curmin*num,num)
            recomax=max(curmax,recomax)
        return recomax
```



