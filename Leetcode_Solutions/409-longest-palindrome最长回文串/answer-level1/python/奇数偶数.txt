### 解题思路
各元素统计值
 除了第一个最小奇数，奇数全部减1
剩下偶数的统计值全部相加

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        # 收集所有奇数，并找到最小奇数
        # 收集所有偶数
        num_dict = dict()
        # odd_dict, even_dict = dict(), dict()
        for _ in s:
            if _ not in num_dict.keys():
                num_dict[_] = 1
            else:
                num_dict[_] += 1
        flag, odd, even  = 0, 0, 0
        oddList=[_ for _ in num_dict.values() if _%2!=0 ]
        least_odd = min(oddList) if len(oddList)>=1 else 0
        for v in num_dict.values():
            if least_odd != 0 and v==least_odd and flag == 0:
                odd = odd + v
                flag = 1
            elif v%2 != 0:
                odd = odd+v-1
            elif v%2 == 0:
                even = even+v
        result = odd + even
        return result
```