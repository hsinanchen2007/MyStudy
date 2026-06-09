#### 方法一：双指针【通过】

**思路**

一般情况下，一座山脉只能在前一座山脉结束后开始。

如果一座山脉从前一座山脉的山顶左边开始，那么此山脉长度一定小于前一座山脉。如果它从前一座山脉的山顶右边开始，那么它无法形成山脉。

**算法**

假设一座山脉的起始索引为 `base`，山脉为 `A[base], A[base+1], ..., A[end]`。

如果存在这样一座山脉，那么下一座山脉的起始索引为 `base = end`。如果不存在以 `base` 起始的山脉，要么是到了数组末尾，要么是因为 `A[base] > A[base+1]`，山脉的起始索引为 `base + 1`。 

**例子**

一个数组为 `A = [1, 2, 3, 2, 1, 0, 2, 3, 1]` 的例子。

![](https://pic.leetcode-cn.com/Figures/845/diagram1.png){:width=400}

`base` 从 `0` 开始，第一个 `while` 循环结束的时候到达山顶 `end = 2, (A[end] = 3)`，第二个 `while` 循环结束的时候到达山底 `end = 5, (A[end] = 0)`。记录当前山脉长度为 6`(base = 5, end = 8)`。

然后，令 `base = 5` 寻找新的山脉，找到第二个山脉的长度为 4`(base = 5, end = 8)`。

```java [solution1-Java]
class Solution {
    public int longestMountain(int[] A) {
        int N = A.length;
        int ans = 0, base = 0;
        while (base < N) {
            int end = base;
            // if base is a left-boundary
            if (end + 1 < N && A[end] < A[end + 1]) {
                // set end to the peak of this potential mountain
                while (end + 1 < N && A[end] < A[end + 1]) end++;

                // if end is really a peak..
                if (end + 1 < N && A[end] > A[end + 1]) {
                    // set end to the right-boundary of mountain
                    while (end + 1 < N && A[end] > A[end + 1]) end++;
                    // record candidate answer
                    ans = Math.max(ans, end - base + 1);
                }
            }

            base = Math.max(end, base + 1);
        }

        return ans;
    }
}

```

```python [solution1-Python]
class Solution(object):
    def longestMountain(self, A):
        N = len(A)
        ans = base = 0

        while base < N:
            end = base
            if end + 1 < N and A[end] < A[end + 1]: #if base is a left-boundary
                #set end to the peak of this potential mountain
                while end+1 < N and A[end] < A[end+1]:
                    end += 1

                if end + 1 < N and A[end] > A[end + 1]: #if end is really a peak..
                    #set 'end' to right-boundary of mountain
                    while end+1 < N and A[end] > A[end+1]:
                        end += 1
                    #record candidate answer
                    ans = max(ans, end - base + 1)

            base = max(end, base + 1)

        return ans
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组 `A` 的长度。

* 空间复杂度：$O(1)$。