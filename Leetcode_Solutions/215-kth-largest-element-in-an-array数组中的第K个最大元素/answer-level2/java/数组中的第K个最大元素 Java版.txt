```java
public class Solution{
    /*
	 * 基于快速排序
	 * 思路如下，每次排序将大于基准值key的放key的左边，将小于基准值key的放key的右边。然后如果基准值所在的位置
	 * 正好=k-1.则正好就是这个值如果左边的数量<k-1,则说明要找的数在右边，否则在左边。
	 */
	public static int findKthLargestQuickSort(int[] nums, int k) {
		if(nums == null || nums.length == 0) {
			return 0;
		}
		return find(nums,0,nums.length-1,k);
	}
	private static int find(int[] nums, int left, int right, int k) {
		//快速排序
		int l = left;
		int r = right;
		int key = nums[l];
		while(l < r) {
			while(l < r && nums[r] <= key) {
				r--;
			}
			nums[l] = nums[r];
			while( l < r && nums[l] >= key) {
				l++;
			}
			nums[r] = nums[l];
		}
		nums[l] = key;
		
		//如果当前的索引i等于k-1,则说明第K大的元素就是索引i指向的元素
		if(l == k - 1) {
			return key;
		}else if( l < k - 1) {
			//如果当前的索引i小于k-1,则说明第K大的元素在i的右边
			return find(nums, l+1, right, k);
		}else {
			//如果当前的索引i大于k-1,则说明第K大的元素在i的左边
			return find(nums, left, l-1, k);
		}
	}
	
	/*
	 * 基于快速选择：从i+1开始到结尾找出最大的数与索引i的元素交换，需要找第K大的元素，即循环K次
	 */
	public static int findKthLargestQuickSelect(int[] nums, int k) {
		//需要找到第K大的元素，便需要循环k次
		for(int i = 0; i < k; i++) { 
			int curIndex = i; 
			int cur = nums[curIndex];
			for(int j = i+1; j < nums.length; j++) { //找出索引i后面的最大值与i位置的元素交换
				if(nums[j] > cur) {
					cur = nums[j];
					curIndex = j;
				}
			}
			nums[curIndex] = nums[i];
			nums[i] = cur;
		}
		return nums[k-1];
	}

	/*
	 * 基于小顶堆
	 * 思路是创建一个小顶堆，将所有数组中的元素加入堆中，并保持堆的大小小于等于 k。这样，
	 * 堆中就保留了前 k个最大的元素。这样，堆顶的元素就是正确答案。
	 */
	public static int findKthLargestMinHeap(int[] nums, int k) {
		//初始化堆的第一个最小元素
		PriorityQueue<Integer> heap = new PriorityQueue<Integer>((n1,n2)->n1-n2);
		//保持k个较大元素在堆中
		for(int n : nums) {
			heap.add(n);
			if(heap.size() > k) {
				heap.poll();
			}
		}
		return heap.poll();
	}
	
	/*
	 * 排序然后返回索引为nums.length-k的元素
	 */
	 public static int findKthLargestSort(int[] nums, int k) {
		 Arrays.sort(nums);
		 return nums[nums.length - k];
	 }
}
```