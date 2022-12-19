### 解题思路
1.用大堆存k个数
2.对原数组k后面开始遍历，跟大堆第一个最大值对比，比他小就交换
3.继续对大堆进行调整
### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var smallestK = function (arr, k) {
    const swap = (arr, i, j) => {
        let temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    const maxHeapIfy = (arr, i, len) => {
        let left = (i << 1) + 1;
        let right = (i << 1) + 2;
        let maxIndex = i;
        if (left < len && arr[left] > arr[maxIndex]) {
            maxIndex = left;
        }
        if (right < len && arr[right] > arr[maxIndex]) {
            maxIndex = right;
        }
        if (i != maxIndex) {
            //需要交换 继续调整堆
            swap(arr, i, maxIndex);
            maxHeapIfy(arr, maxIndex, len);
        }
    }

    const keepHeap = (arr, k) => {
        for (let i = arr.length >> 1; i >= 0; i--) {
            maxHeapIfy(arr, i, k);
        }
    }

    let top = arr.slice(0, k);
    keepHeap(top, k);
    for (let i = k; i < arr.length; i++) {
        if (arr[i] < top[0]) {
            top[0] = arr[i];
            keepHeap(top, k);
        }
    }
    return top;
};
```