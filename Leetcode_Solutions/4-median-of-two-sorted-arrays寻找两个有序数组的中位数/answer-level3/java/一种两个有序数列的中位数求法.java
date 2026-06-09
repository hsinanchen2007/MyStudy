  首先题目中给定的条件是两个有序的数列，这个条件是本求法适用的一个关键之处。
  步骤：
   1. 首先计算中位数的位置，假若我们把两个数组合成一个有序的数组，那么**中位数所在的位置**就是固定的，假设数组长度为n
      1. 如果n为奇数，那中位数就是第（n+1）/2 个数，下标为n/2向下取整
      2. 如果n为奇数，那中位数就是第 n/2 个数和第 n/2 + 1 个数的均值，下标为 n/2-1 和 n/2
   2. 然后就是去找第一步中获得的元素，因为我们只是找中位数，所以不需要对这两个数组真正的进行一次合并并排序，只需要比较到中位数的位置即可，如果总共有偶数个数，就需要找到中间的两个数，如果有奇数个数，就需要找到中间的一个数，即最多只需要比较 n/2 +1 次就可以了，这里比较的时候就需要依赖开头提到的两个数列是有序的。
   
   第2步分解为下面的几个小步骤：
   1. 对两个数组分别设置一个游标，nums1为Index1， nums2为Index2，初试都从0开始
   2. 对nums1[index1] 和 nums2[Index2]进行比较，记录下较小的那一个数，并且对应的index 要加1
   3. 重复2 的步骤，直到比较到一个或两个中位数的位置 或者是比较到某一个数组已经全部遍历完的时候。
   4. 当比较到中位数时，直接返回我们记录下来的数就完成了计算。如果比较到某一个数组已经完成一遍遍历还没有找到中位数时，由于两个数列是有序的，那就说明中位数一定在剩下的一个数组中，而此时我们已经知道中位数的位置以及已经比较了多少次，我们可以直接算出中位数的下标地址：**中位数所在的位置 - 已经比较的次数 + 这个数组已经遍历的Index** 就是中位数在这个数组中的下标位置，直接取数即可，完成计算。


完整代码
```
public class MedianOfTwoSortedArrays {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // 获得中位数在整个序列中的下标
        // 两个数组中数的总个数为奇数时，只需要找到一个中间数字即可，此时只用到 medianIndex2,
        // 若为偶数，就需要找两个中间数
        int nums1Length = nums1.length;
        int nums2Length = nums2.length;
        int sum = nums1Length + nums2Length;
        int medianIndex1 =-1;
        int medianIndex2 = -1;
        if (sum %2 == 0) {
            medianIndex2 = sum / 2;
            medianIndex1 = sum / 2 - 1;
        } else {
            medianIndex2 = sum / 2;
        }

        // 找到指定下标的元素
        // 两个数组的遍历游标
        int index1 = 0;
        int index2 = 0;
        int median1 = 0;
        int median2 = 0;
        int target;
        int i = 0;
        // nums1 和 nums2 下标都不越界时
        for (; i <= medianIndex2; i++){
            if (index1 >= nums1Length || index2 >= nums2Length) {
                break;
            }
            if ( nums1[index1] < nums2[index2]) {
                target = nums1[index1];
                ++index1;
            } else {
                target = nums2[index2];
                ++index2;
            }
            if (i == medianIndex1) {
                median1 = target;
            } else if (i == medianIndex2) {
                median2 = target;
            }
        }
        // 从剩下的有序数组中直接获得中位数
        if (index1 < nums1Length) {
            if (medianIndex1 - i >= 0) {
                median1 = nums1[medianIndex1 - i + index1];
            }
            if (medianIndex2 - i >= 0) {
                median2 = nums1[medianIndex2 - i + index1];
            }
        } else {
            if (medianIndex1 - i >= 0) {
                median1 = nums2[medianIndex1 - i + index2];
            }
            if (medianIndex2 - i >= 0) {
                median2 = nums2[medianIndex2 - i + index2];
            }
        }
        if (medianIndex1 == -1) {
            return median2;
        } else {
            return (median1 + median2) / 2.0;
        }
    }
}
```
