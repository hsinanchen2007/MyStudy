### 解题思路
解题思路见代码

### 代码

```java
class MedianFinder {

   /* 大顶堆，存储左半边元素 */
    private PriorityQueue<Integer> left;
    /* 小顶堆，存储右半边元素，并且右半边元素都大于左半边 */
    private PriorityQueue<Integer> right;
    public MedianFinder() {
        /* 大顶堆，存储左半边元素 */
       left = new PriorityQueue<>((o1, o2) -> o2 - o1);
        /* 小顶堆，存储右半边元素，并且右半边元素都大于左半边 */
       right = new PriorityQueue<>();
    }
    

    /* 当前数据流读入的元素个数 */
    private int N = 0;
    public void addNum(int num) {
        /* 插入要保证两个堆存于平衡状态 */
        if (N % 2 == 0) {
        /* N 为偶数的情况下插入到右半边。
        * 因为右半边元素都要大于左半边，但是新插入的元素不一定比左半边元素来的大，
        * 因此需要先将元素插入左半边，然后利用左半边为大顶堆的特点，取出堆顶元素即为最大元素，此时插入右半边
        */
            left.add(num);
            right.add(left.poll());
        } else {
            right.add(num);
            left.add(right.poll());
        }
        N++;
    }
    
    public double findMedian() {
        if (N % 2 == 0)
            return (left.peek() + right.peek()) / 2.0;
        else
            return (double) right.peek();
    }
}


   
  
   


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```