### 解题思路
1. 借助于小顶堆和大顶堆，Java中默认是小顶堆，大顶堆需要处理下判断规则
2. 需要保持左右数目的平衡，设置一个变量保存当前输入的元素数目
3. 定制自己的规则：奇数个放入左边，偶数个放入右边
4. 放入左边时，先放入右边，然后将右边堆顶元素放入左边即可
5. 放入右边时，先放入左边，然后将左边堆顶元素放入右边即可

### 代码

```java
class MedianFinder {
    // left为大顶堆，存储输入流中排序后的左半部分
    private PriorityQueue<Integer> left;
    // right为小顶堆，存储输入流中排序后的右半部分
    private PriorityQueue<Integer> right;

    // 当前数据流中的元素数目
    private int count = 0;

    /** initialize your data structure here. */
    public MedianFinder() {
        // Java中默认是小顶堆，大顶堆需要处理下判断规则
        left = new PriorityQueue<Integer>((o1, o2) -> (o2 - o1));
        right = new PriorityQueue<Integer>();
        count = 0;
    }
    
    public void addNum(int num) {
        count++;
        if (count % 2 == 1) { 
            // 此元素应该被放入left
            // 直接放入right，将right的堆顶元素挪到left即可
            right.offer(num);
            left.offer(right.poll());
        } else {
            // 此元素应该放入right
            // 首先放入left，然后将left的堆顶元素挪到right即可
            left.offer(num);
            right.offer(left.poll());
        }
    }
    
    public double findMedian() {
        if (count % 2 == 1) {
            // 从left返回即可
            return left.peek();
        }

        return (left.peek() + right.peek()) / 2.0;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```