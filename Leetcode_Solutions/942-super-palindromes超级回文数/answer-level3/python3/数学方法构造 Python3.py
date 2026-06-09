**思路：**

从1产生回文数，把产生的回文数平方，判断平方后是不是回文数并在 `[L, R]` 内。

由于超级回文数的个数十分有限，所以也可以打表解决。

时间复杂度 $O(\sqrt{N})$

空间复杂度 $O(1)$

**代码：**

```python
class Solution:
    def superpalindromesInRange(self, L, R):
        """
        :type L: str
        :type R: str
        :rtype: int
        """
        def is_circle(num):
            s = str(num)
            return s == s[::-1]

        def create_circle(num):
            s = str(num)
            first = int(s + s[::-1])
            second = int(s[:-1] + s[::-1])
            return first, second

        l = int(math.sqrt(int(L)))
        r = int(math.sqrt(int(R))) + 1
        # print(l, r)
        ans = 0
        for num in range(1, 100000):
            # print(num)
            big, small = create_circle(num)
            # print(big, small)
            if l <= small < r:
                if is_circle(small * small):
                    ans += 1
            if l <= big < r:
                if is_circle(big * big):
                    ans += 1
            if small > r:
                break
        return ans
```