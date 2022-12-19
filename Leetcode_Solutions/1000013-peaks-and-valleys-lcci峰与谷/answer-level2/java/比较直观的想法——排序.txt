# 思路
先copyOf()出1个新数组，对其排序。
比如排序结果为：1, 2, 3, 4, 5
每次取1个最大值，再取1个最小值，如此往复直到取完即可：
如：先取最大值`5`，得到为`5`, 剩余`1, 2, 3, 4`
再取最小值1，得到`5, 1`，剩余`2, 3, 4`
再取最大值4，得到`5, 1, 4`, 剩余`2, 3`
再取最小值2，得到`5, 1，4, 2`, 剩余`3`
再取最大值3，得到`5, 1，4, 2, 3`，无剩余

简而言之就是头拿1个，尾拿1个即可

# 完全排序(Arrays.sort())代码
```java
class Solution {
    public void wiggleSort(int[] nums) {
        int idx = 0, len = nums.length;
        if (len < 3) return;
        int low = 0, high = len - 1;
        int[] sorted = Arrays.copyOf(nums, len);
        Arrays.sort(sorted);
        while (low < high) {
            nums[idx++] = sorted[high--];
            nums[idx++] = sorted[low++];
        }
        if (len % 2 > 0)
            nums[idx] = sorted[low];
    }
}
```

# 优先队列(堆)
基于上面的思想，发现其实并不需要使得数组整体有序，只需要以数组的中间为界线，界线左侧的值全部都 < 界线右侧的任意值即可。(可以联想到**快速排序**)
也就是说，找到数组中前nums.length / 2个大(或小)的值，即可满足这种思想。
```java
class Solution {
    public void wiggleSort(int[] nums) {
        int i = 0, len = nums.length;
        if (len < 3) return;
        int half = len >> 1, idx = 0;
        int[] copy_nums = Arrays.copyOf(nums, len);
        PriorityQueue<Integer> min_heap = new PriorityQueue<>();
        for (; i < half; ++i)
            min_heap.offer(copy_nums[i]);
        for (; i < len; ++i) {
            min_heap.offer(copy_nums[i]);
            nums[idx] = min_heap.poll();
            idx += 2;
        }
        idx = 1;
        for (int num : min_heap) {
            nums[idx] = num;
            idx += 2;
        }
    }
}
```

