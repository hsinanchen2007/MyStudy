提交了三次代码，前两次超时，第三次勉强通过，击败百分之七。
效率实在太低，实在没办法骗自己蒙混过关，于是静下心来，踏踏实实在电脑上写写画画，根据商和余数推导出规律，再提交，击败百分之99.44，成功。
主要推导过程很简单，在下面代码的注释中。
```
# 1234     求第6个排列                    4*3*2=24
# 1234     quo=6//(24//4)=1             rem=6%(24//4)=0
# 1        逆转排序234                    1432
# 12345    求第3个排列                    5*4*3*2=120
# 12345    quo=3//(120//5)=0            rem=3%(120//5)=3
# 1 2345   quo=3//(120//5//4)=0         rem=3%(120//5//4)=3
# 12 345   quo=3//(120//5//4//3)=1      rem=3%(120//5//4//3)=1
# 124 35   quo=1//(120//5//4//3//2)=0   rem=3%(120//5//4//3//2)=0
# 12345    求第6个排列                    5*4*3*2=120
# 12345    quo=6//(120//5)=0            rem=6%(120//5)=6
# 1 2345   quo=6//(120//5//4)=1         rem=6%(120//5//4)=0
# 12 345   逆转排序345                    12543
# 12345    求第30个排列                   5*4*3*2=120
# 12345    quo=30//(120//5)=1           rem=6%(120//5)=6
# 2 1345   quo=6//(120//5//4)=1         rem=6%(120//5//4)=0
# 21 345   逆转排序345                    21543
class Solution:
    def getPermutation(self, n: int, k: int):
        if n < 1 or n > 9:
            return ''

        s, nums = 1, ''
        for i in range(1, n + 1):
            s *= i
            nums += str(i)
        if k < 1 or k > s:
            return ''

        def get_nums_param(k, s, n, left, right):
            quo = k // (s // n)
            rem = k % (s // n)
            if rem == 0:
                left = left + right[quo - 1]
                right = right.replace(right[quo - 1], '')
                return left + ''.join(sorted(list(right), reverse=True))
            else:
                left = left + right[quo]
                right = right.replace(right[quo], '')
                return get_nums_param(rem, s // n, n - 1, left, right)

        return get_nums_param(k, s, n, '', nums)
```


