思路一共分三步。
1. 将所有数相加，记录总和，如果被三整除即可直接返回。
2. 剩下除以3余1和余2两种情况，分别讨论。
3. 如果除以3余1，可以删除最小一个余1的数，或删除最小两个余2的数；如果除以3余2，可以删除最小一个余2的数，或删除最小两个余1的数。
于是我们可以这样实际操作：
- 遍历数组，将所有数按照除以3的余数分类。
- 将整除3的所有数相加。
- 对剩下两组进行排序。
- 按照总和除以3的余数，列举可能的两种删除方法，如果余1和余2的数数量不足，则无法做到，返回0。
- 比较删除方法结果的大小即可。


-----------------------------------
评论区有人看不懂，那我举个例子吧。
原数组`nums = [1, 6, 7, 11, 3, 5, 65, 987, 12, 43, 8, 55, 34, 654, 2, 77]`，总和为1970，`1970 % 3 = 2`.
按照模3余数分类并排序后：
```
zeros = [3, 6, 12, 654, 987]
ones = [1, 7, 34, 43, 55]
twos = [2, 5, 8, 11, 65, 77]
```
面对余2的总和有两种操作办法：
- 去掉最小一个余2的数，`2`.
- 去掉最小两个余1的数，`1+7`.


对这两种做法进行比较，`1+7 > 2`，所以选择去掉2，最后的结果即为`1970 - 2 = 1968`.

-----------------------------------

代码在这里：
```python []
class Solution:

    def maxSumDivThree(self, nums) -> int:
        
        all_sum = sum(nums)
        r = all_sum % 3
        if r == 0:
            return all_sum
        
        ones = list()
        twos = list()
        for num in nums:
            if num % 3 == 0:
                continue
            elif num % 3 == 1:
                ones.append(num)
            else:
                twos.append(num)
        ones.sort()
        twos.sort()

        subtract = list()
        if r == 1:
            if ones:
                subtract.append(ones[0])
            if len(twos) >= 2:
                subtract.append(sum(twos[:2]))
            if not subtract:
                return 0
            else:
                return all_sum - min(subtract)
        else:
            if twos:
                subtract.append(twos[0])
            if len(ones) >= 2:
                subtract.append(sum(ones[:2]))
            if not subtract:
                return 0
            else:
                return all_sum - min(subtract)
        
```
点个赞再走呗~