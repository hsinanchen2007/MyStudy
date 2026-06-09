### 解法三

继 [排序 + 小顶堆 解法](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/java-pai-xu-xiao-ding-dui-shi-xian-by-yankuangshig/) 时间复杂度最小的方法。借助"快速排序"中的"快速选择" partition（分区函数）的方法实现。

顺便回忆一下”快排“的实现

```
quick_sort(int[] arr, int low, int high) {
    if (low >= high) return;
    int i = partition(arr, low, high);
    quick_sort(arr, low, i-1);
    quick_sort(arr, i+1, high);
}
```

其中 partition 分区函数会任意选择一个元素（该解法中选择最后一个元素arr[len-1]）作为 pivot（分区点），将数组中小于 pivot 的点都放置到其左边，将大于pivot的点都放置在其右边，最终 partition 函数返回 pivot 的下标 i
经过这一步骤后，数组将分成3部分
1、arr[0] ~ arr[i-1] 都是不大于 pivot 的元素
2、arr[i+1] ~ arr[len-1] 都是不小于 pivot 的元素
3、arr[i] 是 pivot 元素

partition 分区过程如下

![partition1.mp4](b0a46a35-4f00-4cae-90bc-98aa08257a5a)

现在思考如何借助 partition 分区来帮助找到第K大元素
如果 pivot 点刚好是第K大元素，那么它的左边一定有 K-1 个不小于它的元素，它的下标应该是 len-k（数组最末尾是 len-1）

所以

1、当 partition 函数返回的下标 i=len-k，则 arr[i] 就是我们要求的第K大元素
2、当 partition 函数返回的下标 i<len-k，那么说明第K大元素在下标 i 的右边，我们继续分区在 arr[i+1, len-1] 区间内查找：partition(arr, i+1, len-1) 
3、当 partition 函数返回的下标 i>len-k，那么说明第K大元素在下标 i 的左边，我们继续分区在 arr[0, i-1] 区间内查找：partition(arr, 0, i-1)

该方法的时间复杂度是O(n)

第一次分区，需要对大小为n的数组执行分区操作，遍历n个元素；
第二次分区，只需要对大小为n/2的数组执行分区操作，遍历n/2个元素；
第三次分区，遍历n/4；
第四次分区，遍历n/8；
...
直到缩减为1
累加起来 n + n/2 + n/4 + n/8 + ... + 1 该公式是个等比数列，等比数列求和
假设
S = n + n/2 + n/4 + n/8 + .... + 1，两边同时乘以2
2S = 2n + n + n/2 + n/4 + ... + 2
2S - S = (2n + n + n/2 + n/4 + ... + 2) - (n + n/2 + n/4 + n/8 + .... + 1) = 2n-1
S = 2n-1
所以总体时间复杂度为O(n)

```java
class Solution {

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        int targetIndex = len - k;
        int low = 0, high = len - 1;
        while (true) {
            int i = partition(nums, low, high);
            if (i == targetIndex) {
                return nums[i];
            } else if (i < targetIndex) {
                low = i + 1;
            } else {
                high = i - 1;
            }
        }
    }

    /**
     * 分区函数，将 arr[high] 作为 pivot 分区点
     * i、j 两个指针，i 作为标记“已处理区间”和“未处理区间”的分界点，也即 i 左边的（low~i-1）都是“已处理区”。
     * j 指针遍历数组，当 arr[j] 小于 pivot 时，就把 arr[j] 放到“已处理区间”的尾部，也即是 arr[i] 所在位置
     * 因此 swap(arr, i, j) 然后 i 指针后移，i++
     * 直到 j 遍历到数组末尾 arr[high]，将 arr[i] 和 arr[high]（pivot点） 进行交换，返回下标 i，就是分区点的下标。
     */
    private int partition(int[] arr, int low, int high) {
        int i = low;
        int pivot = arr[high];
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                swap(arr, i, j);
                i++;
            }
        }
        swap(arr, i, high);
        return i;
    }

    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
```

虽然该方法可以AC，但是时间效率很低，实际平均通过时间为 41ms, beat 14.81%。可以猜测应该是测试用例中有极端情况的存在，导致 partition 分区效率变低，比如数组为升序或倒序数组。因此可以通过随机选择 pivot 分区点来提高分区效率。

```java
private int partition(int[] arr, int low, int high) {
    if (high > low) {
        //在下标 low 和 high 之间随机选择，然后和下标 high 元素进行交换
        int random = low + new Random().nextInt(high - low);
        swap(arr, high, random);
    }
    int i = low;
    int pivot = arr[high];
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, high);
    return i;
}
```

通过以上优化，实际通过时间缩短到 2ms，beat 96.88%。