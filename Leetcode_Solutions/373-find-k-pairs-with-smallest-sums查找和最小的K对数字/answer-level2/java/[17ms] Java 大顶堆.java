### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.*;

class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        if (nums1.length == 0 || nums2.length == 0 || k == 0)
            return new LinkedList<>();
        // 大顶堆
        PriorityQueue<int[]> heap = new PriorityQueue<>(k, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o2[0] - o1[0];
            }
        });
        for (int i = 0; i < nums1.length; i ++) {
            boolean hasUpdate = false;
            for (int j = 0; j < nums2.length; j++) {
                int sum = nums1[i] + nums2[j];
                // 本次的和比堆中的数都大，意味着后面的都大，无需继续
                if (heap.size() >= k && sum > heap.peek()[0]) {
                    break;
                }
                hasUpdate = true;
                heap.offer(new int[]{sum, nums1[i], nums2[j]});
                if (heap.size() > k) {
                    heap.poll();
                }
                //System.out.println(heap);
            }
            if (!hasUpdate) break;
        }
        List<List<Integer>> ans = new LinkedList<>();
        while (!heap.isEmpty()) {
            int[] ele = heap.poll();
            List<Integer> list = new LinkedList<>();
            list.add(ele[1]);
            list.add(ele[2]);
            ans.add(0, list);
        }
        return ans;
    }
}
```