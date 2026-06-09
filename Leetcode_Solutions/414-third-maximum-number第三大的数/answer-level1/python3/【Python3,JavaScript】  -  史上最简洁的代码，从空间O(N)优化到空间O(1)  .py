
# O(N) 空间复杂度的解法

一个简单的做法是先去重，然后我们进行一次遍历，并使用三个变量a，b，c 分别表示最大值，次大值和第三大的数。 

- 如果当前元素比a大，则说明其一定比b和c都大。 我们同时更新b和c的值。 具体来说就是将b更新到c，a更新到b（可以形象地考虑成冒泡）。
- 否则我们继续判断是否比b大，如果比b大，那么肯定也比c大，我们同时需要更新c的值。 
- 如果都不比a和b大，我们继续判断是否比c大，如果是，我们更新c的值

我们初始化a，b，c为 负无穷。 这样我们最后只要判断c是不是负无穷即可，如果是负无穷我们返回a，否则我们返回c。
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {
    let a = b = c = -1 * Infinity
    nums = [...new Set(nums)]

    for(const num of nums) {
        if (num > a) {
            c = b
            b = a
            a = num
        } else if (num > b) {
            c = b
            b = num
        } else if (num > c) {
            c = num
        }
    }

    return Number.isFinite(c) ? c : a 
    
};
```
```python []
from math import isinf


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = list(set(nums))
        a = b = c = float('-inf')

        for num in nums:
            if num > a:
                c = b
                b = a
                a = num
            elif num > b:
                c = b
                b = num
            elif num > c:
                c = num

        return a if isinf(c) else c
```

**复杂度分析**

- 时间复杂度: 我们使用了一次循环，因此空间复杂度为$O(N)$
- 空间复杂度: 由于我们使用了set来去重，因此空间复杂度为$O(N)$


# O(1) 空间复杂度的解法

上述代码有优化的空间，实际上我们根本没有必要去重。我们只需要在后面的两个elif中判断其是否和a，b相等即可。

```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {
    let a = b = c = -1 * Infinity

    for(const num of nums) {
        if (num > a) {
            c = b
            b = a
            a = num
        } else if (num > b && num !== a) {
            c = b
            b = num
        } else if (num > c && num !== a && num !== b) {
            c = num
        }
    }

    return Number.isFinite(c) ? c : a 
    
};
```
```python []
from math import isinf


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        a = b = c = float('-inf')

        for num in nums:
            if num > a:
                c = b
                b = a
                a = num
            elif num > b and num != a:
                c = b
                b = num
            elif num > c and num != b and num != a:
                c = num

        return a if isinf(c) else c
```

**复杂度分析**

- 时间复杂度: 我们使用了一次循环，因此时间复杂度为$O(N)$
- 空间复杂度: $O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/8302a8c8989edaf066d13bc86549fbd29b6b33f922f7ed071c9521146ede5db5.jpg)


