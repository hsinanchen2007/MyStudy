执行用时 :5 ms, 在所有 Java 提交中击败了97.87%的用户
内存消耗 :47.5 MB, 在所有 Java 提交中击败了7.38%的用户
### 解题思路
标准快速排序＋三个位置筛选pivot主元函数
change_pivot就是看最左最右最中间这三个数哪一个第二大，把他放到最左边作为主元来划分。比每次取第一个数可能在有些情况下会快速一些。
### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
		Qsort(nums,0,nums.length-1) ;
		return nums ;
    }
	public static void swap(int nums[],int i,int j) {
		int temp = nums[i] ;
		nums[i] = nums[j] ;
		nums[j] = temp ;
		return ;
	}
	public static void change_pivot(int nums[],int l,int r) {
		int center = ((l+r)/2) ;
		if(nums[l]>nums[center])
		{
			swap(nums,l,center);
		}
		if(nums[l]>nums[r])
		{
			swap(nums,l,r);
		}
		if(nums[center]>nums[r])
		{
			swap(nums,r,center);
		}
		swap(nums,l,center) ;
	} 
	public static void Qsort(int nums[],int l,int r) {
		if(l>=r)
			return ;
		//Partition
		int pivot , low , high ;
		change_pivot(nums,l,r);//pivot选的好，每一趟交换的数字就多，递归排序次数就会少些。
		pivot = nums[l] ;
		low = l ;
		high = r ; 
		while(low<high) {
			while(low<high && nums[high]>=pivot) high-- ;
			nums[low] = nums[high] ;
			while(low<high && nums[low]<=pivot) low++ ;
			nums[high] = nums[low] ;
		}
		nums[low] = pivot ;
		
		//debug
		// for(int i=0;i<nums.length;i++) {
		// 	System.out.print(nums[i]+" ");
		// }
		// System.out.println();
		
		//Qsort
		Qsort(nums,l,low-1) ;
		Qsort(nums,low+1,r) ;
	}
}
```