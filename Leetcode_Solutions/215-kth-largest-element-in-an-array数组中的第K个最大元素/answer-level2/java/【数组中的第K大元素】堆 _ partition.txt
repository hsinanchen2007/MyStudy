[toc]
#### 题目描述
在未排序的数组中找到第 `k` 个最大的元素。请注意，你需要找的是数组排序后的第 `k` 个最大的元素，而不是第 `k` 个不同的元素

#### 解题思路
这题是一道很经典的题目了，最直接的方法就是先排序，复杂度为$nlogn$，显然不是很理想。常见的思路有**基于堆**和**基于快排的`partition`**。
##### 1、基于堆
**小顶堆**（`min-heap`）有个重要的性质——每个结点的值均不大于其左右孩子结点的值，则堆顶元素即为整个堆的最小值。Java中的`PriorityQueue`实现了数据结构堆，通过指定`comparator`字段来表示小顶堆或大顶堆，默认为`null`，表示自然序（`natural ordering`）。

堆解决这类**Top K**问题的思路：堆中维护当前扫描到的最大K个数，其后每一次的扫描到的元素，若大于堆顶，则入堆，然后删除堆顶；依此往复，直至扫描完所有元素。具体代码如下：

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minQueue = new PriorityQueue<>(k);
        for (int num : nums) {
            if (minQueue.size() < k || num > minQueue.peek()) {
                minQueue.offer(num);
            }
            if (minQueue.size() > k) {
                minQueue.poll();
            }
        }
        return minQueue.peek();
    }
}
```
- 时间复杂度：$O(nlogk)$

##### 2、基于快排`Quick Sort`的`partition`
这种方法应该叫**快速选择**（`Quick Select`），跟快排的思想是非常接近的：选取一个基准元素`pivot`，将数组切分（`partition`）为两个子数组，比`pivot`大的扔左子数组，比`pivot`小的扔右子数组，然后递推地切分子数组。`Quick Select`不同于`Quick Sort`的是其没有对每个子数组做切分，而是对目标子数组做切分。
快排的一般实现：
```java
// Quick Sort
public void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int index = partition(arr, left, right);
    quickSort(arr, left, index - 1);
    quickSort(arr, index + 1, right);
}

private int partition(int arr[], int left, int right) {
    int i = left, j = right + 1, pivot = arr[left];
    while (true) {
        while (i < right && arr[++i] > pivot) {
            if (i == right) break;
        }
        while (j > left && arr[--j] < pivot) {
            if (j == left) break;
        }
        if (i >= j) break;
        swap(arr, i, j);
    }
    swap(arr, left, j); 
    return j;
}

private void swap(int[] arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
```
`Quick Select`的目标是找出第`k`大元素，所以:
- 若切分后的左子数组的长度 > `k`，则第`k`大元素必出现在左子数组中；
- 若切分后的左子数组的长度 = `k - 1`，则第`k`大元素为`pivot`；
- 若上述两个条件均不满足，则第`k`大元素必出现在右子数组中。
基于上述，则可以很容易的得出`Quick Select`的实现代码:
```java
// Quick Select
class Solution {
    public int findKthLargest(int[] nums, int k) {
        return quickSelect(nums, k, 0, nums.length - 1);
    }

    public int quickSelect(int[] arr, int k, int left, int right) {
        if (left == right) return arr[right];
        int index = partition(arr, left, right);
        if (index - left + 1 > k) {
            return quickSelect(arr, k, left, index - 1);
        } else if (index - left + 1 == k) {
            return arr[index];
        } else {
            return quickSelect(arr, k - index + left - 1, index + 1, right);
        }
    }

    private int partition(int arr[], int left, int right) {
        int i = left, j = right + 1, pivot = arr[left];
        while (true) {
            while (i < right && arr[++i] > pivot) {
                if (i == right) break;
            }
            while (j > left && arr[--j] < pivot) {
                if (j == left) break;
            }
            if (i >= j) break;
            swap(arr, i, j);
        }
        swap(arr, left, j); 
        return j;
    }

    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
```