```
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        if n < 0:
            n = n & 0xffffffff
            
        while n:
            n = n & (n - 1)
            count += 1
   # 注释掉的这一块也可以运行，但是效率没有上一个高，毕竟除法运算效率比移位运算低得多。     
        # while n:
            # if n % 2 == 1:
                # count += 1
            # n >>= 1
        return count


```