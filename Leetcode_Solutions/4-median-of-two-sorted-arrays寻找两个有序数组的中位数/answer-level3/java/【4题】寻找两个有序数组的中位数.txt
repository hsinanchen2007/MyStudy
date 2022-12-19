**方法一：合并两个数组(不符合题目要求时间复杂度))**
```
class Solution {
    /**
    * 中位数定义：
    * 数组长度为奇数，则中位数为中间位置数字；
    * 数组长度为偶数，则中位数为中间两位数字的平均值。
    * 思路：
    * 将两个数组合并成一个有序数组，按中位数定义计算中位数。
    */
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len = nums1.length + nums2.length;
        int[] temp;
        if(nums1.length < nums2.length){
            temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        int[] nums = Arrays.copyOf(nums1,len);
        System.arraycopy(nums2,0,nums,nums1.length,nums2.length);
        for (int i = nums1.length; i < nums.length; i++) {
            int tmp = nums[i];
            int left = 0, right = i - 1, mid;
            while (left <= right) {
                mid = (left + right) / 2;
                if (tmp > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            System.arraycopy(nums, left, nums, left + 1, i - left);
            nums[left] = tmp;
        }
        if(len % 2 == 0){
            return (nums[len/2] + nums[len/2 -1]) / 2.0;
        }else {
            return nums[len/2] * 1.0;
        }
    }
}
```

**方法二：分别切割两个数组**
```
class Solution {
    /**
    * 思路：
    * (1)分别以指定位置切割两个数组，
    * 切割后所有左边元素个数等于(总长度为偶数)或者加一等于(总长度为奇数)所有右边元素的个数；
    * 切割后左边最大元素小于等于右边最小元素。
    * (2)根据时间复杂度要求按二分查找切割位置。
    * (找到一个数组的切割位置之后根据总长度的一半算出另一个数组切割位置)
    * (3)正确切割完成后，找到左边最大值和右边最小值，按总长度是奇数还是偶数区分返回中位数。
    * 例如：
    * nums1: 3 4 | 5
    * nums2: 1 2 | 7 8 9
    */
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // 确保nums1是长度较短数据，减少查询时间
        if(nums1.length > nums2.length){
            return findMedianSortedArrays(nums2,nums1);
        }
        // 如果nums1长度为0，直接return结果
        if(nums1.length == 0){
            return (nums2[(nums2.length - 1) / 2] + nums2[(nums2.length / 2)]) / 2.0;
        }
        int len = nums1.length + nums2.length;
        // nums1的切割范围
        int cutL = 0, cutR = nums1.length;
        // num1切割后左边元素个数和nums2切割后左边元素个数
        int cut1 = 0, cut2;
        while (cut1 <= nums1.length){
            cut1 = (cutR - cutL) / 2 + cutL;
            cut2 = len / 2 - cut1;
            // 如果cut1或者cut2等于0,引入一个最小值代表数组切割左边没有元素；
            // 相反如果cut1或者cut2等于切割数组的长度，则引入一个最大值代表数组切割右边没有元素。
            double L1 = (cut1 == 0) ? Integer.MIN_VALUE : nums1[cut1 - 1];
            double L2 = (cut2 == 0) ? Integer.MIN_VALUE : nums2[cut2 - 1];
            double R1 = (cut1 == nums1.length) ? Integer.MAX_VALUE : nums1[cut1];
            double R2 = (cut2 == nums2.length) ? Integer.MAX_VALUE : nums2[cut2];
            if(L1 > R2){
                cutR = cut1 - 1;
            }else if(L2 > R1){
                cutL = cut1 + 1;
            }else {
                // 切割成功，根据总长度是奇数还是偶数区分返回中位数
                if(len % 2 == 0){
                    L1 = L1 > L2 ? L1 : L2;
                    R1 = R1 < R2 ? R1 : R2;
                    return (L1 + R1) / 2;
                }else {
                    return R1 < R2 ? R1 : R2;
                }
            }
        }
        return 0.0;
    }
}
```

