构造一个大小为k的优先队列，将数组里面依次填充进去，剩下的和根节点比较，大就移除根节点并添加进去。最后第一个就是第k大的
```
public int findKthLargest(int[] nums, int k) {
        int result = 0;
        if (nums.length==1){
            return nums[0];
        }
        if (k<=nums.length){
            PriorityQueue<Integer> priorityQueue = new PriorityQueue<Integer>(k);
            for (int i = 0; i < k; i++) {
                priorityQueue.add(nums[i]);
            }
            int key = k;
            for (int j = key;key<nums.length;key++){
                if (nums[key]>=priorityQueue.peek()){
                    priorityQueue.poll();
                    priorityQueue.add(nums[key]);
                }
            }
            result = priorityQueue.peek();
        }
        return result;
    }
```


