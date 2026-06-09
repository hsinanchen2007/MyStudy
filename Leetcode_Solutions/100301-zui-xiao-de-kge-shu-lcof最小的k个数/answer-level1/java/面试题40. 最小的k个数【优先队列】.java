### 解题思路
(1) 遍历输入数组，将前k个数插入到推中；（利用PriorityQueue来做为堆的实现）
(2) 继续从输入数组中读入元素做为待插入整数，并将它与堆中最大值比较：
    如果待插入的值比当前已有的最大值小，则用这个数替换当前已有的最大值；
    如果待插入的值比当前已有的最大值还大，则抛弃这个数，继续读下一个数。
    这样动态维护堆中这k个数，以保证它只储存输入数组中的前k个最小的数，最后输出ans即可
    ，时间复杂度O(nlogk)

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {

       int[] ans = new int[k];
       int j = 0;
        if (arr == null || k <= 0 || k > arr.length) {
            return ans;
        }
        PriorityQueue<Integer> queue = new PriorityQueue<>(k, Collections.reverseOrder());
 
        for (int i = 0; i < arr.length; i++) {
 
            if (queue.size() < k) {
                queue.add(arr[i]);
            } else {
                if (arr[i] < queue.peek()) {
                    queue.remove();
                    queue.add(arr[i]);
                }
            }
        }
        while (!queue.isEmpty()) {
            ans[j++]=queue.remove();
        }
        return ans;
    }
}
```