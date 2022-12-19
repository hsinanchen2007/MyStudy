### 解题思路
使用大顶堆记录k个数据中较小的一半，使用小顶堆记录k其中较大的一半
根据两个堆的堆顶即可得到中位数

### 代码

```java
class Solution {
	public double[] medianSlidingWindow(int[] nums, int k) {
		long[] longNums = new long[nums.length];
		for(int i = 0; i < nums.length; i++) {
			longNums[i] = nums[i];
		}
		return medianSlidingWindowLong(longNums, k);
	}
	
    public double[] medianSlidingWindowLong(long[] nums, int k) {
    	// 较小的一半数构成大顶堆，较大的一半数构成小顶堆
    	double[] medians = new double[nums.length - k + 1];
    	int index = 0;
        PriorityQueue<Long> largeHeap = new PriorityQueue<Long>(new Comparator<Long>() {
        	public int compare(Long o1, Long o2) {
        		if(o2 - o1 > 0) {
        			return 1;
        		}
        		else if(o2 - o1 < 0) {
        			return -1;
        		}
        		else {
        			return 0;
        		}
        	}
        });
        PriorityQueue<Long> smallHeap = new PriorityQueue<Long>(new Comparator<Long>() {
        	public int compare(Long o1, Long o2) {
        		if(o2 - o1 > 0) {
        			return -1;
        		}
        		else if(o2 - o1 < 0) {
        			return 1;
        		}
        		else {
        			return 0;
        		}
        	}
        });
        for(int i = 0; i < nums.length; i++) {
        	if(i < k) {
        		if(largeHeap.size() == smallHeap.size()) {
        			largeHeap.add(nums[i]);
        		}
        		else {		// largeHeap.size() > smallHeap.size()
        			smallHeap.add(nums[i]);
        		}
        		maintain(largeHeap, smallHeap);
        	}
        	else {	// i >= k
        		if(largeHeap.size() == smallHeap.size()) {
        			System.out.println("Error." + i);
        		}
        		medians[index++] = largeHeap.size() == smallHeap.size() ? ((long)largeHeap.peek() + (long)smallHeap.peek()) * 0.5 : largeHeap.peek();
        		if(nums[i - k] <= largeHeap.peek()) { // 被替换的元素在大顶堆中
        			largeHeap.remove(nums[i - k]);
        			largeHeap.add(nums[i]);
        		}
        		else {
        			smallHeap.remove(nums[i - k]);
        			smallHeap.add(nums[i]);
        		}
        		maintain(largeHeap, smallHeap);
        	}
        }
        medians[index++] = largeHeap.size() == smallHeap.size() ? ((long)largeHeap.peek() + (long)smallHeap.peek()) * 0.5 : largeHeap.peek();
        return medians;
    }
    
    public void maintain(PriorityQueue<Long> largeHeap, PriorityQueue<Long> smallHeap) {
    	if(largeHeap.isEmpty() || smallHeap.isEmpty()) {
    		return;
    	}
    	if(largeHeap.peek() > smallHeap.peek()) {
    		// 如果大顶堆的顶大于小顶堆的顶，将两个堆的堆顶元素互换
    		long temp1 = largeHeap.poll();
    		long temp2 = smallHeap.poll();
    		largeHeap.add(temp2);
    		smallHeap.add(temp1);
    	}
    	return;
    }
}
```