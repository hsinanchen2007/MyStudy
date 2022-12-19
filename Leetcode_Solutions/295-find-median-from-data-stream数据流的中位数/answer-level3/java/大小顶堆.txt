### 解题思路
构造一个大顶堆，一个小顶堆
增加元素的时候要确保：
1. 小顶堆的元素个数>=大顶堆的元素个数
2. 小顶堆的元素最多只比大顶堆的元素多1个
这样 数据流的中位数就是大小顶堆的peek值


### 代码

```java
class MedianFinder {

    
    private PriorityQueue<Integer> max_pq;
    private PriorityQueue<Integer> min_pq;

    /** initialize your data structure here. */
    public MedianFinder() {
        max_pq = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2-o1;
            }
        });
        min_pq = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1-o2;
            }
        });
    }

    public void addNum(int num) {
        //添加元素的时候保持两个堆的大小相等
        //要让大顶堆的顶部元素小于或等于小顶堆的顶部元素
        //优先存储在小顶堆中
        if (min_pq.size() == 0)
            min_pq.add(num);
        else{
            if (num >= min_pq.peek())
                min_pq.add(num);
            else {
                max_pq.add(num);
            }
            //调整堆的大小
            if (min_pq.size() - max_pq.size() >= 2)
                max_pq.add(min_pq.remove());
            else if (max_pq.size() > min_pq.size())
                min_pq.add(max_pq.remove());
        }
    }

    public double findMedian() {
        if (!min_pq.isEmpty() && !max_pq.isEmpty() && (min_pq.size() + max_pq.size()) % 2 == 0)
            return (min_pq.peek() + max_pq.peek()) / 2.0;
        return min_pq.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```