
这道题坑挺多，debug了好久

如果没有思路，建议先理解295题，在大顶堆小顶堆之外增加了移除操作。 
可以参考 [295代码](https://github.com/icecrea/leetcode/blob/master/src/main/java/com/example/swordoffer/Sword63_StreamMid.java)

注意
1.声明大顶堆，不要用maxheap = new PriorityQueue<>((x, y) -> y - x)形式， 在相等的时候会有问题。
2.两个Int最大值相加溢出情况
3.删除操作之后，大根堆和小根堆的数量有可能会存在 2-3 或者 4-2这种情况 所以添加操作的判断条件为minheap.size() > maxheap.size()
```
class Solution {
     PriorityQueue<Integer> maxheap = new PriorityQueue<>(Comparator.reverseOrder());
    PriorityQueue<Integer> minheap = new PriorityQueue<>();

    public double[] medianSlidingWindow(int[] nums, int k) {
        double[] arr = new double[nums.length - k + 1];
        for (int i = 0; i < nums.length; i++) {
            if (i >= k) {
                remove(nums[i - k]);
            }
            add(nums[i]);
            if (i >= k - 1) {
                buildMidArray(arr, k, i);
            }
        }
        return arr;
    }

  /**
     * 注意这里移动回大根堆的条件：
     * minheap.size() > maxheap.size()
     * 因为当删除操作之后，大根堆和小根堆的数量有可能会存在 2-3 或者 4-2这种情况
     */
    private void add(int num) {
        maxheap.add(num);
        minheap.add(maxheap.poll());
        if(minheap.size() > maxheap.size()){
            maxheap.add(minheap.poll());
        }
    }

    private void remove(int num) {
        if (maxheap.peek() >= num) {
            maxheap.remove(num);
        } else {
            minheap.remove(num);
        }
    }

    private void buildMidArray(double[] arr, int k, int i) {
        if ((k & 1) == 1) {
            arr[i - k + 1] = maxheap.peek();
        } else {
            double sum = (double) maxheap.peek() + minheap.peek();
            arr[i - k + 1] = sum / 2;
        }
    }
}
```
git代码地址：[滑动窗口中位数](https://github.com/icecrea/leetcode/blob/master/src/main/java/com/example/leetcode/other/LeetCode480_SlidingWindowMedian.java)