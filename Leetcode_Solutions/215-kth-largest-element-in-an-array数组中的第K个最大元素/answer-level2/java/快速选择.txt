### 解题思路
    切分完毕之后，第k大的元素就放在k-1位置上。

### 代码

```java


class Solution {
    static void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    int partition_kr(int[] a, int left, int right) {
        int i, last;

        swap(a, left, (left + right) / 2);
        last = left;
        for (i = left + 1; i <= right; i++)
            if (a[i] > a[left])
                swap(a, i, ++last);
        swap(a, left, last);
        return last;
    }

    public int findKthLargest(int[] nums, int k) {
        int left = 0;
        int right = nums.length - 1;
        
        while (left < right) {
            int i = partition_kr(nums, left, right);
            if (i == k - 1)
                break;
            else if (i < k - 1)
                left = i + 1;
            else
                right = i - 1;
        }
        return nums[k - 1];
    }
}
```