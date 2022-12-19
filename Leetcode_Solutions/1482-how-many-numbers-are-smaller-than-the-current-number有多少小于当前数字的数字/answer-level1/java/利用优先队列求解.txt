### 解题思路
优先队列可以存储各个元素的序号并排序。然后按序取出时便可计算小于当前元素值的元素个数。

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int len = nums.length;
        int[] res = new int[len];
        PriorityQueue<int[]> que = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        for (int i = 0;i < len;i++) {
            int [] arr = new int[2];
            arr[0] = nums[i];
            arr[1] = i;
            que.offer(arr);
        }
        int i = 0,j = 0;
        while (i < len) {
            int tem = (que.peek())[0];
            j  = i;
            while (i < len && que.peek()[0] == tem) {
                int[] arr = que.remove();
                res[arr[1]] = j;
                i++;
            }
        }
        return res;
    }
}
```