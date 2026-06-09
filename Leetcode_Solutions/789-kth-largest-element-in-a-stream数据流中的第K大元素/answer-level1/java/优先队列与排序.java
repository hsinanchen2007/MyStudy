## 排序：
1. 对输入的arr进行排序，找出前k个
2. 每次add进行插入排序
```
class KthLargest {
    private int[] arr;
    public KthLargest(int k, int[] nums) {
        arr = new int[k];
        Arrays.fill(arr, Integer.MIN_VALUE);
        Arrays.sort(nums);
        int offset = nums.length - k;
        for (int i = 0; i < (k > nums.length ? nums.length : k); ++i) {
            arr[k - i - 1] = nums[nums.length - i - 1];
        }
    }
    
    public int add(int val) {
        int len = arr.length;
        if (val < arr[0]) return arr[0];
        for (int i = 0; i < len; ++i) {
            if (i == len - 1) arr[i] = val;
            else if (val > arr[i + 1]) {
                arr[i] = arr[i + 1];
            } else {
                arr[i] = val;
                break;
            }
        }
        return arr[0];
    }
}
```
时间复杂度分别为：nlogn、k
空间复杂度为n或k（依赖于排序算法的空间复杂度）

## 优先队列：
```
class KthLargest {
    private PriorityQueue<Integer> pq;
    private int k;
    public KthLargest(int k, int[] nums) {
        this.k = k;
        pq = new PriorityQueue<>();
        for (int i : nums) {
            add(i);
        }
    }
    public int add(int val) {
        if (pq.size() < k) {
            pq.add(val);
        } else if (pq.peek() < val) {
            pq.add(val);
            pq.poll();
        }
        return pq.peek();
    }

}
```
时间复杂度：nlogK、logK
空间复杂度：k