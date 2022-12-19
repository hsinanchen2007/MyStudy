首先想到的方法是使用最大堆，思路如下：
1. 维护一个k大小的最大堆
2. 当堆中元素不足k个时，直接加入到堆中；
3. 当堆中元素大于k个时，判断新元素是否大于堆顶的值，如果大于则舍弃，反之入堆，舍弃最大的值

代码如下：
```
public int[] getLeastNumbers(int[] arr, int k) {
        if (k < 0) {
            return null;
        }
        int[] res = new int[k];
        if (arr == null || arr.length == 0 || k == 0) {
            return res;
        }
        // 如果k比arr还大，那直接返回arr
        if (k >= arr.length) {
            return arr;
        }
        PriorityQueue<Integer> heap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2.compareTo(o1);
            }
        });
        for (int i = 0; i < arr.length; i++) {
            if (heap.size() < k) {
                heap.offer(arr[i]);
            } else {
                if (arr[i] < heap.peek()) {
                    heap.poll();
                    heap.offer(arr[i]);
                }
            }
        }
        int i = 0;
        while (!heap.isEmpty()) {
            res[i++] = heap.poll();
        }
        return res;
    }
```