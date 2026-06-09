解法一：有序数组，维护K个元素的有序数组，根据插入排序的，每次插入新元素，对K个数组重新排序，插入复杂度O(N)，返回复杂度O(1)
```java
class KthLargest {
private int[] topK;

    public KthLargest(int k, int[] nums) {
        topK = new int[k];
        // 初始化
         for (int i = 0; i < topK.length; i++) {
            topK[i] = Integer.MIN_VALUE;
        }
          for (int num : nums) {
            kth(topK, num);
        }
    }

    public int add(int val) {
        return kth(topK, val);
    }

    /**
     * 维护topK内部有序,返回kth
     *
     * @param topK
     * @param val
     * @return
     */
    private int kth(int[] topK, int val) {
        if (topK[topK.length - 1] >= val) {
            return topK[topK.length - 1];
        }
        topK[topK.length - 1] = val;
        for (int i = topK.length - 1; i > 0; i--) {
            if (topK[i - 1] < topK[i]) {
                int tmp = topK[i];
                topK[i] = topK[i - 1];
                topK[i - 1] = tmp;
            } else {
                break;
            }
        }


        return topK[topK.length - 1];
    }
}
```
解法二：Java内置PriorityQueue，这种解法中，priorityQueue.poll()以后内部会再进行一次下沉操作，对于这道题来说是没有必要的，因此实际上我们可以不用priorityQueue，自己维护数组实现最小堆的上浮操作
class KthLargest {

    Queue<Integer> priorityQueue;
    int limit;

     public KthLargest(int k, int[] nums) {
        limit = k;
        priorityQueue = new PriorityQueue<>(k);
        for (int num : nums) {
            add(num);
        }
    }

    public int add(int val) {
        if (priorityQueue.size() < limit) {
            priorityQueue.add(val);

        } else if (val > priorityQueue.peek()) {
            priorityQueue.poll();
            priorityQueue.add(val);
        }

        return priorityQueue.peek();
    }
}