归并排序的实现，这里用了【从大到小】排列，感觉计算count的时候会好理解一点，更直观。
```java
class Solution {
    public int reversePairs(int[] nums) {
        if (nums == null || nums.length <= 1) return 0;
        return mergeSort(nums, 0, nums.length - 1, new int[nums.length]);
    }

    int mergeSort(int[] nums, int left, int right, int[] tmp) {
        if (left >= right) return 0;
        int mid = (left + right) / 2;
        int count = mergeSort(nums, left, mid, tmp) + mergeSort(nums, mid + 1, right, tmp);

        int i = left, j = mid + 1;
        while (i <= mid) {
            double numi = (double) nums[i++] / 2.0d;
            // 左侧：left ~ i ~ mid
            // 右侧：mid+1 ~ j ~ right
            // 因为【从大到小】排序
            // 1、当i、j不满足nums[i]>2nums[j]条件时，则i~mid、j这部分数据必然也不满足上述条件，此时为了减少多余循环，i~mid复用已经累加过的j即可。
            // 2、当i、j满足nums[i]>2nums[j]条件时，则当前i、j~right这部分数据必然也满足上述条件，此时无需后续循环，count直接加上j到right数量即可。
            while (j <= right && numi <= (double) nums[j]) j++;
            count += (right - j + 1);
        }

        merge(nums, left, mid, right, tmp);
        return count;
    }

    void merge(int[] nums, int left, int mid, int right, int[] tmp) {
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            tmp[k++] = (nums[i] >= nums[j]) ? nums[i++] : nums[j++]; // 注意这里是【从大到小】排序
        }
        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= right) tmp[k++] = nums[j++];
        System.arraycopy(tmp, 0, nums, left, k);
    }
}
```
当然【从小到大】也可以
```java
class Solution {
    public int reversePairs(int[] nums) {
        if (nums == null || nums.length <= 1) return 0;
        return mergeSort(nums, 0, nums.length - 1, new int[nums.length]);
    }

    int mergeSort(int[] nums, int left, int right, int[] tmp) {
        if (left >= right) return 0;
        int mid = (left + right) / 2;
        int count = mergeSort(nums, left, mid, tmp) + mergeSort(nums, mid + 1, right, tmp);

        int i = left, j = mid + 1;
        while (i <= mid) {
            double numi = (double) nums[i++] / 2.0d;
            // 左侧：left ~ i ~ mid
            // 右侧：mid+1 ~ j ~ right
            // 因为【从小到大】排序
            // 1、如果i、j不满足nums[i]>2nums[j]条件，则i、j~right这部分数据必然也不满足当前条件，此时直接跳出循环即可
            // 2、如果i、j满足nums[i]>2nums[j]条件，则i~mid、j这部分数据必然也满足当前条件，所以后续的i直接加上mid+1~j这部分数量，而无需再循环。
            while (j <= right && numi > (double) nums[j]) j++;
            count += (j - (mid + 1));
        }

        merge(nums, left, mid, right, tmp);
        return count;
    }

    void merge(int[] nums, int left, int mid, int right, int[] tmp) {
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            tmp[k++] = (nums[i] <= nums[j]) ? nums[i++] : nums[j++]; // 注意这里是【从小到大】排序
        }
        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= right) tmp[k++] = nums[j++];
        System.arraycopy(tmp, 0, nums, left, k);
    }
}
```
