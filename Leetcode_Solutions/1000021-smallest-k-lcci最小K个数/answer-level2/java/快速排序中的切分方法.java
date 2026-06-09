![image.png](https://pic.leetcode-cn.com/36056a96a23e88245b10f9135fbde104a417ae8f0fb3f0a900fe8cd7ee0a6723-image.png)
- 快速排序的重点是切分方法，这道题不要求返回的 k 个数有序，切分方法返回的的部分有序正好满足
- partition(int[] arr, int lo, int hi) 对数组进行排序并切分，返回一个索引 j，此时 a[j] 左边的数都比 a[j] 小，a[j] 右边的数都比它大
- 利用切分使得 j = k 即可得到一个部分有序的 arr，然后返回 arr[0...k-1] 数组就是需要的解

```
class Solution {
    public int[] smallestK(int[] arr, int k) {
        int lo = 0;
        int hi = arr.length - 1;
        int[] ans = new int[k];
        int j = 0;
        while (j != k) {
            j = partition(arr, lo, hi);
            if (j > k) {
                hi = j - 1;
            } else if (j < k) {
                lo = j + 1;
            }
        }
        ans = Arrays.copyOfRange(arr, 0, k);
        return ans;
    }
    
    public int partition(int[] a, int lo, int hi) {
        int i = lo + 1;
        int j = hi;
        int pivot = a[lo];  // 将 a[lo] 放到合适的地方
        while (true) {
            while (a[i] <= pivot) {
                i++;
                if (i >= hi) break;
            }
            while (a[j] >  pivot) {
                j--;
                if (j <= lo) break;
            }
            if (i >= j) break;
            swap(a, i, j);
        }
        swap(a, j, lo);
        return j;
    }
    public void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
```
