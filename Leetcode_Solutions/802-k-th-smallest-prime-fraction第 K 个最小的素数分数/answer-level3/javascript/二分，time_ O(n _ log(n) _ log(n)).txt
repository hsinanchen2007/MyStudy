LeetCode中有几道相似的题，特点都是“**求第K个**”问题，都可以用`堆`或者`值域二分`来实现
- `373. Find K Pairs with Smallest Sums`
- `378. Kth Smallest Element in a Sorted Matrix`
- `668. Kth Smallest Number in Multiplication Table`
- `719. Find K-th Smallest Pair Distance`
- `786. K-th Smallest Prime Fraction`

这里主要讲解`二分`，因为堆实现本题优化空间不大，时间能达到`K * log(min(n, K))`，当K很大的时候效率就很低，因为`K`最大能取`n ^ 2`

- 整体思路：
  - 主体的二分：算法主体通过二分找到一个数，这个数是满足“小于等于该数的fraction有K个”的最小的数
    - 二分的check条件就是对于mid，统计小于等于mid的fraction个数
  - 二分实现找lowerBound：“统计小于等于某个数”也用二分来实现
    - 暴力解法是通过两层遍历平方级别实现，但是其实可以优化，思路就是对于每一行，找到满足条件的下标，然后通过下标直接计算这一行中“小于等于某个数”的个数。类似的优化思路在第668题中也有体现
    - 在这个过程中每次二分时也求出对应的p和q，并且不断找出最接近答案的值，当所有的二分完成时，我们就找到了最终的p和q


![image.png](https://pic.leetcode-cn.com/2f25c0de5bbdc4db9b97d6b760fae610a38cc233d277434fdd4836e8f8358c96-image.png)

js实现：
```js
var kthSmallestPrimeFraction = function(A, K) {
    const n = A.length;
    let l = A[0] / A[n - 1];
    let r = 1;
    const ans = [];
    while (l < r) {
        const mid = (l + r) / 2;
        const [count, p, q] = countLessEqual(A, mid);
        ans[0] = p; // 跟着二分一起更新答案，每次逼近最后的答案
        ans[1] = q;
        if (count > K) r = mid;
        else if (count < K) l = mid;
        else if (count === K) break;
    }

    function countLessEqual(A, target) {
        let count = 0;
        let minDiff = Infinity;
        let p = null;
        let q = null;
        for (let i = 0; i < n - 1; i++) {
            const index = findLowerBound(A, i, target);
            count += n - index;
            if (index !== n) { // 每次把最近的值算出来
                const diff = Math.abs(target - A[i] / A[index]);
                if (diff < minDiff) {
                    minDiff = diff;
                    p = A[i];
                    q = A[index];
                }
            }
        }
        return [count, p, q];
    }

    function findLowerBound(A, start, target) {
        let l = 0;
        let r = A.length - 1;
        while (l < r) {
            const mid = l + r >>> 1;
            if (A[start] / A[mid] <= target) r = mid;
            else l = mid + 1;
        }
        if (A[start] / A[l] <= target) return l;
        return n;
    }

    return ans;
};
```