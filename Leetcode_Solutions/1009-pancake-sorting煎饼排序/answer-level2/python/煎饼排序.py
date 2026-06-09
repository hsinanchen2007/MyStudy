#### 方法：从大到小排序

**思路**

我们可以将最大的元素（在位置 `i`，下标从 1 开始）进行煎饼翻转 `i` 操作将它移动到序列的最前面，然后再使用煎饼翻转 `A.length` 操作将它移动到序列的最后面。  此时，最大的元素已经移动到正确的位置上了，所以之后我们就不需要再使用 `k` 值大于等于 `A.length` 的煎饼翻转操作了。

我们可以重复这个过程直到序列被排好序为止。  每一步，我们只需要花费两次煎饼翻转操作。

**算法**

我们从数组 A 中的最大值向最小值依次进行枚举，每一次将枚举的元素放到正确的位置上。

每一步，对于在位置 `i` 的（从大到小枚举的）元素，我们会使用思路中提到的**煎饼翻转组合操作**将它移动到正确的位置上。  值得注意的是，执行一次煎饼翻转操作 `f`，会将位置在 `i, i <= f` 的元素翻转到位置 `f+1 - i` 上。

```java [uXAyrLqR-Java]
class Solution {
    public List<Integer> pancakeSort(int[] A) {
        List<Integer> ans = new ArrayList();
        int N = A.length;

        Integer[] B = new Integer[N];
        for (int i = 0; i < N; ++i)
            B[i] = i+1;
        Arrays.sort(B, (i, j) -> A[j-1] - A[i-1]);

        for (int i: B) {
            for (int f: ans)
                if (i <= f)
                    i = f+1 - i;
            ans.add(i);
            ans.add(N--);
        }

        return ans;
    }
}
```
```python [uXAyrLqR-Python]
class Solution(object):
    def pancakeSort(self, A):
        ans = []

        N = len(A)
        B = sorted(range(1, N+1), key = lambda i: -A[i-1])
        for i in B:
            for f in ans:
                if i <= f:
                    i = f+1 - i
            ans.extend([i, N])
            N -= 1

        return ans
```


**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是数组 `A` 的长度。

* 空间复杂度：$O(N)$。



