## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)


#### 解法1：大顶堆小顶堆
**【核心思想】**
* 用大顶堆来存比中位数小的数，用小顶堆来存比中位数大的数

**【数据结构】**
* 大顶堆和小顶堆


**【思路】**
* 用大顶堆来存比中位数小的数，用小顶堆来存比中位数大的数
* 保持两个堆的平衡
* 如果总数为奇数，那么中位数就是小顶堆的堆顶；如果总数为偶数，那么中位数就是大顶堆的堆顶和小顶堆的堆顶的平均值

**【代码】**
```java
public class MedianFinder {
    private PriorityQueue<Integer> maxHeap, minHeap;
    /** initialize your data structure here. */
    public MedianFinder() {
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        minHeap = new PriorityQueue<>();
    }
    public void addNum(int num) {
        int size = maxHeap.size() + minHeap.size();
        if(size%2==1){
            //插入之后是偶数 插入大顶堆 并保证大顶堆中均小于小顶堆
            if(minHeap.size()>0&&minHeap.peek()<num)
                minHeap.offer(num);
            else
                maxHeap.offer(num);
         
            while(minHeap.size()-1>maxHeap.size())
            	maxHeap.offer(minHeap.poll());
        }else{
            //插入小顶堆
            if(maxHeap.size()>0&&maxHeap.peek()>num)
                maxHeap.offer(num);
            else
                minHeap.offer(num);
 
            while(minHeap.size()<maxHeap.size())
            	minHeap.offer(maxHeap.poll());
        }
    }
    public double findMedian() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.peek() + minHeap.peek()) * 0.5;
        return minHeap.peek();
    }
}
```
**【备注】**
* addNum()方法的逻辑可以简化

#### 解法2：大顶堆小顶堆

**【核心思想】**
* 用大顶堆来存比中位数小的数，用小顶堆来存比中位数大的数

**【数据结构】**
* 大顶堆和小顶堆


**【思路】**
* 在addNum()方法中，来一个新数先插入到大顶堆中，然后将大顶堆中的最大值插入到小顶堆中
* 如果此时小顶堆的大小比大顶堆大，那么再把小顶堆的最小值插入到大顶堆中，保持平衡

**【代码】**
```java
public class MedianFinder {
    private PriorityQueue<Integer> maxHeap, minHeap;
    /** initialize your data structure here. */
    public MedianFinder() {
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        minHeap = new PriorityQueue<>();
    }
    public void addNum(int num) {
        maxHeap.offer(num);
        minHeap.offer(maxHeap.poll());
        //如果不平衡则调整
        if (minHeap.size() > maxHeap.size())
            maxHeap.offer(minHeap.poll());
    }
    public double findMedian() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.peek() + minHeap.peek()) * 0.5;
        return maxHeap.peek();
    }
}
```
**【关注微信公众号，带你拿大厂offer】**

![logo_gif.gif](https://pic.leetcode-cn.com/f6d7085de4095860835e77030f7fd659dc589c02e9fbc0ed5e125ca913d1b15f-logo_gif.gif)
