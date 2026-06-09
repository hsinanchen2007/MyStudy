### 解题思路
构建极大堆排序

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (arr.length == 0 || k == 0 || k > arr.length) {
            return new int[] {};
        }
        //优先队列 构建极大堆
        PriorityQueue<Integer>  pq = new PriorityQueue<>((x,y) -> y - x);

        for (int i = 0; i < arr.length; i++) {
            //放入堆中
            if (pq.size() < k) {
                pq.add(arr[i]);
            } else {
                if (pq.peek() > arr[i]) {
                    pq.remove();
                    pq.add(arr[i]);
                }
            }
        }

        //复制返回的数组
        int[] retArr = new int[k];
        k--;

        while (pq.size() > 0) {
            retArr[k--] = pq.remove();
        }

        return retArr;
    }
}
```