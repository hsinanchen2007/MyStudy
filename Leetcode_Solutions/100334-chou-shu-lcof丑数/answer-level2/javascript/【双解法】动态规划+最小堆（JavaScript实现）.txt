
## 解法 1: 动态规划

因为丑数只包含质因数 2, 3, 5，所以对于下个丑数来说，一定是前面某个丑数乘 3、乘 4 或者乘 5 所得。

准备三个指针 ptr2、ptr3、ptr5，它们指向的数只能乘 2、3 和 5。在循环过程中，每次选取 `2 * res[ptr2]`、`3 * res[ptr3]` 和 `5 * res[ptr5]`这三个数中结果最小的数，并且将对应的指针向前移动。有效循环是 n 次，当循环结束后，res 数组中就按从小到大的顺序保存了丑数。

代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/ugly-number-ii/
// 原文地址：https://xxoo521.com/2020-03-10-ugly-number-ii/
/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    const res = new Array(n);
    res[0] = 1;

    let ptr2 = 0, // 下个数字永远 * 2
        ptr3 = 0, // 下个数字永远 * 3
        ptr5 = 0; // 下个数字永远 * 5

    for (let i = 1; i < n; ++i) {
        res[i] = Math.min(res[ptr2] * 2, res[ptr3] * 3, res[ptr5] * 5);
        // 说明前ptr2个丑数*2也不可能产生比i更大的丑数了
        // 所以移动ptr2
        if (res[i] === res[ptr2] * 2) {
            ++ptr2;
        }
        if (res[i] === res[ptr3] * 3) {
            ++ptr3;
        }
        if (res[i] === res[ptr5] * 5) {
            ++ptr5;
        }
    }

    return res[n - 1];
};
```

时间复杂度是$O(N)$，空间复杂度是$O(N)$。

## 解法 2: 最小堆

借助最小堆，可以在 $O(LogN)$ 时间复杂度内找到当前最小的元素。整体算法流程是：

-   准备最小堆 heap。准备 map，用于记录丑数是否出现过。
-   将 1 放入堆中
-   从 0 开始，遍历 n 次：
    -   取出堆顶元素，放入数组 res 中
    -   用堆顶元素依此乘以 2、3、5
    -   检查结果是否出现过。若没有出现过，那么放入堆中，更新 map
-   返回 res 最后一个数字

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/ugly-number-ii/
// 原文地址：https://xxoo521.com/2020-03-10-ugly-number-ii/

const defaultCmp = (x, y) => x > y;
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
            // 如果有右节点，并且右节点的值大于左节点的值
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

/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    const heap = new Heap((x, y) => x < y);
    const res = new Array(n);
    const map = {};
    const primes = [2, 3, 5];

    heap.insert(1);
    map[1] = true;
    for (let i = 0; i < n; ++i) {
        res[i] = heap.extract();

        for (const prime of primes) {
            let tmp = res[i] * prime;
            if (!map[tmp]) {
                heap.insert(tmp);
                map[tmp] = true;
            }
        }
    }
    return res[n - 1];
};
```

时间复杂度是$O(NlogN)$, 空间复杂度是$O(N)$。

## 更多资料

**整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
