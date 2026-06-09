
**测试用例：**

* 功能测试：\[1, 2, 5\], 12
* 性能测试：\[227, 99, 328, 299, 42, 322\], 9847
* 边界测试：\[1, 2\], 0 (ans=0)
* 负面测试：

## 方法：回溯+贪心

- 利用贪心的思路，先用大的硬币凑，因此先将coins按从大到小排序。
- 利用回溯法的模板：backward(count, amount\_last, idx)
	- count表示当前已经有多少硬币了，amount\_last表示当前剩余金额，idx表示目前以哪个硬币为最大硬币进行尝试
	- n=amount\_last // coins\[idx\]表示当前最大硬币能够最多利用多少次，将当前余额分别尝试减去n个coins\[idx\]，n-1个coins\[idx\]，...，0个coins\[idx\]，这个循环的数量记为i
	- 剪枝条件1：如果对于当前剩余的金额amount\_last，idx所指的硬币直接就能使余额为0，则进行剪枝，amount\_last // coins\[idx\]以下个数的coins\[idx\]搜索得到的硬币数一定比当前的硬币数大，例子：\[1,5,10\] 20，在尝试过10,10以后（注意此处都是元素10）就没有必要尝试10, 5, 5了
	- 剪枝条件2：如果将当前数量i与已有硬币数量count加和以后，已经比当前最优值+1还大了，那么不要继续尝试了，因为继续尝试意味着硬币数至少要加1，意味着这条路径下去的解顶多与现在的最优解相同

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0: return 0

        global min_count
        min_count = float('inf')
        coins.sort(reverse=True)

        def backward(count, amount_last, idx):
            global min_count
            if idx >= len(coins):
                return
            for i in range(amount_last // coins[idx], -1, -1):
                new_amount_last = amount_last - i * coins[idx]
                new_count = count + i
                if new_amount_last == 0:
                    min_count = min(min_count, new_count)
                    break
                if new_count >= min_count - 1:
                    break
                backward(new_count, new_amount_last, idx+1)
                
        backward(0, amount, 0)
        ans = min_count if min_count != float('inf') else -1
        return ans
```

**复杂度分析：**

* 时间复杂度：O(n2)
* 空间复杂度：O(n)