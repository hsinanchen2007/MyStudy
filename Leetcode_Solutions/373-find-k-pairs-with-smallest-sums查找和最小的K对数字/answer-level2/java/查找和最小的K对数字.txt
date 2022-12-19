### 方法一：暴力法

#### 思路：
设数组`nums1`的长度为`n1`,数组`num2`的长度为`n2`。我们可以暴力枚举全部的`n1*n2`对数字，然后对他们的和按照由小到大的顺序进行排序，然后选取前`K`对数来解决该问题。

#### 算法：
暴力枚举全部`n1*n2`对数字，排序后取其前`K`对。
时间复杂度`O(n1 * n2)`，空间复杂度`O(n1 * n2)`

```java []
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        int n1 = nums1.length, n2 = nums2.length;
        List<List<Integer>> result = new ArrayList<>();
        
        
        if (n1 == 0 || n2 == 0 || k == 0) return result;
        
        int[][] arr = new int[n1 * n2][2];
        int idx = 0;

        for (int i = 0; i < n1; i++) {
        	for (int j = 0; j < n2; j++) {
        		arr[idx][0] = nums1[i];
        		arr[idx][1] = nums2[j];
        		idx++;
        	}
        }

        Arrays.sort(arr, (o1, o2) -> (o1[0] + o1[1]) - (o2[0] + o2[1]));

        for (int i = 0; i < Math.min(k, arr.length); i++) {
        	List<Integer> temp = new ArrayList<>();
        	temp.add(arr[i][0]);
        	temp.add(arr[i][1]);
        	result.add(temp);
        }

        return result;
    }
}
```

### 方法二：优先级队列（堆）

#### 思路:
我们可以利用堆，在不枚举出全部数对的情况下解决该问题，从而提高效率。
由于`nums1`和`nums2`均是已经排好序的升序数组，我们可以固定选择`nums1`中的一个数字`nums[k]`,让其依次和`nums2`中的每个数对进行组合从而形成一个以升序排列的数对队列。
例：`nums1 = [1,7,11], nums2 = [2,4,6]`

![WX20190820-143004@2x.png](https://pic.leetcode-cn.com/b9f1f9a754efd9b679d131c9504989c33159607d2e7e68de481c28bab2d1223d-WX20190820-143004@2x.png)

这样，我们将原问题转换成在`n1`个升序队列中，查找最小的前`K`对数字。为了解决该问题，我们可以参考[leetcode 23 合并K个有序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)的方法。我们统计`n1`个升序队列的队首元素中的最小值，将其加入结果队列，并将指向该队首的指针向后移，直到我们找齐前`K`对数字。

#### 算法:
维护一个堆，存放`n1`个升序队列的队首元素，每个元素为一个长度为`2`数组，里面存放的是`nums1`和`nums2`中某个数字的**下标**。堆中的元素按照数对和由小到大顺序排列，每次我们取出堆中数对和最小的数对，加入结果数组。同时将该数对所在的队列中下一个元素(若存在的话)加入堆中，如此反复直至我们找齐全部`K`对数字或堆的大小为空。
```java []
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        int n1 = nums1.length, n2 = nums2.length;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> (nums1[o1[0]]+nums2[o1[1]]) - (nums1[o2[0]]+nums2[o2[1]]));
        List<List<Integer>> result = new ArrayList<>();
        
        if (n1 == 0 || n2 == 0 || k == 0) return result;
        for (int i = 0; i < n1; i++) pq.offer(new int[]{i, 0});

        while(pq.size() > 0 && k > 0) {
        	int[] pair = pq.poll();
        	if (pair[1] + 1 < n2) pq.offer(new int[]{pair[0], pair[1]+1});
        	List<Integer> temp = new ArrayList<>();
        	temp.add(nums1[pair[0]]);
        	temp.add(nums2[pair[1]]);
        	result.add(temp);
                k--;
        }

        return result;
    }
}
```
#### 复杂度分析
- 时间复杂度：$O(KlogN1)$ 其中N1是数组$nums1$的长度。
- 空间复杂度：$O(K)$ 




