### 解题思路

求每对数字里面的最小值的最大和，只要让数组中比较大的数字和更大的在一组就好了，所以只要时奇数即可。

主要考验的是计算之前的排序效率。

最快的是JDK内置的Arrays.sort(nums)  14ms

之后是算法导论里面的快排 19ms

之后是插入排序 1070ms左右

### 代码

```java
class Solution {
    public int arrayPairSum(int[] nums) {
        quickSort(nums, 0, nums.length - 1);
        int sum = 0;
        for (int i = 0; i < nums.length - 1; i += 2) {
            sum += nums[i];
        }
        return sum;
    }
    private void quickSort(int[] nums, int low, int high) {
        if (low < high) {
            int q = partition(nums, low, high);
            quickSort(nums, low, q - 1);
            quickSort(nums, q + 1, high);
        }
    }

    private int partition(int[] nums, int low, int high) {
        int x = nums[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (nums[j] <= x) {
                i = i + 1;
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        nums[high] = nums[i + 1];
        nums[i + 1] = x;
        return i + 1;
    }

    private void insertSort(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            int j = i - 1;
            int tmp = nums[i];

            while (j >= 0 && nums[j] > tmp) {
                nums[j + 1] = nums[j];
                j = j - 1;
            }

            nums[j + 1] = tmp;
        }
    }
}
```