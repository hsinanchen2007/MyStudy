# 分析：
为了得到最大值，应将尽可能多的负数转化为正数，（数组按从小到大排序），所以可以分为以下三种情况：
- 负数的个数大于K，则只需将数组前K个负数转为正数，然后计算数组总和
- 负数的个数小于K且K减去负数个数后为偶数，则需要将所有负数转为正数，然后计算数组总和，因为剩下的偶数次反转可以不改变值
- 负数的个数小于K且K减去负数个数后为奇数，则需要将所有负数转为正数，然后重新将数组按从小到大排序，并将最小值反转，然后计算数组总和
# 代码：
```
var largestSumAfterKNegations = function(A, K) {
    A.sort((a, b) => a - b);
    let sum = 0;
    let index = 0;
    for (let i = 0; i < A.length; i++) {
        if (A[i] < 0) {
            if (i < K) {
                A[i] = -A[i];
            }
            index++;
        } else {
            break;
        }
    }
    if (index >= K || ((K - index) & 1) === 0) {
        return A.reduce(function(prev, cur) {
            return prev + cur;
        })
    } else {
        A.sort((a, b) => a - b);
        for (let i = 0; i < A.length; i++) {
            if (i === 0) {
                sum += -A[i];
            } else {
                sum += A[i];
            }
        }
        return sum;
    }
};
```
