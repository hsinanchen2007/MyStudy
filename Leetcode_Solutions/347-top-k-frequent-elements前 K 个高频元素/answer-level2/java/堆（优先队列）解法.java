![FF234CE2A331404EF5089F5954D94D70.png](https://pic.leetcode-cn.com/02e672c2819c4f4c52465b6f812ccdf32ecfd7611390342379d7d5f7a4746891-FF234CE2A331404EF5089F5954D94D70.png)
``
```
class Solution {
    class Pair implements Comparable<Pair> {
        int n1;
        int n2;
        public Pair (int n1, int n2) {
            this.n1 = n1;
            this.n2 = n2;
        }
        public int compareTo(Pair o) {
            if (this.n2 < o.n2) {
                return 1;
            } else if (this.n2 > o.n2) {
                return -1;
            } else {
                return 0;
            }
        }
    }
    public List<Integer> topKFrequent(int[] nums, int k) {
          List<Integer> result = new LinkedList<>();
          //非法情况
        if (nums.length <= 0 || k < 1) {
            return result;
        }
        //当数组只有一个元素时，特殊处理
        if (nums.length == 1) {
            result.add(nums[0]);
            return result;
        }
        //对数组进行排序，方便后面的操作
        Arrays.sort(nums);
        PriorityQueue<Pair> queue = new PriorityQueue<>();
        int ret = 1;
        //作用是如果数组所有元素都是同一个值的时候，没有进行 offer 操作。用 flag 可以作为标记。
        int flag = 0; 
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ret++;
                continue;
            }
            queue.offer(new Pair(nums[i], ret));
            flag = 1;
            ret = 1;
        }
        //当数组所有元素都是同一个值的时候，进行特殊处理。
        if (flag == 0) {
            queue.offer(new Pair(nums[0], ret));
        }
        //因为上面的循环没有处理最后一种元素（一种元素即值相等的元素）的情况，在这里进行处理
        if (nums[nums.length - 1] != nums[nums.length - 2]) {
             queue.offer(new Pair(nums[nums.length - 1], 1));
        } else {
             queue.offer(new Pair(nums[nums.length - 1], ret));
        }
        //进行出优先队列操作
        while (k > 0) {
            Pair pair = queue.poll();
            result.add(pair.n1);
            k--;
        }
        return result;
    }
}
```
```
