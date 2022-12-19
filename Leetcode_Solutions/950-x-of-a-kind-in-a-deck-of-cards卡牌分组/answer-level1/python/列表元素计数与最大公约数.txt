### 解题思路
（1）文字思路
给定deck列表，计算每个元素出现次数，如果不同元素拥有一个最大公约数（大于1），说明他们可以最大公约数为单位进行捆绑。
（2）所用函数
**第一部分**，collections模块下的Counter()以字典形式呈现deck列表中元素出现的次数，之后字典使用values()方法即可获取每个元素出现的次数并以dict_values形式呈现，此时需要传递给list()，返回类型即为列表形式。参考链接：
https://blog.csdn.net/itanders/article/details/87882229?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task

**第二部分**，最大公约数求法。首先在math模块下存在gcd()函数，用于求两个数的最大公约数，且只能为两个数，参考链接为：
https://blog.csdn.net/AndesStay/article/details/82527026?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522158528836019725211923135%2522%252C%2522scm%2522%253A%252220140713.130056874..%2522%257D&request_id=158528836019725211923135&biz_id=0&utm_source=distribute.pc_search_result.none-task
那么，deck中可能存在多于两个元素，求多个数的最大公约数需借助functools模块下的reduce()函数，逻辑是内置函数和被使用范围两个参数，内置函数顺序作用于范围参数，使用一次去除被使用数，返回函数求值并作为初始值，然后继续使用函数作用于后续范围参数。参考链接为：
https://blog.csdn.net/joker_hapy/article/details/83447738?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task

举个例子：如果元素次数列表为[4,6,12,16],先math.gcd(4,6),返回最大公约数2并作为初始值，然后math.gcd(2,12)，返回最大公约数2.再是math.gcd(2,16)返回最终值2


### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        import collections
        import math
        from functools import reduce
        return False if reduce(math.gcd, list(collections.Counter(deck).values())) < 2 else True


```