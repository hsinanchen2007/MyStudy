```
1、 大顶堆
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null || nums.length <= 1) {
            return nums;
        }
        int len = nums.length;
        int[] res = new int[len-k+1];
        int index = 0;
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer e1, Integer e2) {
                return e2-e1;
            }
        });
        for(int i = 0; i < len ;i++) {
            if(i<k) {
                maxHeap.add(nums[i]);
            } else {
                res[index++] = maxHeap.peek();
                maxHeap.remove(nums[i-k]);
                maxHeap.add(nums[i]);
            }
        }
        res[index] = maxHeap.peek();
        return res;
    }
}
2、双端队列+单调栈
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null || nums.length <= 1) {
            return nums;
        }
        int len = nums.length;
        int[] res = new int[len-k+1];
        int index = 0;
        LinkedList<Integer> valuesStack = new LinkedList<>();
        LinkedList<Integer> indexStack = new LinkedList<>();
        valuesStack.push(nums[0]);
        indexStack.push(0);
        if(k == 1) {
            res[index++] = nums[0];
        }
        for(int i = 1; i < len ;i++) {
            while(!valuesStack.isEmpty() && nums[i]>valuesStack.getLast()) {
                valuesStack.removeLast();
                indexStack.removeLast();
            }
            valuesStack.addLast(nums[i]);
            indexStack.addLast(i);
            if(i>=k-1) {
                while(i-indexStack.getFirst()>=k) {
                    valuesStack.removeFirst();
                    indexStack.removeFirst();
                }
                res[index++] = valuesStack.getFirst();
            }
        }
        return res;
    }
}
```
