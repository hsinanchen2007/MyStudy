### 解题思路
快排，判断是否刚刚好分成k块
### 解题结果
![image.png](https://pic.leetcode-cn.com/e3f39129153835343b6d75ae114ebd88998f5b8859b1ed66ff72960e92a4da4f-image.png)

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var smallestK = function (arr, k) {
      const quickSort = function (arr, left, right) {
        if (left >= right) {
            return;
        }
        let i = left;
        let j = right;
        let key = arr[left];
        while (i < j) {
            while (i < j && arr[j] >= key) {
                j--;
            }
            arr[i] = arr[j];
            while (i < j && arr[i] <= key) {
                i++;
            }
            arr[j] = arr[i];
        }
        arr[i] = key;
        if (i === k - 1) {
            // 这种情况是刚刚好左边排好最小k个
            return;
        } else if (k - 1 < i) {
            quickSort(arr, left, i - 1);
        } else {
            // (k - 1 > i)
            quickSort(arr, i + 1, right);
        }

    }
    quickSort(arr, 0, arr.length - 1);
    return arr.slice(0, k);
};
```