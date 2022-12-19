
本题是滑动窗口的经典题，
主要思路是，
1. 遍历数组时，在窗口中一次添加一个数字。
2. 记录当前窗口中的最大重复1（使用max_repeat_count记录）。 
3. 因此，窗口中记录了1的个数，我们应该尝试替换窗口中剩下的0。 
4. 如果剩余的0个数大于K，则需要缩小窗口，因为替换的个数不能超过K个0。

代码如下：

```python []
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        window_start = 0
        output = 0
        max_repeat_count = 0
        for window_end in range(len(A)):
            num = A[window_end]
            if num == 1:
                max_repeat_count += 1
            if window_end - window_start + 1 - max_repeat_count > K:
                if A[window_start] == 1:
                    max_repeat_count -= 1
                window_start += 1
            output = max(output, window_end - window_start + 1)
        return output
```

