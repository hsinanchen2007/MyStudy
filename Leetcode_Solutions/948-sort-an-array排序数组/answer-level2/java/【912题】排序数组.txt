**九种排序算法**
插入型：直接插入排序、二分插入排序、希尔排序。
选择型：选择排序、堆排序。
交换型：冒泡排序、快速排序。
归并型：归并排序。
基数型：基数排序(桶排序)。

![sort.png](https://pic.leetcode-cn.com/7df16ec773ce0664505d39e7d0c7e0780365bf6d0572382ffd1f01d189861e74-sort.png)
图片名词解释：
    n: 数据规模
    k: “桶”的个数
    In-place: 占用常数内存，不占用额外内存
    Out-place: 占用额外内存

**一：冒泡排序**
思路：
(1) 依次两两比较，如果前者大于后者则交换位置。
(2) 每轮比较都会将最大值置于末位（当前轮）。
(3) 每轮比较完成后长度-1重复(1)(2)直至遍历完。
```
class Solution {
	/**
     * 冒泡排序
     * 时间复杂度：O(n^2)
     */
    public int[] sortArray(int[] nums) {
		// 遍历到倒数第二个数时候比较最后一次完成排序。
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = 0; j < nums.length - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        return nums;
    }
}
```

**二：选择排序**
思路：
(1) 从头开始遍历标记最小值和此轮第一位数交换位置。
(2) 开始角标+1重复(1)的遍历，直至遍历完成。 
```
class Solution {
    /**
     * 选择排序
     * 时间复杂度：O(n^2)
     * 由于每轮比较只交换一次位置，性能要优于冒泡排序。
     */
    public int[] sortArray(int[] nums) {
        // 遍历到倒数第二个数时候比较最后一次完成排序。
        for (int i = 0; i < nums.length - 1; i++) {
            // 标记每轮比较中最小值的位置。
            int min = i;
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[min] > nums[j]) {
                    min = j;
                }
            }
            // 找到每轮比较中的最小值与本轮首位数字交换位置。
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
        return nums;
    }
}
```

**三：直接插入排序**
(1) 从角标1的数开始遍历，依次插入之前已经遍历过的有序集合。
(2) 集合中的数从后往前依次和遍历到的数比较，如果大于则后移一位，否则在后一位插入。
(3) 直至将之后所有数都插入之前有序集合。
```
class Solution {
    /**
     * 直接插入排序
     * 时间复杂度：O(n^2)
     */
    public int[] insertArray(int[] nums) {
        // 一个数必然是有序的，所以从第二个角标 1 的数开始遍历插入之前有序集合。
        for (int i = 1; i < nums.length; i++) {
            int temp = nums[i];
            int k;
            // 遍历角标 i 之前的集合，比 temp 大的全部后移一位。
            for (k = i - 1; k >= 0; k--) {
                if (nums[k] > temp) {
                    nums[k + 1] = nums[k];
                } else {
                    break;
                }
            }
            // 将 temp 插入有序集合正确位置使之依然有序。
            nums[k + 1] = temp;
        }
        return nums;
    }
}
```

**四：二分插入排序**
思路：
(1) 从角标1的数开始遍历，依次插入之前已经遍历过的有序集合。
(2) 遍历到的数依次使用二分法和之前有序集合中数比较找到正确位置插入。
(3) 直至将之后所有数都插入之前有序集合。
```
class Solution {
    /**
     * 二分插入排序
     * 时间复杂度：O(n*logn)
     */
    public int[] sortArray(int[] nums) {
        // 一个数必然是有序的，所以从第二个角标 1 开始遍历插入之前有序集合。
        for (int i = 1; i < nums.length; i++) {
            // 标记要插入角标 i 之前有序集合的数。
            int temp = nums[i];
            int left = 0, right = i - 1, mid;
            // 循环结束后 left - right = 1 。
            while (left <= right) {
                mid = (left + right) / 2;
                if (nums[mid] > temp) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // 将数组角标 i 之前比temp大的数全部后移一位。
            for (int j = i; j > left; j--) {
                nums[j] = nums[j - 1];
            }
            // 将 temp 插入有序集合正确位置使之依然有序。
            nums[left] = temp;
        }
        return nums;
    }
}
```

**五：希尔排序**
思路：
(1) 定义一个角标增量 m ，集合的长度为 n ，则将集合拆分为 n / m 组，
    每组中数组下标 i % m 值相等。
    例如：集合长度为 9 ，增量 m 为 3 ，
        则拆分为角标值集合为{0,3,6}、{1,4,7}、{2,5,8}三组。
(2) 分组后每组内部使用直接插入排序方法进行比较排序。
(3) 不断缩小增量直至增量缩小为 1 排序一次后完成。

注意：增量 m 的变化方式有多种，不同的变化方式效率不同。
```
class Solution {
    /**
     * 希尔排序
     * 时间复杂度：O(n*logn)
     */
    public int[] sortArray(int[] nums) {
        int m = nums.length;
        while (m > 1) {
            // 定义增量变化方式为 m / 2 。
            m = m / 2;
            // 分组后 0 到 m - 1 为每组的第一个数。
            for (int i = 0; i < m; i++) {
                // 每组内部使用直接插入排序。
                for (int j = i + m; j < nums.length; j += m) {
                    // 标记要插入角标 i + m 之前有序数列的数。
                    int temp = nums[j];
                    int k;
                    // 遍历 j 角标之前的有序集合，大于 temp 则后移 m 位，不大于则找到位置跳出循环。
                    for (k = j - m; k >= i; k -= m) {
                        if (nums[k] > temp) {
                            nums[k + m] = nums[k];
                        } else {
                            break;
                        }
                    }
                    // 将 temp 插入有序数列正确位置使之依然有序。
                    nums[k + m] = temp;
                }
            }
        }
        return nums;
    }
}
```

**六：快速排序**
思路：
(1) 首先选定一个基准点数值 m ，这里每次设定的基准点为每一组的第一个数。
(2) 拿 m 在集合中比较，比 m 大则放在 m 右侧，比 m 小则放在 m 左侧，
    比较完则找到 m 在最后排完序的准确位置，集合分成 m 前后的两部分。
(3) 对 m 前后的两部分递归重复(1)(2)操作直至集合所有数找到排序后准确位置。
```
class Solution {
    /**
     *  快速排序：
     *  时间复杂度：O(n*logn)
     */
    public int[] sortArray(int[] nums){
        quickSort(0, nums.length - 1, nums);
        return nums;
    }

    private void quickSort(int low, int high, int[] nums){
        if(low >= high){
            return;
        }
        // 得到基准点在集合最后排完序所在的位置。
        int mid = getMiddle(low,high, nums);
        // 对基准点前后两部分拆分递归。
        quickSort(low, mid - 1, nums);
        quickSort(mid + 1, high, nums);
    }

    private int getMiddle(int low, int high, int[] nums){
        // 设定基准点为每一部分的第一个数。
        int temp = nums[low];
        // 当 low == high ，结束循环。
        while (low < high) {
            // 将不小于基准点的数留在基准点右边。
            while (low < high && nums[high] >= temp) {
                high--;
            }
            // 如果有小于基准点的数，则置于左边指针位置。
            nums[low] = nums[high];

            // 将不大于基准点的数留在基准点左边。
            while (low < high && nums[low] <= temp) {
                low++;
            }
            // 如果有大于基准点的数，则置于右边指针位置。
            nums[high] = nums[low];
        }
        // low 为基准点在集合最后排完序所在的位置，并将集合按与基准点相比分成大小两部分。
        nums[low] = temp;
        return low;
    }
}
```

**七：堆排序**


**八：归并排序**


**九：基数排序（桶排序）**
