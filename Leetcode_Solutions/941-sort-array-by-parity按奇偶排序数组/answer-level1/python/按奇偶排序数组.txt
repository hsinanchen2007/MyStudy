#### 方法 1：排序

**想法和算法**

使用排序算法，按照模 2 的结果排序。

```Java []
class Solution {
    public int[] sortArrayByParity(int[] A) {
        Integer[] B = new Integer[A.length];
        for (int t = 0; t < A.length; ++t)
            B[t] = A[t];

        Arrays.sort(B, (a, b) -> Integer.compare(a%2, b%2));

        for (int t = 0; t < A.length; ++t)
            A[t] = B[t];
        return A;

        /* Alternative:
        return Arrays.stream(A)
                     .boxed()
                     .sorted((a, b) -> Integer.compare(a%2, b%2))
                     .mapToInt(i -> i)
                     .toArray();
        */
    }
}
```

```Python []
class Solution(object):
    def sortArrayByParity(self, A):
        A.sort(key = lambda x: x % 2)
        return A
```

**复杂度分析**

* 时间复杂度：$O(N\log N)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：排序空间为 $O(N)$，取决于内置的 `sort` 函数实现。

#### 方法 2：两边扫描

**想法和算法**

第一遍输出偶数，第二遍输出奇数。

```Java []
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] ans = new int[A.length];
        int t = 0;

        for (int i = 0; i < A.length; ++i)
            if (A[i] % 2 == 0)
                ans[t++] = A[i];

        for (int i = 0; i < A.length; ++i)
            if (A[i] % 2 == 1)
                ans[t++] = A[i];

        return ans;
    }
}
```

```Python []
class Solution(object):
    def sortArrayByParity(self, A):
        return ([x for x in A if x % 2 == 0] +
                [x for x in A if x % 2 == 1])
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。
* 空间复杂度：$O(N)$，存储结果的数组。

#### 方法 3：原地算法

**想法**

如果希望原地排序，可以使用快排，一个经典的算法。

**算法**

维护两个指针 `i` 和 `j`，循环保证每刻小于 `i` 的变量都是偶数（也就是 `A[k] % 2 == 0` 当 `k < i`），所有大于 `j` 的都是奇数。

所以， 4 种情况针对 `(A[i] % 2, A[j] % 2)`：

* 如果是 `(0, 1)`，那么万事大吉 `i++` 并且 `j--`。
* 如果是 `(1, 0)`，那么交换两个元素，然后继续。
* 如果是 `(0, 0)`，那么说明 `i` 位置是正确的，只能 `i++`。
* 如果是 `(1, 1)`，那么说明 `j` 位置是正确的，只能 `j--`。

通过这 4 种情况，循环不变量得以维护，并且 `j-i` 不断变小。最终就可以得到奇偶有序的数组。

```Java []
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int i = 0, j = A.length - 1;
        while (i < j) {
            if (A[i] % 2 > A[j] % 2) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }

            if (A[i] % 2 == 0) i++;
            if (A[j] % 2 == 1) j--;
        }

        return A;
    }
}
```

```Python []
class Solution(object):
    def sortArrayByParity(self, A):
        i, j = 0, len(A) - 1
        while i < j:
            if A[i] % 2 > A[j] % 2:
                A[i], A[j] = A[j], A[i]

            if A[i] % 2 == 0: i += 1
            if A[j] % 2 == 1: j -= 1

        return A
```
**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。循环的每一步都让 `j-i` 至少减少了一。（注意虽然快排的复杂度是 $O(N\log N)$，但是我们只需要一轮扫描就可以了）。
* 空间复杂度：$O(1)$，不需要额外空间。