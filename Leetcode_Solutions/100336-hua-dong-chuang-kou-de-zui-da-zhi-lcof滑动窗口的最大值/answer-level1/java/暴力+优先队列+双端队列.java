## 暴力
```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0) return nums;
        int[] result = new int[nums.length - k + 1];
        for (int i = 0; i < nums.length - k + 1; ++i) {
            int max = nums[i];
            for (int j = 1; j < k; ++j) {
                max = max > nums[i + j] ? max : nums[i + j];
            }
            result[i] = max;
        }
        return result;
    }
}
```
时间复杂度: O(nk)
空间复杂度：O(k)
## 优先队列
```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0 || k == 1) return nums;
        int[] result = new int[nums.length - k + 1];
        PriorityQueue<Integer> pq = new PriorityQueue<>(
            (o1, o2) -> o2 - o1);
        for (int i = 0; i < k; ++i) pq.offer(nums[i]);
        for (int i = 0; i < nums.length - k; ++i) {
            result[i] = pq.peek();
            pq.remove(nums[i]);
            pq.offer(nums[i + k]);
        }
        result[result.length - 1] = pq.poll();
        return result;
    }
}
```
时间复杂度: O(nlogk)
空间复杂度：O(k)
## 双端队列
注意在滑动窗口中有些信息是可以省略的
当窗口中元素A1, A1, ... Ak 当 Ai < Ak 且 i < k时，Ai可以省略，因为只要有Ak在Ai就无用武之地
因此一旦发现Ai < Ak，就将其移除窗口，最大值永远是窗口最左边的值
```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0 || k == 1) return nums;
		int[] result = new int[nums.length - k + 1];
		LinkedList<Integer> deque = new LinkedList<>();
        for (int i = 0; i < nums.length; ++i) {
            add(deque, nums, i - k, i);
            if (i >= k - 1) result[i - k + 1] = deque.peekLast();
        }
		return result;
	}
    private void add(LinkedList<Integer> deque, int[] arr, int oldIndex, int newIndex) {
        int newVal = arr[newIndex];
        if (oldIndex >= 0 && deque.peekLast() == arr[oldIndex]) deque.pollLast(); 
        while (!deque.isEmpty()) {
            if (deque.peekFirst() < newVal) deque.pollFirst();
            else break;
        }
        deque.offerFirst(newVal);
	}
}
```
时间复杂度: O(n)
空间复杂度：O(k)