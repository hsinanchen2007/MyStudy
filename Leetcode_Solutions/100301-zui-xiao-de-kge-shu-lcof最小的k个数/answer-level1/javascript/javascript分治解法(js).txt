Top K 问题的另一个分治解法就比较难想到，需要在平时有算法的积累。实际上，“查找第 k 大的元素”是一类算法问题，称为选择问题。找第 k 大的数，或者找前 k 大的数，有一个经典的 quick select（快速选择）算法。这个名字和 quick sort（快速排序）看起来很像，算法的思想也和快速排序类似，都是分治法的思想。

让我们回顾快速排序的思路。快速排序中有一步很重要的操作是 partition（划分），从数组中随机选取一个枢纽元素 v，然后原地移动数组中的元素，使得比 v 小的元素在 v 的左边，比 v 大的元素在 v 的右边，如下图所示：

partiition

这个 partition 操作是原地进行的，需要 O(n)O(n) 的时间，接下来，快速排序会递归地排序左右两侧的数组。而快速选择（quick select）算法的不同之处在于，接下来只需要递归地选择一侧的数组。快速选择算法想当于一个“不完全”的快速排序，因为我们只需要知道最小的 k 个数是哪些，并不需要知道它们的顺序。

我们的目的是寻找最小的 kk 个数。假设经过一次 partition 操作，枢纽元素位于下标 mm，也就是说，左侧的数组有 mm 个元素，是原数组中最小的 mm 个数。那么：

若 k = mk=m，我们就找到了最小的 kk 个数，就是左侧的数组；
若 k<mk<m ，则最小的 kk 个数一定都在左侧数组中，我们只需要对左侧数组递归地 parition 即可；
若 k>mk>m，则左侧数组中的 mm 个数都属于最小的 kk 个数，我们还需要在右侧数组中寻找最小的 k-mk−m 个数，对右侧数组递归地 partition 即可。
这种方法需要多加领会思想，如果你对快速排序掌握得很好，那么稍加推导应该不难掌握 quick select 的要领。

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    if (arr.length <= k) {
        return arr;
    }
    partitionArray(arr, 0, arr.length - 1, k);
    return arr.slice(0, k);
};
function partitionArray(arr, low, high, k) {
    const mid = partition(arr, low, high);
    if (mid === k) {
        return;
    }
    if (mid < k) {
        partitionArray(arr, mid + 1, high, k);
    } else {
        partitionArray(arr, low, mid - 1, k);
    }
}
function partition(arr, low, high) {
    let i = low;
    let j = low - 1;
    const mid = arr[high];
    while (i < high) {
        if (arr[i] < mid) {
            swap(arr, j + 1, i);
            j++;
        }
        i++;
    }
    swap(arr, j + 1, high);
    return j + 1;
}
function swap(arr, i, j) {
    const temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
```