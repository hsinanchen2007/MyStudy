![GKWEef.png](https://pic.leetcode-cn.com/0ec2af0824cd945484e93f62e282cfd64f24f1b95877b4a551c38402d1a5449e.png)

### 解题思路

思路都写在了代码注释中。

大意是通过一个滑动窗口将所有大于基准值的元素都包裹在其中，小于基准值的都丢在滑动窗口的前面的外边。

然后将基准值插到滑动窗口的前面即可，这样大于基准的都在右边，小于基准的都在左边。

思路和一般的快速排序不太相同，但是理解了之后觉得非常巧妙而容易记忆，故推荐给大家。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    // 快速排序
    function quickSort(array, start = 0, end = array.length - 1) {
        if (start < end) {
            // 取基准值，将array的每个元素与基准值大小比对后放在基准值的左边或者右边
            let pivot = divide(array, start, end);
            // 对小于基准值的元素排序
            quickSort(array, start, pivot - 1);
            // 对大于基准值的元素排序
            quickSort(array, pivot + 1, end);
        }
        return array;
    }

    function divide(array, start, end) {
        // 取中位数作为pivot以避免基本有序时时间复杂度飙升的问题
        let mid = (start + end) >> 1; // 即mid = Math.floor((start + end) / 2);
        // 将中位数交换到开头
        [array[start], array[mid]] = [array[mid], array[start]];
        let pivot = start;
        
        // 构建一个[low, high]的滑动窗口，想要实现窗口里包含的都是大于pivot的数
        let low = start + 1;
        // 一开始窗口里还没有内容（low=high）
        for (let high = low; high <= end; high++) {
            // 找到的数是小于pivot的数
            if (array[high] < array[pivot]) {
                // 小于pivot的数丢到窗口的第一位去
                [array[low], array[high]] = [array[high], array[low]];
                // 将第一位挤出窗口
                low++;
            }
            // 大于pivot的数，则仅high++，使得窗口扩大
        }
        // 将pivot插回该在的位置
        // 区间(pivot, low-1]的数都小于pivot
        // 区间[low, high)的数都大于等于pivot
        // 故将pivot与low-1交换即可（不与low交换，是因为[low, high)可能没有包含任何的元素，是越界的）
        [array[pivot], array[low - 1]] = [array[low - 1], array[pivot]];
        return low - 1;
    }
    // 调用自定义快排函数
    return quickSort(nums);
};
```

<br>

---

> 我的GitHub： https://github.com/ceynri 欢迎来访~