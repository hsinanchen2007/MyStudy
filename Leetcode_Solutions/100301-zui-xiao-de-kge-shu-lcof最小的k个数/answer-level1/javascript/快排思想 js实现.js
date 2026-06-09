```
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function (arr, k) {
    qSort(0, arr.length - 1);

    return arr.slice(0, k)

    function qSort(m, n) {
        if (m >= n) {
            return;
        }

        let pivot = arr[n];
        let i = m;
        let j = m;
        while (i < n) {
            if (arr[i] <= pivot) {
                let tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
                j++;
            }

            i++;
        }

        let tmp = arr[j];
        arr[j] = pivot;
        arr[n] = tmp;

        if (j === k) {
            return;
        } else if (j > k) {
            qSort(m, j - 1)
        } else {
            qSort(j + 1, n)
        }

    }
};
```
