### 解题思路

**思路分析**
1. 首先利用for循环将nums2中的数组打入到nums1中；
2. 利用冒泡排序法对nums1中的元素进行排序
3. 从第n个元素挨个遍历到第0个元素，利用遍历实现的。
4. 时间复杂度为O（n.^2）

**运行结果**

执行用时：11ms,在Java提交中击败了6.21%的用户......(时间效率还有待提高)
### 代码

```java
class Solution {
    	public static void merge(int [] nums1,int m,int[] nums2,int n) {
		for(int i=m;i<m+n;i++) {
			nums1[i]=nums2[i-m];
		}
		Order(m+n-1,nums1);
	
		for(int k:nums1) {
			System.out.print(k+" ");
		}
	}
	public static void Order(int n,int [] arr) {
		if(n==0) {return;}
		for(int i=n-1;i>=0;i--) {
			if(arr[n]<arr[i]) {//现在只能做到比较这个数和其周围数的大小;
				int temp=arr[n];
				arr[n]=arr[i];
				arr[i]=temp;	
			}
		}
		
		Order(n-1,arr);
	}
}
```