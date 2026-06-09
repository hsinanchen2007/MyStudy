如果要求数据流中最大元素，那么只需要维护一个当前最大值，每次新元素进来，和当前最大值比较即可。

那么当题目升级成了求第K大元素，那么我们只需要维护最大的k个数，每次新元素进来，和这最大K个数中最小值比较即可。

```
    int size;
    private PriorityQueue<Integer> q;

    public LeetCode703_KthLargestElementStream(int k, int[] nums) {
        size = k;
        q = new PriorityQueue(k);
        for (int num : nums) {
            add(num);
        }
    }

    public int add(int val) {
        if (q.size() < size) {
            q.add(val);
        } else if (q.peek() < val) {
            q.poll();
            q.add(val);
        }
        return q.peek();
    }
```
