# 解题思路：
根据题意，要对x乘n次，如果用直接遍历n次，那么复杂度为O(n)，考虑二分查找的思想，每次x *= x，那就是成倍地增加，复杂度为O(logn)
因此，只需要一边记录x累乘的结果，一边记录累乘的次数，当累乘次数的两倍大于n时，n减去此次的累乘次数，再对剩余的幂次进行递归，将每次递归的累乘结果都累乘，作为返回。
最后，再考虑符号问题。
注意：首次调用递归时要对x和n取绝对值

# 解题步骤：
## 一、反向二分查找
定义一个计数器count，用于比较与n的大小
定义sum来记录当前的结果
1. 判断n < 1 ？ 返回 1
2. 初始化count=1， sum=x
3. Repeat（count * 2 <= n）：
        count += count
        sum *= sum
4. n -= count
5. return 递归(x, n) * sum

## 二、根据符号对结果进行处理
如果x为负数且n是奇数，那么res添加一个负号
如果n为负数，那么res

![1.png](https://pic.leetcode-cn.com/34cd40c9ee8fbfe1a4e2176eabe61ba928217d7df51018b2493d712597a59403-1.png)
```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        def re_binarysearch(x, n): # 逆向二分查找
            # 递归出口
            if n < 1:
                return 1
            count, sum = 1, x  # 初始化
            # 二分查找
            while count * 2 <= n:
                count += count  # 计数器翻倍
                sum *= sum  # 累乘
            return re_binarysearch(x, n-count) * sum  # 返回累乘结果
        
        res = re_binarysearch(abs(x), abs(n))  # 调用二分查找，传入绝对值
        # 符号处理
        res = -res if x < 0 and n % 2 != 0 else res
        res = 1/res if n < 0 else res
        return res
```
