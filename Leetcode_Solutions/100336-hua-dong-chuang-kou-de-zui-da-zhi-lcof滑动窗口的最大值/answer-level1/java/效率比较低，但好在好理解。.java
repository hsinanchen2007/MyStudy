### 解题思路
1.判断边界非法条件
2.创建大顶堆，每次堆顶肯定是最大值
3.将前K个数装入大顶堆
4.从第K个开始遍历，每次装一个尾，删除一个头
5.最后不要忘了最后一个数。
时间复杂度应该是nlogk？

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return new int[]{};
        }
        if (nums.length < k) {
            return nums;
        }
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        for (int i = 0; i < k; i++) {
            priorityQueue.add(nums[i]);
        }

        int[] results = new int[nums.length - k + 1];
        int index = 0;
        for (int i = k; i < nums.length; i++) {
            results[index++] = priorityQueue.peek();
            priorityQueue.remove(nums[i - k]);
            priorityQueue.add(nums[i]);
        }
        results[results.length - 1] = priorityQueue.peek();
        return results;
    }
}
```