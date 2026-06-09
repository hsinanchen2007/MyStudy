解题思路：
    一. 将数组nums[]中的元素从minHeap[1]开始依次放入，这里分为 num.length >= k 和 num.length < k 两种情况
        1. num.length >= k：
        - 将num中的前个元素，依次放入堆中
        - 从第k+1个元素开始，对元素进行add()操作
        2. num.length < k：
        - 将num中的前个元素，依次放入堆中
    二. add()会判断是 num.length >= k 和 num.length < k 哪种情况
        1. num.length >= k
        - 此时堆为有序的，堆顶（即minHeap[1]），为堆中最小元素，同时也是所有数中第k大元素
        - 若新元素>堆顶元素，则替换对顶元素，并对堆顶元素进行sink()（下沉操作），若新元素<=堆顶元素,则丢弃不作操作
        2. num.length < k
        - 由题nums.length >= k-1，所以当进行一次add()操作后堆会被填满
        - 填满后对堆进行有序化

![image.png](https://pic.leetcode-cn.com/e99bb83f9721a9cbf805f7d8bf7b8783af43b50369e027c0e5b92af8fdd451b9-image.png)
执行用时：23 ms
内存消耗：47.8 MB

代码：
```
class KthLargest {

    /**小顶堆*/
    private int[] minHeap;
    /**堆的规模*/
    private final int k;
    /**堆的最后一个元素的索引*/
    private int last;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        this.minHeap = new int[k+1];
        /**/
        for (int i = 1; i <= k && i <= nums.length; i++){
            this.minHeap[i] = nums[i-1];
            this.last = i;
        }

        /*如果小顶堆被填满了,就继续添加元素,并使堆有序*/
        if (last == k) {
            order();
            for (int i = k; i < nums.length; i++){
                add(nums[i]);
            }
        }

    }

    public int add(int val) {
        /*如果堆还未被填满（由题意堆会在至多一次add后被填满）,则将元素放在无序堆的末尾，然后将堆有序化*/
        if (last == k-1) {
            minHeap[++last] = val;
            order();
        }
        /*如果新元素大于堆中第k大的元素（minHeap[1]），则替换它，并将堆有序化*/
        else if(val > minHeap[1]){
            minHeap[1] = val;
            /*此时处堆尖处无序外,其他部分为有序,所以只需将堆顶下沉即可*/
            sink(1);
        }
        return minHeap[1];
    }

    /**堆的有序化*/
    private void order(){
        for (int i = k/2; i >=1 ; i--) {
            sink(i);
        }
    }

    /**下沉*/
    private void sink(int i){
        while( 2*i <= k){
            int j = 2*i;

            if ( j < k && minHeap[j] > minHeap[j+1]) {
                j++;
            }

            if ( minHeap[i] > minHeap[j]){
                int temp = minHeap[i];
                minHeap[i] = minHeap[j];
                minHeap[j] = temp;

                i = j;
            }else {
                break;
            }
        }
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```
