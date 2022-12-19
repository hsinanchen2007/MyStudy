### 解题思路
参见高赞题解。
 先统计只出现一个5： 5,10,15,20, 25, 30, ...
 统计出现 2 个 5， 25,50,75,100,125, ...
 统计出现 3 个 5： 125, 250, 375, ...
 这有点像 [233. 数字 1 的个数](https://leetcode-cn.com/problems/number-of-digit-one/)对于 “11”，统计个位上的 1，count+=1,然后统计十位上的 “1”，count+=1

### 代码

```python3
class Solution:
    def trailingZeroes(self, n: int) -> int:
        # a2, a5 = 0, 0
        # for x in range(1, n+1):
        #     if x%2 == 0:
        #         while x>0 and x%2==0:
        #             x = x//2
        #             a2 += 1
        #     if x>0 and x%5 == 0:
        #         while x>0 and x%5 == 0:
        #             x = x//5
        #             a5 += 1
        # return min(a2, a5)   # 1808548329 算法太慢，这个没有解. 这个题是个数学题，要自己思考，可以减少复杂度。

        a5 = 0
        # 先统计只出现一个5： 5,10,15,20, 25, 30
        # 统计出现 2 个 5， 25,50,75,100,125，
        # 统计出现 3 个 5： 125, 250, 375，
        # 这有点像对于 “11”，统计个位上的 1，count+=1,然后统计十位上的 “1”，count+=1
        k = 5
        while k<=n:
            a5 += n//k
            k = 5*k
        return a5

```