### 解题思路
### 方法1：堆
此处我参考了别人的代码，有一个细节就是创建堆heap对象时候，要重写里面的Comparator方法使其为小顶堆（默认是大顶堆），这里采用的是lambda表达式写法。
遍历arr数组，当堆为空或 堆的容量 < k 的时候，添加当前arr[i]。此处还可以多加一个条件进行小优化：i < heap.peek()，当前arr[i] < 堆顶才添加，否则跳过。
此时一旦堆容量大于k，移除堆顶。

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        Queue<Integer> heap = new PriorityQueue<>(k,(i1,i2) -> Integer.compare(i2,i1));

        for(int i : arr){
            if(heap.isEmpty() || heap.size() < k || i < heap.peek()){
                heap.offer(i);
            }
            if(heap.size() > k){
                heap.poll();
            }
        }
        int[] res = new int[k];
        int j = 0;
        for(int i : heap){
            res[j++] = i;
            
        }
        return res;
    }
    
}
```

### 方法2：快速排序
划分数组首先通常取第一个作为哨兵arr[0]，分别创建左右指针（其中左指针为arr[1]，即哨兵右边第一个），左指针指向第一个大于哨兵以及右指针第一个小于哨兵互换，继续重复此操作直至 左指针 >= 右指针 为止。此时取【右指针】与哨兵互换（此处必须是右指针，因为右指针到此时一定是小于哨兵的元素，哨兵与其互换后满足左边小于等于哨兵）。返回此时（互换后）的哨兵下标。

利用划分后返回的数组下标，截取左半部分（小于arr[下标]的部分）判断是否长度为k，否则递归取其左/右部分。

### 代码
```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }
        // 最后一个参数表示我们要找的是下标为k-1的数
        return quickSearch(arr, 0, arr.length - 1, k - 1);
    }

    private int[] quickSearch(int[] nums, int lo, int hi, int k) {
        // 每快排切分1次，找到排序后下标为j的元素，如果j恰好等于k就返回j以及j左边所有的数；
        int j = partition(nums, lo, hi);
        if (j == k) {
            return Arrays.copyOf(nums, j + 1);
        }
        // 否则根据下标j与k的大小关系来决定继续切分左段还是右段。
        return j > k? quickSearch(nums, lo, j - 1, k): quickSearch(nums, j + 1, hi, k);
    }

    // 快排切分，返回下标j，使得比nums[j]小的数都在j的左边，比nums[j]大的数都在j的右边。
    private int partition(int[] nums, int lo, int hi) {
        int v = nums[lo];
        int i = lo, j = hi + 1;
        while (true) {
            while (++i <= hi && nums[i] < v);
            while (--j >= lo && nums[j] > v);
            if (i >= j) {
                break;
            }
            int t = nums[j];
            nums[j] = nums[i];
            nums[i] = t;
        }
        nums[lo] = nums[j];
        nums[j] = v;
        return j;
    }
    
}
```