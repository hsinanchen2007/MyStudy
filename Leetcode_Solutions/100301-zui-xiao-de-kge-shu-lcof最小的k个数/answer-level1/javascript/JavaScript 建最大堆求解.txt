### 解题思路

用数组来构造最大堆

数组的第一个元素插入一个无穷大的值

如下的堆

```
      10
    /    \
    8     9
   / \   /  \
  7   6  4   5
```

按照层序遍历插入到数组中，则用数组表示的结果如下：

```JS
[Infinity,10,8,9,7,6,4,5]
```

这样的表示的话，一个结点的下标为i，则它的两个儿子的结点的下标分别为2i，2i+1。

一个结点它的父结点的下标为，parseInt(i/2)。

然后实现最大堆构造的方法，以及将最大堆的顶部替换的方法。

最后返回结果时将数组的首项删除。

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function (arr, k) {
    if (k === 0 || arr.length === 0) {
        return [];
    }
    let maxheap = [Infinity]; // 最大堆

    for (let i = 0; i < arr.length; i++) {
        let item = arr[i];
        if (maxheap.length - 1 < k) {
            // 构造最大堆
            insert(item, maxheap);
        } else {
            // 如果当前元素比最大堆的最大值小，则将堆的最大值替换成此元素，然后再重新构造成最大堆
            if (item < maxheap[1]) {
                addToTop(item, maxheap)
            }
        }
    }

    function insert(item, heap) {
        heap.push(item);
        let index = heap.length - 1;
        while (heap[index] > heap[parseInt(index / 2)]) {
            let temp = heap[index];
            heap[index] = heap[parseInt(index / 2)];
            heap[parseInt(index / 2)] = temp;
            index = parseInt(index / 2)
        }
    }

    function addToTop(item, heap) {
        heap[1] = item;
        let index = 1;
        while (true) {
            if (heap[2 * index] === undefined) {
                break;
            }
            if (heap[2 * index + 1] === undefined) {
                if (heap[2 * index] < heap[index]) {
                    break;
                }
                let temp = heap[2 * index];
                heap[2 * index] = heap[index];
                heap[index] = temp;
                index = 2 * index;
            } else {
                if (heap[2 * index] < heap[index] && heap[2 * index + 1] < heap[index]) {
                    break;
                };
                if (heap[2 * index] > heap[2 * index + 1]) {
                    let temp = heap[2 * index];
                    heap[2 * index] = heap[index];
                    heap[index] = temp;
                    index = 2 * index;
                } else {
                    let temp = heap[2 * index + 1];
                    heap[2 * index + 1] = heap[index];
                    heap[index] = temp;
                    index = 2 * index + 1;
                }
            }
        }
    }
    maxheap.shift();
    return maxheap
};
```