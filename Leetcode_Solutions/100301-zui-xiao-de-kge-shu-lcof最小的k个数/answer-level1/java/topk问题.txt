### 解题思路
此处撰写解题思路
最小k个-->大顶堆
执行用时 :
36 ms
, 在所有 Java 提交中击败了
17.88%
的用户
内存消耗 :
41.3 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        PriorityQueue<Integer> heap = new PriorityQueue<Integer>((n1, n2) -> n2 - n1);
        int[] res = new int [k];
        for (int n : arr){
            heap.add(n);
            if (heap.size() > k) heap.poll();
        }
        for (int i = 0; i < k; i++){
            res[i] = heap.poll();
        }
        return res;
    }
}
```