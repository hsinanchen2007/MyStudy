### 解题思路
三种解法：
法1：思路：假设n个硬币可以排成等差k行（第K行个数不够），那么累加前k-1行的硬币的和为sum，
            然后n-sum就是最后一行的硬币个数，那么最后一行的硬币个数必然小于等于前一行的个数，
            并且sum也必然小于等于总硬币个数n
        sum = 0
        if n <2:
            return n
        else:
            for i in range(1,n+1):
                sum += i
                if sum <=n and n - sum <= i:
                    return i
                i += 1
        

法二：思路：就是一个首项为1，公差为1的等差数列求和公式，具体数学过程看这里：https://leetcode-cn.com/problems/arranging-coins/solution/mo-ni-shu-xue-by-powcai/

之所以用int包围结果，是为了防止如果算出来的x为小数，那么就只取整数部分。
        return int(((8 * n + 1) ** 0.5 - 1) // 2)

法三：思路：如下，第一行所以为1，第二行索引为2......也就是索引号就等于该行的硬币数量（最后一行除外）
当索引指向第二行时，此时总数n为减去第一行后的数量；
然后索引指向第三行，此时总数n为减去第二行后的数量；
然后索引指向第四行，此时总数n为减去第三行后的数量；
当发现索引号和该行的硬币数量不相等时，那么说明遍历到头了，前一行就是要求的行数。
① o 
② o o
③ o o o
④ o o

        i = 1
        while n -i >= 0:
            n -=i
            i +=1
        return i-1

### 代码

```python3
class Solution:
    def arrangeCoins(self, n: int) -> int:
        return int(((8 * n + 1) ** 0.5 - 1) // 2)

            
```