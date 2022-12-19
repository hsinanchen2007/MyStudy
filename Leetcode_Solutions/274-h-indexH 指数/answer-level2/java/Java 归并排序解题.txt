### 解题思路

思路:

1. 从大到小排序  这里我用的是 归并排序
2. 排序之后检查 h 指数

### 代码

```java
class Solution {
    /**
     * 思路:
     * 1. 从大到小排序  这里我用的是 归并排序
     * 2. 排序之后检查 h 指数
     */
    public int hIndex(int[] citations) {
        if (citations.length == 0) {
            return 0;
        }
        int[] aux = new int[citations.length];
        sort(citations, aux, 0, citations.length - 1);
        int max = citations[0] > citations.length ? citations.length : citations[0];
        for (int h = max; h > 0; h--) {
            // 至多有 h 篇论文分别被引用了至少 h 次。
            if (citations[h - 1] >= h) {
                return h;
            }
        }
        return 0;
    }

    /**
     * 这里使用 merge sort 练练手
     */
    private static void sort(int[] a, int[] aux, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        int mid = (lo + hi) / 2;
        sort(a, aux, lo, mid);
        sort(a, aux, mid + 1, hi);
        merge(a, aux, lo, mid, hi);
    }

    private static void merge(int[] a, int[] aux, int lo, int mid, int hi) {
        System.arraycopy(a, lo, aux, lo, hi - lo + 1);
        int i = lo;
        int j = mid + 1;
        int k = lo;
        while (k <= hi) {
            if (i > mid) {
                a[k++] = aux[j++];
            } else if (j > hi) {
                a[k++] = aux[i++];
            } else if (aux[i] > aux[j]) {
                // 从大到小排序
                a[k++] = aux[i++];
            } else {
                a[k++] = aux[j++];
            }
        }
    }

}
```