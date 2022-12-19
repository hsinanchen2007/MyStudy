### 解题思路
对于所有位数为n的的数字，所有的confusing number的数量，是有算数解的，具体见sum_bit_n函数，可以用排列组合推导一下

给定位数为bit_N的N，先计算[0, bit_N-1]位数的confusing number的算数解，然后再依次判断从小到大直到N为止的位数为bit_N的数字是否为confusing number

### 代码

```python
from math import log10

class Solution(object):
    def confusingNumberII(self, N):
        """
        :type N: int
        :rtype: int
        """
        rotation = {
            '0': '0',
            '1': '1',
            '6': '9',
            '8': '8',
            '9': '6'
        }

        def is_confusing(number):
            length = len(number)
            rotated = [rotation.get(number[i]) for i in range(length-1, -1, -1)]
            if ''.join(number) == ''.join(rotated):
                return False
            return True


        def sum_bit_n(number_digit):

            if number_digit == 0:
                return 0
            if number_digit == 1:
                return 2
            if number_digit % 2 == 0:
                return 5**(number_digit-1)*4 - 5**((number_digit-2)/2)*4
            return 5**(number_digit-1)*4 - 5**((number_digit-3)/2)*12
        
        def population(size):

            pool = [list('01689')] * (size-1)
            pool.append(list('1689'))
            count = 0
            total = 4 * 5 **(size-1)
            while count < total:
                yield tuple(pool[i][count/(5**i)%5] for i in reversed(range(size)))
                count += 1
            

        bit_N = len(str(N))
        bit_N = int(bit_N)
        count = sum([sum_bit_n(i) for i in range(1, bit_N)])
        for comb in population(bit_N):
            # print(comb, count)
            if comb[0] == '0':
                continue
            if int(''.join(comb)) > N:
                return count
            if is_confusing(comb):
                count += 1
        return count
        

```