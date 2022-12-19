### 解题思路
刚刚学习了堆排序，用来解答此题。
堆排序的时间复杂度为O（nlogn）;
**基本思想：**
1. 首先创建一个方法adjustHeap来实现“大顶堆”；
2. 将大顶堆的顶部元素与数组nums末尾元素进行交换，即将最大元素存在末尾；
3. 将数组的长度减小一个单元，即忽略末尾元素，对剩下的元素实现“大顶堆”；
4. 在调用2，3，直到遍历完所有元素；
5. 最后得到一个升序的数组nums

### 代码

```java
class Solution {
    public static int findKthLargest(int [] nums,int k) {
		
		HeapSort(nums);
		return nums[nums.length-k];
	}
	public static void adjustHeap(int [] nums,int i,int length) {
		int temp=nums[i];
		for(int k=2*i+1;k<length;k=k*2+1) {
			if(k+1<length && nums[k]<nums[k+1]) {
				k++;
			}
			if(nums[k]>nums[i]) {
				nums[i]=nums[k];
				nums[k]=temp;
				i=k;
			}
		}
	}
	
	public static void HeapSort(int[] nums) {
		int temp=0;
		for(int j=nums.length;j-1>0;j--) {
			for(int i=j/2-1;i>=0;i--) {
				adjustHeap(nums, i, j);
			}
			temp=nums[j-1];
			nums[j-1]=nums[0];
			nums[0]=temp;
		}
	}
}
```