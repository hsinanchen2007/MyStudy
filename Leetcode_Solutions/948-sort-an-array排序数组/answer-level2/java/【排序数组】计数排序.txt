计数排序是一个非基于比较的排序算法，它的优势在于在对一定范围内的整数排序时，它的复杂度为$Ο(n+k)$（其中 $n$ 是待排序数组的**长度**，$k$ 是待排序数组元素值的**上下界之差**），正常来说，比任何比较排序算法都要快。这是典型的空间换时间，但是需要注意一点：当数据比较分散或者说数据范围很大时，$k$ 可能比 $nlogn$ 都大，这个时候基数排序的性能反而不如一些基于比较的排序算法。其基本思想很简单：
- 找出待排序的数组中最大`maxNum`和最小的元素`minNum`
- 定义一个计数数组`count`，数组长度为`maxNum - minNum + 1`，对待排序数组中的元素进行计数：统计每一个数字`num`出现的次数(我们会设定一个**偏置量**`offset`，使得待排序数组中的元素加上偏置量之后都**不小于零**，偏置量一般取`-minNum`)，并记录在计数数组`count`的第`num`项
- 填充结果数组`result`(或者直接填充到原数组)：取出计数数组每一个非零元素，将该元素**数组下标**`i`作为`result`数组的元素值，该元素的**值**`count[i]`代表重复次数，也就是把`i`重复`count[i]`次填充到`result`中。
![countingSort.gif](https://pic.leetcode-cn.com/a2d831492825af61f191a41000ceaf858fc0627b1d0a12b25679681e892f1f04-countingSort.gif)
> *图片来源：[https://www.runoob.com/w3cnote/counting-sort.html](https://www.runoob.com/w3cnote/counting-sort.html), 侵删*

- 时间复杂度：$O(n + k)$，其中 $n$ 是待排序数组的**长度**，$k$ 是待排序数组元素值的**上下界之差**。

```java
class Solution {
    public int[] sortArray(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return nums;
        }
        // 数组最大值
        int maxNum = Integer.MIN_VALUE;
        // 数组最小值
        int minNum = Integer.MAX_VALUE;
        for (int num: nums) {
            maxNum = Math.max(maxNum, num);
            minNum = Math.min(minNum, num);
        }
        // 计数数组
        int[] count = new int [maxNum - minNum + 1]; 
        // 结果数组（这里可以不重新定义一个数组，直接用原数组也行）
        int[] result = new int[nums.length];
        
        // 偏置量（使得计数数组不越界）
        int offset = -minNum;       
        for (int num: nums) {
            count[num + offset]++;
        }
        int index = 0;
        for (int i = 0; i < count.length; i++) {
            // 某个元素出现多次，就将多个该元素放到结果数组中
            if (count[i] > 0) {
                for (int j = 1; j <= count[i]; j++) {
                    result[index] = i - offset;
                    index++;
                }
            }
        }
        return result;
    }
}
```

![image.png](https://pic.leetcode-cn.com/44aea348835592512522c789b59d22d5598d7f78fd0a5e4fd75fa1f079558d7e-image.png)