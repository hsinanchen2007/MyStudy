### 手撕小顶堆，15ms
第k大，可以理解为前k大里的最小，又因为求的是数据流中的第k大，显然应该使用优先队列，一个基于小顶堆实现的优先队列。
堆的大小为k，堆顶为最小元素，通过删除堆顶元素和堆的下沉操作维护该小顶堆，使其中的元素总是数据流中的前k大，且堆顶为前k大里的最小，即第k大。
如果数据流中新添加的数比堆顶小，则新添加的数对原来的前k大元素不造成影响，第k大的数不变；
如果新添加的数比堆顶大，则意味该数要挤进前k大，则前k大的数将发生变化，自然第k大的数也将发生变化。

堆的插入操作时间复杂度为O(logn)，返回堆顶元素时间复杂度为O(1)。

### 代码

```java
class KthLargest {
    private int[] pq;//二叉堆，从下标1开始存储
    private int sz;//堆的大小
    private int n;//堆中含有的元素数量

    /**
     * 基于数组的构造函数
     * 通过下沉操作构造堆
     * @param k即堆的规模用于维护前k大的元素
     */
    public KthLargest(int k, int[] nums) {
        sz = k;
        pq = new int[sz + 1];
        int len = nums.length;
        for(int i = 0; i < k && i < len; i++)
        {
            pq[i + 1] = nums[i];
            n++;
        }
        if(len >= k)
        {
            toHeap();
            for(int i = k; i < len; i++)
                add(nums[i]);
        }
    }
    
    /** 
     * 数据流中添加新元素后返回第k大
     * @param 数据流中新添加的元素
     */
    public int add(int val) {
        if(n < sz)
        {
            pq[++n] = val;
            toHeap();
        }
        else if(val > pq[1])
        {
            pq[1] = val;
            sink(1);
        }
        return pq[1];
    }

    /**
     * 自底向上构造堆
     */
    private void toHeap() {
        for(int i = sz/2; i >= 1; i--)
            sink(i);
    }

    /**
     * Helper functions to restore the heap.
     * 下沉
     * @param 待下沉元素在数组中的下标
     */
    private void sink(int k) {
        while(2*k <= sz)
        {
            int j = 2 * k;
            if(j < sz && pq[j+1] < pq[j])   j++;
            if(pq[k] <= pq[j])              break;
            exch(k, j);
            k = j;
        }
    }

    /**
     * Helper functions for swaps.
     * 交换函数
     * @param 待交换元素的下标
     */
    private void exch(int a, int b) {
        int t = pq[a];
        pq[a] = pq[b];
        pq[b] = t;
    }
}
```