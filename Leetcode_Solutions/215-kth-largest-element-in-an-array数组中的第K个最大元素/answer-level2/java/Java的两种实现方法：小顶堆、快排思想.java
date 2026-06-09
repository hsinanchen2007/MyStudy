**快排思想实现代码：**
```
public int findKthLargest(int[] nums, int k) {
    return nums[findKthLargest2(nums, 0, nums.length - 1, k)];
}
public int findKthLargest2(int[] nums, int left, int right, int k) {
    int p = partion(nums, left, right);
    if (nums.length - k < p)
        return findKthLargest2(nums, left, p - 1, k);
    else if (nums.length - k > p)
        return findKthLargest2(nums, p + 1, right, k);
    else
        return p;
}
public int partion (int[] nums, int left, int right) {
    int lTemp = left;
    int pivot = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= pivot)
            right--;
        while (left < right && nums[left] <= pivot)
            left++;
        swap(nums, left, right);
    }
    swap(nums, left, lTemp);
    return left;
}
public void swap(int[] nums,int i,int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

```
**小顶堆代码：**
```
public static int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> queue = new  PriorityQueue<Integer>();  
        for (int i = 0;i < nums.length;i++) {
            if (queue.size() >= k && queue.peek() < nums[i]) {
                queue.poll();
                queue.add(nums[i]);
            } else if (queue.size() < k)
                 queue.add(nums[i]);
        }
        return queue.peek();
    }
```
