one某位为1   表示该位出现1的次数为3k+1次。
two某位为1   表示该位出现1的次数为3k+2次。
three某位为1 表示该位出现1的次数为3k次。

# **每次得到新的num更新one有2种情况。**
**1.在新num中某位为1，且原先出现了3次。(已经出现3次为1的位再次在num中为1)
2.在新num中某位为0，且原先出现1次。  (已经出现1次为1的位再次在num中为0)**
代码为：new_one =  (three&num)|(one&~num)
three&num某一位在three中为1且在num中为1。则同时出现。为情况1
one&~num某一位在one中为1，在num中为0。情况2
组合2种情况。new_one =  (three&num)|(one&~num)得出所有为1的位，即出现1次的位

# 注意：
某1位只可能在one,two,three其中1个位置上为1.且必须有1个为1.
如不可能出现：
one =  0b0001
two =  0b0011
three= 0b1100
即在最后一位上，既出现了1次又出现了2次。（one和two的最后以为都为1）
换句话说，one,two,three种对应的位上，有且只有1个位1（某一位出现1的次数肯定是1，2，3中的1种.初始状态three全为1，即下1个出现的数字（通过1.在新num种出现，且原先出现了3次。）对应位可转换到1次。)


# 类似的。
**new_one =  (three&num)|(one&~num)
new_two =  (one&num)|(two&~num)
new_three =  (two&num)|(three&~num)**



```


class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        one,two,three = 0,0,~0
        #初始状态three=~0每一位全为1，这样新出现的数字便可转移至one
        for num in nums:
            denum = ~num
            new_one =  (three&num)|(one&denum)
            new_two =  (one&num)|(two&denum)
            new_three =  (two&num)|(three&denum)
            
            one,two,three = new_one,new_two,new_three
        return one
```