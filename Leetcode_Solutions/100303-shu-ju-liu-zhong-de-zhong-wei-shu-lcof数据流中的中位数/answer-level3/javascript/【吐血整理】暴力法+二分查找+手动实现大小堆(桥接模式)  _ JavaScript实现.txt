
## 解法 1:暴力法

每次取出中位数的时候，都先将所有元素进行排序，然后再计算中位数。代码如下：

```javascript
// 原文地址：https://xxoo521.com/2020-02-27-find-median-from-data-stream/

var MedianFinder = function() {
    this.data = [];
};

MedianFinder.prototype.addNum = function(num) {
    this.data.push(num);
};

MedianFinder.prototype.findMedian = function() {
    const length = this.data.length;
    if (!length) {
        return null;
    }
    this.data.sort((a, b) => a - b);

    const mid = Math.floor((length - 1) / 2);
    if (length % 2) {
        return this.data[mid];
    }
    return (this.data[mid] + this.data[mid + 1]) / 2;
};
```

也可以在添加元素的时候直接排序。时间复杂度一样，均是$O(NlogN)$，**无法 ac**。

## 解法 2: 二分查找

其实不需要每次添加元素的时候，都对全部元素重新排序。如果之前一直保证元素是有序的，那么添加新元素的时候，只需要将元素插入到正确位置即可，查找正确位置可以通过「二分搜索」来完成。

为了保证之前的元素有序，针对每个新添加的元素都将其放入正确位置。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/find-median-from-data-stream/
// 原文地址：https://xxoo521.com/2020-02-27-find-median-from-data-stream/

var MedianFinder = function() {
    this.data = [];
};

MedianFinder.prototype.addNum = function(num) {
    if (!this.data.length) {
        this.data.push(num);
        return;
    }

    let left = 0,
        right = this.data.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (this.data[mid] === num) {
            this.data.splice(mid, 0, num);
            return;
        } else if (this.data[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    this.data.splice(right + 1, 0, num);
};

MedianFinder.prototype.findMedian = function() {
    const length = this.data.length;
    if (!length) {
        return null;
    }

    const mid = Math.floor((length - 1) / 2);
    if (length % 2) {
        return this.data[mid];
    }
    return (this.data[mid] + this.data[mid + 1]) / 2;
};
```

二分查找需要$O(logN)$的复杂度，移动元素需要$O(N)$复杂度，所以时间复杂度是$O(N)$。

## 解法 3: 最大堆 + 最小堆

对于这种动态数据，堆是极好的解决方案。准备两个堆：

-   最大堆：存放数据流中较小的一半元素
-   最小堆：存放数据流中较大的一半元素

需要保证这 2 个堆的“平衡”。这里的平衡指得是：最大堆的大小 = 最小堆的大小， 或者 最大堆的大小 = 最小堆的大小 + 1。

当调用 findMedian 查询中位数的时候，中位数就是最大堆的堆顶元素，或者 (最大堆的堆顶元素 + 最小堆的堆顶元素)/2

剩下的问题就是怎么保证堆的平衡？步骤如下：

-   先让 num 入 maxHeap
-   取出 maxHeap 的堆顶元素，放入 minHeap
-   若此时`最大堆的大小 < 最小堆的大小`，取出 minHeap 的堆顶元素，让入 maxHeap

由于 JavaScript 中没有堆，所以要自己实现。**在实现的时候，堆的代码其实只需要一份，堆中进行判定的比较函数由外界传入即可**。这是一种名为「桥接模式」的设计模式，具体可以看这篇文章：[《设计模式 - 桥接模式 - JavaScript》](https://xxoo521.com/2019-01-19-bridge-pattern/)

```javascript
// ac地址：https://leetcode-cn.com/problems/find-median-from-data-stream/
// 原文地址：https://xxoo521.com/2020-02-27-find-median-from-data-stream/

const defaultCmp = (x, y) => x > y; // 默认是最大堆

const swap = (arr, i, j) => ([arr[i], arr[j]] = [arr[j], arr[i]]);

class Heap {
    /**
     * 默认是最大堆
     * @param {Function} cmp
     */
    constructor(cmp = defaultCmp) {
        this.container = [];
        this.cmp = cmp;
    }

    insert(data) {
        const { container, cmp } = this;

        container.push(data);
        let index = container.length - 1;
        while (index) {
            let parent = Math.floor((index - 1) / 2);
            if (!cmp(container[index], container[parent])) {
                return;
            }
            swap(container, index, parent);
            index = parent;
        }
    }

    extract() {
        const { container, cmp } = this;
        if (!container.length) {
            return null;
        }

        swap(container, 0, container.length - 1);
        const res = container.pop();
        const length = container.length;
        let index = 0,
            exchange = index * 2 + 1;

        while (exchange < length) {
            // // 以最大堆的情况来说：如果有右节点，并且右节点的值大于左节点的值
            let right = index * 2 + 2;
            if (right < length && cmp(container[right], container[exchange])) {
                exchange = right;
            }
            if (!cmp(container[exchange], container[index])) {
                break;
            }
            swap(container, exchange, index);
            index = exchange;
            exchange = index * 2 + 1;
        }

        return res;
    }

    top() {
        if (this.container.length) return this.container[0];
        return null;
    }
}
```

整体的代码逻辑如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/find-median-from-data-stream/
// 原文地址：https://xxoo521.com/2020-02-27-find-median-from-data-stream/

var MedianFinder = function() {
    this.maxHeap = new Heap();
    this.minHeap = new Heap((x, y) => x < y);
};

MedianFinder.prototype.addNum = function(num) {
    this.maxHeap.insert(num);
    this.minHeap.insert(this.maxHeap.top());
    this.maxHeap.extract();

    if (this.maxHeap.container.length < this.minHeap.container.length) {
        this.maxHeap.insert(this.minHeap.top());
        this.minHeap.extract();
    }
};

MedianFinder.prototype.findMedian = function() {
    return this.maxHeap.container.length > this.minHeap.container.length
        ? this.maxHeap.top()
        : (this.maxHeap.top() + this.minHeap.top()) / 2;
};
```

时间复杂度是$O(logN)$，空间复杂度是$O(N)$。

## 更多资料

**若有错误，欢迎指正。若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer + Leetcode 题解](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
