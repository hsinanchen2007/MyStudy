首先献上最朴素的解法：使用ArrayList存储数据，当需要获取中位数的时候，就对整个ArrayList排序，然后再输出中位数。这个解法显然很慢，因为排序需要耗时O(nlogn)，如果每插入一个数就获取一次中位数，耗时就会非常多。
```
class MedianFinder {

   private ArrayList<Integer> nums = new ArrayList<>();

    /** initialize your data structure here. */
    public MedianFinder() {

    }

    public void addNum(int num) {
       nums.add(num);
    }


    public double findMedian() {
        Collections.sort(nums);
        int size = nums.size();
        return size % 2 == 0 ? (nums.get(size / 2 - 1) + nums.get(size / 2)) / 2.0 : nums.get(size / 2);
    }
}
```
执行结果：
![image.png](https://pic.leetcode-cn.com/6d36c06647b4a1bb42df9707f9b8c36ab52b2d9bc6b0f7e56c367ece54e383a2-image.png)

一种优化过的解法是使用一个大顶堆存储小于等于中位数的数，使用一个小顶堆存储大于等于中位数的数，并且时刻保持大顶堆的元素数量等于小顶堆的元素数量（总元素数量为偶数），或者大顶堆的元素数量比小顶堆的元素数量多1（总元素数量为奇数）。当两个堆的元素数量相等的时候，中位数就是两个堆堆顶元素的平均数。当大顶堆的数量比小顶堆的数量多1的时候，中位数就是大顶堆的堆顶元素。
```
class MedianFinder {

    // 存储小于等于中位数的数，使用大顶堆
    private PriorityQueue<Integer> left = new PriorityQueue<>(Comparator.reverseOrder());
    // 存储大于等于中位数的数，使用小顶堆
    private PriorityQueue<Integer> right = new PriorityQueue<>();
    // left的元素数量和right的元素数量的差值。其合理范围只有0（left和right元素数量相同）和1（left比right的元素数量多1）
    private int gap;

    /** initialize your data structure here. */
    public MedianFinder() {

    }

    public void addNum(int num) {
        // 当left为空或者num小于等于left中的最大值，将num插入left中
        if (left.isEmpty() || num <= left.peek()) {
            left.offer(num);
            gap++;
            // 如果插入后left的元素数量比right的元素数量多2，将left中的最大值取出，插入right中
            if (gap >= 2) {
                right.offer(left.poll());
                gap -= 2;
            }
        }
        // num大于left中的最大值，将num插入right中
        else {
            right.offer(num);
            gap--;
            // 如果插入后right中的元素比left中的元素多1，将left中的最小值取出，插入left中
            if (gap <= -1) {
                left.offer(right.poll());
                gap += 2;
            }
        }
    }


    public double findMedian() {
        return gap == 0 ? (left.peek() + right.peek()) / 2.0 : left.peek();
    }
}

```
执行结果：
![image.png](https://pic.leetcode-cn.com/90082d3d88be8942c8019e8fb51f02e49ae6cc26ef5d8d8221795c34383f698b-image.png)
