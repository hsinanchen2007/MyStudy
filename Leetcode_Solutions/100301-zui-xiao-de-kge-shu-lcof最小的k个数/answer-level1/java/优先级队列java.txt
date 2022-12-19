### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
        public int[] getLeastNumbers(int[] arr, int k) {
        if (arr == null || arr.length <= k) {
            return arr;
        }
        if (k == 0) {
            return new int[0];
        }
        PriorityQueue<Integer> heap = new PriorityQueue<>((o1, o2) -> {
            if (o1 > o2) {
                return -1;
            } else {
                return 1;
            }
        });
        for (int num : arr) {
            heap.add(num);
            if (heap.size() > k) {
                heap.poll();
            }
        }
        int[] res = new int[k];
        int index = 0;
        for (int num : heap) {
            res[index++] = num;
        }
        return res;
    }
}
```