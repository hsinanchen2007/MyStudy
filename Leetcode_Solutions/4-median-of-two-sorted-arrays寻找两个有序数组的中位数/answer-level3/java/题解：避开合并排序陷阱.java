照惯例提供参考题解，不提供本人的最优题解，本题不能使用合并后再排序，否则必然超时。

#### 解题核心：
1. 因为是有序数组，可创建双指针，通过对比两个数组当前位置的大小即可获取当前的排序数。
2. 设置集合存放上一位数，由于长度为偶数情况下需要取两数的平均数。

代码如下：
```Java []
public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int isEven = (nums1.length + nums2.length) % 2;
		int midden = (nums1.length + nums2.length) / 2;
		int i = 0;
		int j = 0;
		List<Integer> nums = new ArrayList<>();  // 该处定义效率不高，请参考阿里java规范或使用数组则有较大提升
		while (i + j <= midden) {
			if (i < nums1.length && j < nums2.length) {
				if (nums1[i] > nums2[j]) {
					nums.add(nums2[j]);
					j++;
				} else {
					nums.add(nums1[i]);
					i++;
				}
			} else if (i >= nums1.length && j < nums2.length) {
				nums.add(nums2[j]);
				j++;
			} else {
				nums.add(nums1[i]);
				i++;
			}
		}
		if (isEven == 0) { // 偶数
			return (nums.get(midden) + nums.get(midden - 1)) / 2D;
		} else {
			return nums.get(midden);
		}
    }
```