### 解题思路

1，浮点数二分查找，先找到满足条件的的浮点值d，使得小于d的分数个数为k个
2，找到p和q使得p/q小于d且与d最接近就是答案

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number[]}
 */
var kthSmallestPrimeFraction = function(A, K) {
    const { length } = A;
    let left = A[0] / A[length - 1], right = 1, mid;
    let getCurrentMidCount = function(A, target) {
        let cnt = 0, p = 0, q = 1;
        for (let i = 0, j = i + 1; i < length; i++) {
            while (j < length && A[i] > target * A[j]) {
                ++j;
            }
            //以A[i]为分子，比target小的分数个数
            cnt += length - j;
            // 找出最近的值
            if (j < length && p * A[j] < q * A[i]) {
                p = A[i];
                q = A[j];
            }
        }
        return [cnt, p, q];
    }
    while (left < right) {
        mid = (right + left) / 2;
        [count, p, q] = getCurrentMidCount(A, mid);
        if (count === K) {
            return [p, q];
        } else if (count < K) {
            left = mid;
        } else {
            right = mid;
        }
    }
};
```

![屏幕快照 2020-01-09 上午9.25.20.png](https://pic.leetcode-cn.com/2dbfdc878a91051175123ef32047f4757a52a4dd7d1c6c712a3140859fac6eb5-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-09%20%E4%B8%8A%E5%8D%889.25.20.png)
