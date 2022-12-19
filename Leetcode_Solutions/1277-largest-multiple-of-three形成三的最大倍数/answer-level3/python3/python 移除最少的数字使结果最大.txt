### 解题思路
先将数组按降序排列，然后从数组尾部移除多余的数字，然后拼接。

#### 排序
要让数最大，则各位上的数字必然是降序排列。

#### 移除
一个数能被3整除则各位上的数字之和能被3整除。那么，移除若干模3余1或2的数字可以让组成的数能被3整除。  
位数越高，结果越大。为了使结果最大，必须要尽可能少地移除数字；尽可能移除更小的数字，即从（排序后的）数组尾部开始移除。  
因为3个余1的数或3个余2的数和能被3整除，所以以下我们从个数模3的结果考虑。  

>记one, two为数组中模3余1或2的数字的个数  
>one_3, two_3为one % 3, two % 3  

对于数字的移除，考虑如下几种情况
- one_3 == two_3, 不需要移除任何数字(1+2=3)
- one_3 - two_3 == 1, 需要移除多余的1个余1的数
- two_3 - one_3 == 1, 需要移除多余的1个余2的数
- two_3 - one_3 == 2, 余2的数字多了
    - one > 0, 可以移除一个余1的数，这样使得one_3 == 2 == two_3
    - one == 0, 没有余1的数，只能移除两个余2的数
- one_3 - two_3 == 2, 余1的数字多了
    - two > 0, 可以移除一个余2的数，这样使得one_3 == 2 == two_3
    - two == 0, 没有余2的数，只能移除两个余1的数

#### 拼接
拼接时需要考虑
- 数组为空, 无法组成任何数字，直接返回空字符串
- 数组中只剩下0, 直接返回字符串0, 防止产生多余的前导0
- 其他情况正常把降序后的数字逐个拼接返回即可

### 代码

```python3
class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        # 降序排列
        digits.sort(reverse=True)
        # 移除多余的数字
        n = len(digits)
        one, two = sum(d % 3 == 1 for d in digits), sum(d % 3 == 2 for d in digits)
        one_3, two_3 = one % 3, two % 3
        if one_3 != two_3:
            if two_3 - one_3 == 1 or one_3 + two_3 == 2 and (one == 0 or two_3 == 0 and two > 0):
                # 需要移除的个数
                c = 2 if one == 0 and two_3 == 2 else 1
                # 移除余2的数
                r = 2
            else:
                # 需要移除的个数
                c = 2 if two == 0 and one_3 == 2 else 1
                # 移除余1的数
                r = 1
            
            for i in range(n - 1, -1, -1):
                if digits[i] % 3 == r:
                    c -= 1
                    digits.pop(i)
                    if c <= 0:
                        break
        # 空数组
        if not digits:
            return ''
        # 数组中只剩下0（降序排列）
        if digits[0] == 0:
            return '0'
        # 拼接返回
        return ''.join(map(str, digits))

```