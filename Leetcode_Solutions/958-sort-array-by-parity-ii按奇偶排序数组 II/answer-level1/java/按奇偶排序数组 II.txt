#### 方法一： 两次遍历

**思路和算法**

遍历一遍数组把所有的偶数放进 `ans[0]`，`ans[2]`，`ans[4]`，依次类推。

再遍历一遍数组把所有的奇数依次放进 `ans[1]`，`ans[3]`，`ans[5]`，依次类推。

```java [solution1-Java]
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int N = A.length;
        int[] ans = new int[N];

        int t = 0;
        for (int x: A) if (x % 2 == 0) {
            ans[t] = x;
            t += 2;
        }

        t = 1;
        for (int x: A) if (x % 2 == 1) {
            ans[t] = x;
            t += 2;
        }

        return ans;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def sortArrayByParityII(self, A):
        N = len(A)
        ans = [None] * N

        t = 0
        for i, x in enumerate(A):
            if x % 2 == 0:
                ans[t] = x
                t += 2

        t = 1
        for i, x in enumerate(A):
            if x % 2 == 1:
                ans[t] = x
                t += 2

        # We could have also used slice assignment:
        # ans[::2] = (x for x in A if x % 2 == 0)
        # ans[1::2] = (x for x in A if x % 2 == 1)

        return ans
```

**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 是 `A` 的长度。

* 空间复杂度： $O(N)$。


#### 方法二： 双指针

**思路**

我们可能会被面试官要求写出一种不需要开辟额外空间的解法。

在这个问题里面，一旦所有偶数都放在了正确的位置上，那么所有奇数也一定都在正确的位子上。所以只需要关注 `A[0], A[2], A[4], ...` 都正确就可以了。

将数组分成两个部分，分别是偶数部分 `even = A[0], A[2], A[4], ...` 和奇数部分 `odd = A[1], A[3], A[5], ...`。定义两个指针 `i` 和 `j`, 每次循环都需要保证偶数部分中下标 `i` 之前的位置全是偶数，奇数部分中下标 `j` 之前的位置全是奇数。

**算法**

让偶数部分下标 `i` 之前的所有数都是偶数。为了实现这个目标，把奇数部分作为暂存区，不断增加指向奇数部分的指针，直到找到一个偶数，然后交换指针 `i`，`j` 所指的数。

```java [solution2-Java]
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int j = 1;
        for (int i = 0; i < A.length; i += 2)
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1)
                    j += 2;

                // Swap A[i] and A[j]
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }

        return A;
    }
}
```

```python [solution2-Python]
class Solution(object):
    def sortArrayByParityII(self, A):
        j = 1
        for i in xrange(0, len(A), 2):
            if A[i] % 2:
                while A[j] % 2:
                    j += 2
                A[i], A[j] = A[j], A[i]
        return A
```

**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 是 `A` 的长度。

* 空间复杂度： $O(1)$。