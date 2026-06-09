### 解题思路
用小顶堆，保持pq中始终只有最大的k个值，取堆顶即可

### 代码

```java
class KthLargest {

    PriorityQueue<Integer> pq = new PriorityQueue<>();
    int flag;

    public KthLargest(int k, int[] nums) {
            for (Integer c : nums) {
                pq.offer(c);
            }
            if(pq.size() > k){
                for (int i = 0; i < nums.length - k; i++) {
                    pq.remove();
                }
            }
            flag = k;
    }
    public int add(int val) {
        if(pq.size() == flag && val > pq.peek()) {
            pq.remove();
            pq.offer(val);
        }else if(pq.size() < flag){
            pq.offer(val);
        }
        return pq.peek();
    }
}



```