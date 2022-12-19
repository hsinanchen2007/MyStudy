# 思路
- 通过快排将数组排序，然后循环取出最小值放入新数组中

```
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    // arr.sort((a, b) => a - b)
    qSort(arr)
    let res = []
    for (let i = 0; i < k; i++) {
        res.push(arr[i])
    }

    return res
}

//快排
const qSort = (arr) => {
    const swap = (arr, i, j) => {
        let temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
    }

    const findCenter = (arr, left, right) => {
        let flag = arr[left]
        let idx = left + 1

        for (let i = idx; i <= right; i++) {
            if (arr[i] < flag) {
                swap(arr, idx, i)
                idx++
            }
        }

        swap(arr, left, idx - 1)
        return idx
    }

    const sort = (arr, left, right) => {
        if (left < right) {
            let center = findCenter(arr, left, right)
            sort(arr, left, center - 1)
            sort(arr, center, right)
        }
    }

    sort(arr, 0, arr.length - 1)
    return arr
}
```
