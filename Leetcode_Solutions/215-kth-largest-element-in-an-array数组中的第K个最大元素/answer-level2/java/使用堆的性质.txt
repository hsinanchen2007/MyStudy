/*
 * 本题若采用先排序的方法则最优的时间复杂度也为O(nlogn)，若利用最小堆的性质则可以把时间复杂度降为O(nlogk)
 * 只需要维护一个大小为k的最小堆，堆顶元素即为第k大元素，当堆顶小于新元素时弹出堆顶，将新元素加入堆这样就保证了堆中是有k个最大的元素
 */

class Solution {
	
    public int findKthLargest(int[] nums, int k) {
    	 //最小堆
    	 PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    	 //当堆中元素小于k时直接push进入即可
    	 for (int i = 0; i < nums.length; i++) {
			if (minHeap.size() < k) {
				minHeap.add(nums[i]);
			}else {
				if (minHeap.peek() < nums[i]) {
					minHeap.remove();
					minHeap.add(nums[i]);
				}
			}
		}
    	 //返回堆顶元素
    	 return minHeap.peek();
    }
}