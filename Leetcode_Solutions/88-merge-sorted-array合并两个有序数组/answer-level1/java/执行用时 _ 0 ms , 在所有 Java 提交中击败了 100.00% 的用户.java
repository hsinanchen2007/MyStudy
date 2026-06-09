### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
	/*
	 * 合并2个有序数组成为一个,nums1有足够的长度 {256}合并{123}=》{122356}
	 */
	public static void main(String[] args) {
		// int数组默认各个元素为0
		int nums1[] = new int [1];
		int nums2[] = {1};
		merge(nums1, 0, nums2, 1);
		for (int i = 0; i < nums1.length; i++) {
			System.out.print(nums1[i]);
		}

	}
	// 123
	// 256

	public static void merge(int[] nums1, int m, int[] nums2, int n) {
		int count = 0;//nums3的计数指针
		int i = 0;//nums1的步进指针
		int j = 0;//nums2的步进指针
		int nums3[]=new int[m+n];
		for (; i < m;) {	
			for (; j < n; ) {
				if (nums1[i] <= nums2[j] && i<m) {
					nums3[count++] = nums1[i];
					i++;
					continue;
				} else {
					nums3[count++] = nums2[j];
					j++;
				}
			}
			//判断nums2循环完，nums1还有剩下的情况
			if(j==n&&i!=m){
				nums3[count++] = nums1[i];
				i++;
			}
		}
		//判断nums1长度为0
		if(m==0&&n!=0){
			for(;j<n;){
				nums3[count++] = nums2[j];
				j++;
			}
		}
		//赋值给nums1	
		for(int x=0;x<nums3.length;x++){
			nums1[x]=nums3[x];
		}

	}
}
```