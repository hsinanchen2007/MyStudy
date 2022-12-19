### 解题思路
#### 快排
##### 思路
按照`pivot`的值，把区间`[l, r]`分成两部分，前一部分的值都小于等于`pivot`，后一部分的值都大于`pivot`。
**一次操作后，`pivot`的位置固定**，然后再递归的去排序被`pivot`分割的这两部分区间。

区间`[l, r]`, 按照`pivot` 的值分割成两部分。$values_{i-1}=pivot$
 * $[values_{l}, values_{i-1}]$ 都小于等于`pivot`，
 * $[values_{i}, values_{r}]$ 都大于`pivot`。

##### 复杂度分析
* 时间复杂度： $O(NlogN)$ ~ $O(N^2)$
* 空间复杂度： $O(logN)$

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        sort(nums, 0, nums.length-1);
        return nums;
    }

    public long sort(int[] values, int l, int r) {
        long compareTime = r - l;
        int pivot = choosePivot(values, l, r);
        int i = l + 1;
        int j = l + 1;
        for (; j <= r; ++j) {
            if (values[j] <= pivot) {
                exchange(values, i, j);
                ++i;
            }
        }
        exchange(values, l, i - 1);
        if (l < i - 1) {
            compareTime += sort(values, l, i - 2);
        }
        if (i < r) {
            compareTime += sort(values, i, r);
        }
        return compareTime;
    }

    private void exchange(int[] values, int a, int b) {
        int tmp = values[a];
        values[a] = values[b];
        values[b] = tmp;
    }

    private int choosePivot(int[] values, int l, int r) {
        // 为了避免排序一个已经有序的数组，时间复杂度退化为 N^2
        // 随机那三个值，选择一个中间值作为 pivot 分割点
        int mid = (l + r) / 2;
        int min = l, max = l;
        if (values[min] > values[mid]) {
            min = mid;
        }
        if (values[min] > values[r]) {
            min = r;
        }
        if (values[max] < values[mid]) {
            max = mid;
        }
        if (values[max] < values[r]) {
            max = r;
        }
        if (mid != min && mid != max) {
            exchange(values, l, mid);
        } else if (r != min && r != max) {
            exchange(values, l, r);
        }
        return values[l];
    }
}
```