```
package ZJM_88_合并两个有序数组;

public class Main {
    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int m = 3;
        int[] nums2 = {2, 5, 6};
        int n = 3;

        Solution solution = new Solution();
        solution.merge(nums1, m, nums2, n);

        for (int i = 0; i < m + n; i++) {
            System.out.print(nums1[i] + " ");
        }
    }
}

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int pointer = m + n - 1;                            //初始化指针位置为合并后的的数组末尾位置
        while (n > 0) {                                     //当nums2数组没遍历完，循环继续
            if (m > 0 && nums1[m - 1] > nums2[n - 1]) {     //如果在nums1数组没遍历完的情况下，nums1[m-1]大于nums2[n-1]（减1是实际下标）
                nums1[pointer--] = nums1[--m];              //先将nums1[--m]（先自减m得到实际下标），赋值给nums[pointer]，然后指针向前移动
            } else {
                nums1[pointer--] = nums2[--n];              //如果nums1数组遍历完或是nums1[m-1]小于nums2[n-1]，则赋值nums2[--n]给nums[pointer]
            }
        }
    }
}

/**
 * 本题要注意题目的要求，是将 nums2 合并到 nums1 中，且nums1的空间足够，初始化 nums1 和 nums2 的元素数量分别为 m 和 n
 * 首先，容易看出来，题目中给的数组是有序的，所以我们可以方便的对两个数组进行大小比较（若为无序数组，排序后也可使用此方法）
 * 定义一个指到合并后的nums1数组末尾的指针，一个数组长度作为循环条件，进行两个数组大小的比较，将较大的赋值到nums1数组末尾，
 * 将指针前移，循环结束，得到的nums1就是两个数组合并后的有序数组
 */

```
