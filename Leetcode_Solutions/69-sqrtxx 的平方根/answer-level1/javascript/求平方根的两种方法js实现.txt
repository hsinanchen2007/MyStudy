### 解题思路

1. 二分查找法，记好这个套路即可
2. 牛顿迭代法，通过一个公式不断迭代逼近终点，看图：
![image.png](https://pic.leetcode-cn.com/39f1b5dc386c8878c9b08107bab9bfc1ba120e4dca21ad490ed903ff06cd631d-image.png)

### 代码

```javascript
/* 二分查找法，这个比较好理解
var mySqrt = function(x) {
    let left = 0, right = x, mid, num, mid2
    while (right - left > 1e-9) {
        mid = (left + right) / 2
        mid2 = Math.round(mid)
        if (mid2 * mid2 === x) {
            return mid2
        }
        num = mid * mid
        if (num > x) {
            right = mid
        } else if (num < x) {
            left = mid
        } else {
            left = mid
            right = mid
            break
        }
    }

    return Math.floor(left)
};
*/

// 牛顿迭代法
function mySqrt (x) {
    if (x === 0 || x === 1) {
        return x
    }
    let r = x
    while (r * r - x > 0.1) {
        // 以下是逼近公式，别问我为啥，数学公式求出来的
        r = (r + x / r) / 2
    }
    let rr = Math.round(r)
    if (rr * rr === x) {
        return rr
    } else {
        return Math.floor(r)
    }
}
```