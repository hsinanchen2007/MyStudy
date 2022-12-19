## 暴力使用大顶堆

对于再某集合中寻找前K小的元素，我们都知道可以使用大小为`k`的大顶堆，依次遍历集合中的各个元素：

- 若堆未满，则将元素放入堆
- 若堆已满：
  - 如果遍历到的元素比堆顶大，则跳过
  - 如果比堆顶小，则移除堆顶，将当前元素加入堆

最后队中所剩的K个元素即为我们所要找的前K小的元素。

对于本题，我们可以将两个数组所能组成的所有数对作为集合，使用以上方法找出最小的K个元素：

```java
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        // 大顶堆，比较器使用lambda表达式，更简洁
        PriorityQueue<List<Integer>> queue = new PriorityQueue<>(k, (o1, o2)->{
            return (o2.get(0) + o2.get(1)) - (o1.get(0) + o1.get(1));
        });
        
        // 遍历所有可能的集合
        for(int i = 0; i < Math.min(nums1.length, k); i++){
            for(int j = 0; j < Math.min(nums2.length, k); j++){
                // 剪枝，如果当前的两个数之和超过了堆顶元素，由于数组已经排序，后面的元素只会更大，因此无需继续遍历
                if(queue.size() == k && nums1[i]+nums2[j] > queue.peek().get(0) + queue.peek().get(1)){
                    break;
                }

                // 若比堆顶小，则弹出堆顶元素，把当前数对加入
                if(queue.size() == k){
                    queue.poll();
                }
                List<Integer> pair = new ArrayList<>();
                pair.add(nums1[i]);
                pair.add(nums2[j]);
                queue.add(pair);
            }
        }

        // 最后将元素弹出，倒序插入数组即可
        List<List<Integer>> res = new LinkedList<>();
        for(int i =0; i < k && !queue.isEmpty(); i++){
            res.add(0, queue.poll());
        }
        return res;
    }
}
```

## 使用小顶堆

这个想法借鉴了 [23.合并K个排序链表](https://leetcode.com/problems/merge-k-sorted-lists/)。

举个例子，示例中给出的数组是：

```
nums1 = [1,7,11]
nums2 = [2,4,6]
```

我们把这个问题转换为合并K个有序数组，则我们可以把数组转换为：

```
(1,2)->(1,4)->(1,6)
(7,2)->(7,4)->(7,6)
(11,2)->(11,4)->(11,6)
```

在合并K个有序数组中我们是如何做的的呢？

1. 把每个数组的第一个元素加入小顶堆
2. 弹出小顶堆的堆顶元素
3. 弹出的元素来自哪个数组，就把那个数组的下一个元素加入小顶堆
4. 重复2，直到所有数组都没有下一个元素

本题中我们只需要弹出K次，即可获取前K小的元素

```java
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        // 小顶堆
        PriorityQueue<int[]> queue = new PriorityQueue<>(
                (o1, o2) -> (nums1[o1[0]] + nums2[o1[1]]) - (nums1[o2[0]] + nums2[o2[1]]));
        List<List<Integer>> res = new LinkedList<>();
        
        // 两个数组有一个为空，返回空
        if(nums1.length==0 || nums2.length == 0){
            return res;
        }

        // 将我们假想的每个数组的第一项加入小顶堆
        for (int i = 0; i < Math.min(nums1.length, k); i++) {
            queue.add(new int[] { i, 0 }); // 加入的是坐标，小顶堆的比较器也是基于坐标比较
        }

        // 循环K次或者堆空
        while (k > 0 && !queue.isEmpty()) {
            // 弹出堆顶元素
            int[] pair = queue.poll();
            List<Integer> item = new ArrayList<>();
            item.add(nums1[pair[0]]);
            item.add(nums2[pair[1]]);

            // 若我们假想的数组有下一个元素，则加入小顶堆
            if (pair[1] < nums2.length - 1) {
                queue.add(new int[] { pair[0], pair[1] + 1 });
            }
            res.add(item);
            k--;
        }
        return res;
    }
}
```