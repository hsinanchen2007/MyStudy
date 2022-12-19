### 解题思路

* 解法一：每次插入使用二分查找来找到插入的位置，时间复杂度O(lgN) + O(N)
* 解法二：使用两个堆，时间复杂度O(lgN)


### 代码

```java
class MedianFinder {
 interface MedianFinderDefine {

        /** initialize your data structure here. */
        void addNum(int num);

        double findMedian();
    }

    /**
     *  通过二分查找来解决这个问题
     *  时间复杂度：O(lgN) + O(N) = O(N)
     *  空间复杂度：O(N)
     */
    static class BinarySearchSolve implements MedianFinderDefine {

        private List<Integer> list = new ArrayList<>();

        /**
         * initialize your data structure here.
         *
         * @param num
         */
        @Override
        public void addNum(int num) {
            if (list.isEmpty()) {
                list.add(num);
                return;
            }
            // 找到合适的位置，然后插入
            int index = searchIndex(num);
            if (index >= list.size()) {
                list.add(num); // 这是最大值，加到最后，不能插入
                return;
            }

            // 插入
            list.add(index, num);
        }

        private int searchIndex(int target) {
            int l = 0, r = list.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (target >= list.get(m)) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            return l;
        }

        @Override
        public double findMedian() {
            if (list.isEmpty()) {
                return 0.0;
            }
            int len = list.size();
            if ((len & 1) == 0) {
                return (list.get(len / 2) + list.get((len / 2) - 1)) * 0.5;
            } else {
                return list.get(len / 2) * 1.0;
            }
        }
    }

   /**
     *  使用两个堆完成，一个大顶堆，一个小顶堆
     *  两个堆分别维护一半的数据，数据流先插入左边的大顶堆，然后将堆顶push到右边的小顶堆，确保
     *  两个堆元素相等，或者左边的堆比右边的堆多一个，这样最后求中位数的时候，如果数据大小为偶数，则
     *  就将两个堆顶元素求平均，否则就是左边大顶堆的堆顶就是中位数；为此需要在将左边的大顶堆的
     *  堆顶push给小顶堆之后，如果右边的小顶堆数量大于了左边的大顶堆，就需要将右边的堆顶push给
     *  左边的大顶堆，这样才能满足最后求中位数的需求
     *  时间复杂度：O(lgN)：push/pop需要O(lgN)，取堆顶需要O(1)
     *  空间复杂度：O(N)：需要存储数据流
     *
     *
     */
    static class TwoHeapSolve implements MedianFinderDefine {

        interface SimpleHeap {

            void push(int x);

            int top();

            int pop();

            int size();

        }

        static class MinHeap implements SimpleHeap {

            private int[] heap = new int[50000];
            private int sz = 0;

            @Override
            public void push(int x) {
                int i = sz ++; // 插入到最后一个位置，然后向上调整（交换）
                while (i > 0) {
                    // 父亲
                    int p = (i - 1) / 2;
                    // 如果父亲比他小，那么就可以停止了
                    if (heap[p] <= x) {
                        break;
                    }
                    // 否则继续向上交换
                    heap[i] = heap[p];
                    i = p;
                }
                // 找到位置
                heap[i] = x;
            }

            @Override
            public int top() {
                if (sz == 0) {
                    throw new IllegalStateException("empty heap");
                }
                return heap[0];
            }

            @Override
            public int pop() {
                // 这是要被pop的值
                int ret = top();

                // 这是最后一个值，现将它提到堆顶，然后向下调整（交换）
                int x = heap[--sz];
                int i = 0;
                while ((i * 2 + 1) < sz) {

                    // 左右儿子
                    int l = i * 2  + 1, r = l + 1;
                    // 找到比较小的儿子
                    if (r < sz && (heap[r] < heap[l])) {
                        l = r;
                    }
                    // 如果比孩子都小了，那么就没必要继续向下交换了
                    if (heap[l] >= x) {
                        break;
                    }

                    // 否则继续向下交换
                    heap[i] = heap[l];
                    i  = l;
                }

                // 找到调整好的位置，插入
                heap[i] = x;

                return ret;
            }

            @Override
            public int size() {
                return sz;
            }
        }

        static class MaxHeap implements SimpleHeap {

            private int[] heap = new int[50000];
            private int sz = 0;

            @Override
            public void push(int x) {
                int i = sz ++; // 先将它放在最后，然后向上调整
                while (i > 0) {
                    int p = (i - 1) / 2;
                    // 如果父亲比自己大了，那么就可以停止了
                    if (heap[p] >= x) {
                        break;
                    }

                    // 否则继续向上交换
                    heap[i] = heap[p];
                    i = p;
                }
                // 找到合适的位置，插入
                heap[i] = x;
            }

            @Override
            public int top() {
                if (sz == 0) {
                    throw new IllegalStateException("empty heap");
                }
                return heap[0];
            }

            @Override
            public int pop() {
                int ret = top();
                // 先将最末未的节点提到根节点，然后向下交换
                int x = heap[--sz];
                int i = 0;
                while ((i * 2  + 1) < sz) {

                    // 左右儿子
                    int l = i * 2 + 1 ,  r = l  + 1;
                    // 找到较大的儿子
                    if (r < sz && (heap[r] >= heap[l])) {
                        l = r;
                    }
                    // 如果比孩子都大，那么就没必要再继续交换下去了
                    if (heap[l] <= x) {
                        break;
                    }

                    // 否则，继续向下交换
                    heap[i] = heap[l];
                    i = l;
                }
                // 找到合适的位置，插入
                heap[i] = x;
                return ret;
            }

            @Override
            public int size() {
                return sz;
            }
        }

        // 大顶堆
        private SimpleHeap maxHeap = new MaxHeap();
        // 小顶堆
        private SimpleHeap minHeap = new MinHeap();

        /**
         * initialize your data structure here.
         *
         * @param num
         */
        @Override
        public void addNum(int num) {

            // 先push到左边的大顶堆
            maxHeap.push(num);

            // 然后再将左边的大顶堆的堆顶push到右边小顶堆
            minHeap.push(maxHeap.pop());

            // 确保左边的大顶堆数量大于右边的小顶堆
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.pop());
            }
        }

        @Override
        public double findMedian() {
            // 看看有没有数据
            int size = maxHeap.size() + minHeap.size();
            if (size == 0) {
                return  0.0;
            }
            if ((size & 1) == 0) {
                return (maxHeap.top() + minHeap.top()) * 0.5;
            } else {
                return maxHeap.top() * 1.0;
            }
        }
    }


     private MedianFinderDefine binarySearchSolve = new BinarySearchSolve();
        private MedianFinderDefine twoHeapSolve = new TwoHeapSolve();

        private int algorithm = 1; // 0 -> binary search 1 -> two heap

        /** initialize your data structure here. */
        public MedianFinder() {
        }

        public void addNum(int num) {
            if (algorithm == 0) {
                binarySearchSolve.addNum(num);
            } else {
                twoHeapSolve.addNum(num);
            }
        }

        public double findMedian() {
            if (algorithm == 0) {
                return binarySearchSolve.findMedian();
            } else {
                return twoHeapSolve.findMedian();
            }
        }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```