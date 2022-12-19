### 解题思路
维护一个k大小的小顶堆，堆顶即为第K大元素

### 代码

```java
class KthLargest {

    PriorityQueue<Integer> q;
    int k;

    public KthLargest(int k, int[] nums) {
        this.q = new PriorityQueue<>(k);
        this.k = k;
        for(int num:nums){
            add(num);
        }
    }
    
    public int add(int val) {
        if(q.size() < k){
            q.offer(val);
        }else if (val >= q.peek()){
            q.poll();
            q.offer(val);  
        }
        return q.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```