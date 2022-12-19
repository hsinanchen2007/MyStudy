### 解题思路
1. 至少有一位重复的数字的个数=N-没有重复字符的数字的个数
2. 设数字N有W位，则需要除去所有位数为1到W的数字中没有重复字符的数字
3. 计算W位数字中小于N且没有重复的字符的数字的个数可以递归求得

### 代码

```python3

class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:

        def non_dup_of_n_digits(n):
            """
            长度为n的数字中，没有重复字符的数字的个数
            :param n: 
            :return: 
            """
            if n < 1:
                return 0

            if n == 1:
                return 9
            
            x = 9
            for i in range(n-1):
                x *= 9-i
            return x

        v = N
        digits, num = 0, [] # digits是数字的位数，num是用数组表示数字
        while v > 0:
            digits += 1
            num.append(v % 10)
            v //= 10
        num = num[::-1]

        def non_dup_of_num(num, index, used):
            if not num:
                return 0

            if len(num) == 1:
                return num[0]

            val = num[index]
            if index == digits - 1:
                # 如果是最后一位，可以选取0-9中没有使用过的数字
                return len([x for x in range(0, val + 1) if x not in used])

            # 如果是第一位，不能选0。
            # 如果不是第一位，可以选取中没有使用过的，小于当前数字的数字， 后面不管怎么选都小于N
            count = len([x for x in range(0 if index > 0 else 1, val) if x not in used])
            for i in range(len(num)-index-1):
                count *= 9-i-len(used)

            # 如果选取和当前位一样的数字，继续
            return count + (non_dup_of_num(num, index+1, used | {val}) if val not in used else 0)
        
        # 总共N个数字，减去位数较小的数字中没有重复字符的数字个个数，再减去位数和N一样的数字中没有重复字符的数字的个数
        ans = N - sum([non_dup_of_n_digits(i) for i in range(digits)]) - non_dup_of_num(num, 0, set())

        return ans
```