### 解题思路
>1.通常我的想法都是暴力的研究数的规律，然后测试调整以通过。也就是说在没有充足的测试案例的情况下通常是有缺陷的.

循环之前加了一下判断是冗余的提升了点性能。对满足的最大小时的的十位数进行遍历，用一个map记录所有的值，做循环和异常捕捉，因为四个数字的顺序的规律，都是唯一确定的,我的算法就是取所能取得时间的极大值，每一个数字都在存在的情况下取极大值，并且可能第一位取最大值计算，后面的可能不满足时间规则，取小一点就满足了的特殊情况比如[2,0,6,6]，后三位取当前能取的极大值即可，不存在最大值，也不存在其他的可能（观察可知我也不能证明。。）
>2.暴力法，取出所有排列，过滤不合法的组合，比较选出极值,虽然python本身特性,代码比较短，但是算法本身需要穷举比较耗时,优化下提前对A排序，这样第一个合格的就是有效的最大值,有些人通过分钟数来比较思路也很好，其实list本身就可以比较，或者；利用排列本身的序*
```
ans =-1
 ans = max(ans, 60*(a*10+b) + (c*10+d))
"{:02}:{:02}".format(*divmod(ans, 60))
```
### 代码
```python3
class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        hour_ten_list = [i for i in A if i <= 2]
        res = {}
        for i in hour_ten_list:
            try:
                new = list(A)
                hour_ten = i
                new.remove(hour_ten)
                threshold = 3 if hour_ten==2 else 9
                hour_single = max([i for i in new if i<=threshold])
                print(hour_single, hour_ten)
                new.remove(hour_single)
                minute_ten = max([i for i in new if i <= 5])
                print(minute_ten)
                new.remove(minute_ten)
                minute_single = max([i for i in new if i <= 9])
                new.remove(minute_single)
                res[hour_ten] ='{}{}:{}{}'.format(hour_ten,hour_single,minute_ten,minute_single)
            except Exception as e:
                    print('exception',str(e),new)
        return res[max(res.keys())] if res else ''
```

```python3
class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:

        hour_ten_list = [i for i in A if i <= 2]
        ten_num = [i for i in A if i <= 6]

        length = len(ten_num)
        if length < 2:
            return ''
        else:
            if min(ten_num) == 2:
                if length<3:
                    return ''
                # 至少有两个小于等于3
                elif sorted(ten_num)[1]>3:
                    print(sorted(ten_num))
                    # 小时数的个位数必小于3
                    return ''
        res = {}
        for i in hour_ten_list:
            try:
                new = list(A)
                hour_ten = i
                new.remove(hour_ten)
                threshold = 3 if hour_ten==2 else 9
                hour_single = max([i for i in new if i<=threshold])
                new.remove(hour_single)
                minute_ten = max([i for i in new if i <= 5])
                new.remove(minute_ten)
                minute_single = max([i for i in new if i <= 9])
                new.remove(minute_single)
                res[hour_ten] ='{}{}:{}{}'.format(hour_ten,hour_single,minute_ten,minute_single)
            except Exception as e:
                    print('exception',str(e),new)
        return res[max(res.keys())] if res else ''
```
```python3
import itertools
from typing import List
class Solution(object):
    def largestTimeFromDigits(self, A):
        """
        暴力法罗列所有排列然后处理，过滤规则我是从数的角度考虑当然可以更抽象一点从24，小时，60分钟考虑
        :type A: List[int]
        :rtype: str
        """
        sum_list = itertools.permutations(A, 4)
        def is_valid(lst):
            if lst[0]*10+lst[1] < 24 and lst[2]*10+lst[3] < 60:
                return True
        res = list(filter(is_valid, sum_list))
        return '{}{}:{}{}'.format(*max(res)) if res else ''
```
```python3
class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        sum_list = itertools.permutations(sorted(A,reverse=1), 4)
        def is_valid(lst):
            if lst[0]*10+lst[1] < 24 and lst[2]*10+lst[3] < 60:
                return True
        # res = list(filter(is_valid, sum_list))
        for i in sum_list:
            if is_valid(i):
                return '{}{}:{}{}'.format(*i)
        return ''
```
