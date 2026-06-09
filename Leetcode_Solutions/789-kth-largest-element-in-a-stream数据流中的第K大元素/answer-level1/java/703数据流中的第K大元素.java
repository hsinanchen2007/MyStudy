### 解题思路
此处撰写解题思路

### 代码

```java
class KthLargest {
    PriorityQueue<Integer> queue;
    int maxK;

    public KthLargest(int k, int[] nums) {
        maxK=k;
        queue=new PriorityQueue<>(k);
        for(int num:nums){           
            add(num);
        }
    }
    
    public int add(int val) {
        if(queue.size()<maxK){
            queue.add(val);
        }else if(queue.peek()<val){
            queue.poll();
            queue.add(val);
        }
        return queue.peek();

    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```