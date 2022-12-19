### 解题思路
利用优先队列，思路清晰，每次只需要把最小的值出队列，然后把取反的值加入队列。
但时间和空间复杂度不理想。

### 代码

```java
class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
     //每次取反最小值取反
     PriorityQueue<Integer> pq=new PriorityQueue<Integer>();
     for(int i:A)
      pq.add(i);
      int min,sum=0;
     while(K>0)
     {
         K--;
         min=pq.poll();
         pq.add(-min);
     }
     for(int i:A)
        sum+=pq.poll();
    return sum;
    } 
}
```