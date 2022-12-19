### 解题思路
维护一个最大堆

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if( k == 0 || arr.length == 0){
            return new int [0];
        }
        Queue<Integer> pq = new PriorityQueue<>((v1,v2)->v2-v1);
        for(int num : arr){
            if(pq.size() < k){
                pq.offer(num);
            }else{
                if(pq.peek()>num){
                    pq.poll();
                    pq.offer(num);
                }
            }
        }
        int [] res = new int [pq.size()];
        int index = 0;
        for(int num : pq){
            res[index++] = num;
        }
        return res;
    }
}
```