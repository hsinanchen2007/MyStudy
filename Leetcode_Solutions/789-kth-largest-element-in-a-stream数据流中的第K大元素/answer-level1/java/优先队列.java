实现
```java
class KthLargest {
    //创建final优先队列变量q、第k大元素变量k
    private final PriorityQueue<Integer> q;
    private final int k;

    public KthLargest(int k, int[] nums) {
        //初始化
        q = new PriorityQueue<>();
        this.k = k;
        //循环把数组值在add方法规则下存入队列
        for (int n : nums)
            add(n);
    }
    
    public int add(int val) {
        //判断队列大小小于k，直接存入，否则判断val大于队列顶值，poll出顶值，将val值offer
        if (q.size() < k) {
            q.offer(val);
        } else if (val > q.peek()){
            q.poll();
            q.offer(val);
        }
        //返回顶值
        return q.peek();
    }
}
```

测试
```java
class KthLargestTest {
    @Test
    void test() {
        int k = 3;
        int[] nums = new int[]{4, 5, 8, 2};
        KthLargest kthLargest = new KthLargest(k, nums);
        assertEquals(3, kthLargest.add(10));
        assertEquals(4, kthLargest.add(1));
        assertEquals(4, kthLargest.add(4));
        assertEquals(8, kthLargest.add(3));
    } 
}
```
