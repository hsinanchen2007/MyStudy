### 解题思路
 * 快速排序
 * 最大最小swap

### 代码

```javascript
/**
 * 快速排序
 * 
 * @param {number[]} nums 
 * @returns {number[]}
 */
var sortArray = function (nums) {
    quickSort(0, nums.length - 1);
    return nums;
    function quickSort(a, b) {
        let m = divide(a, b);
        if (m > a) {
            quickSort(a, m - 1);
        }

        if (m < b) {
            quickSort(m + 1, b);
        }
    }

    /**
     * 对nums的i - j 快速排序
     * @param {number} i 
     * @param {number} j 
     * @returns {number} middle
     */
    function divide(a, b) {
        let v = nums[a];
        let i = a;
        let j = b;
        while (i < j) {
            while (i <= j && nums[i] <= v) {
                i++;
            }
            while (i <= j && nums[j] > v) {
                j--;
            }
            if (i >= j) break;
            swap(nums, i, j);
        }
        swap(nums, j, a);
        return j;
    }
};

function swap(list, i, j) {
    const temp = list[j];
    list[j] = list[i];
    list[i] = temp;
}
```