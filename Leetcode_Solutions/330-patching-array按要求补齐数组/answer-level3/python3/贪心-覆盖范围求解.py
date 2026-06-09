### 解题思路
![image.png](https://pic.leetcode-cn.com/e42d11cc199bcdf3bc01faa09246ab2fe2d846f3f512786de3ba768d57a2a055-image.png)

-   贪心法

尽量利用数组中的元素去覆盖更多的范围，如果不能覆盖，就增加范围之外的一个数字，扩大覆盖范围

-   设置一个变量`current_coverage`表示当前的数字能够表示的范围，我们希望能够尽量利用数组中的数字，使得覆盖范围大于等于`n`



```
初始值：
    current_coverage = 0    覆盖0
    
然后开始判断，数组中提供的元素是否小于等于 current_coverage+1？
如果是，表示覆盖范围可以向前扩展
如果不是，那么数字current_coverage+1 不能被覆盖，这时候就需要新增这个数字，同时向后扩展覆盖范围，直到范围大于等于n截止
```

### 代码

```python3
class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        ans = 0
        current_coverage = 0
        length = len(nums)
        pos = 0
        while current_coverage < n:
            if pos < length:
                if nums[pos] <= current_coverage + 1:
                    current_coverage += nums[pos]
                    pos += 1
                else:
                    ans += 1
                    current_coverage += current_coverage + 1
            else:
                ans += 1
                current_coverage += current_coverage + 1

        return ans
```