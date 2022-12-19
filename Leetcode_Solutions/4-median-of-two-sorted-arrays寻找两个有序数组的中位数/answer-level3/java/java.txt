### 解题思路
先合并数组，再排序

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        Integer[] arr=new Integer[nums1.length+nums2.length];
		for(int i=0;i<nums1.length;i++) {
			arr[i]=nums1[i];
		}
		for(int i=nums1.length;i<nums1.length+nums2.length;i++) {
			arr[i]=nums2[i-nums1.length];
		}
		int temp=0;
		for(int i=0;i<arr.length;i++) {
			for(int j=i;j<arr.length;j++) {
				if(arr[i]>arr[j]) {
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
        if(arr.length%2!=0) {
        	return arr[arr.length/2];
        }else {
        	return (double)(arr[arr.length/2] + arr[arr.length/2 - 1])/2;
        }
    }
}
```