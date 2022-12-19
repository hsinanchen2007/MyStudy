### 解题思路
![image.png](https://pic.leetcode-cn.com/c231bff66c070398508968262eed433c68c1e8d0bba236e1e680f299395c4122-image.png)

没啥说的，map大法，为了凑每天三题的积分而刷。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    if (!nums.length) return false;
    if (k === 0) return false;

    let m = new Map(),
        dist = Number.MAX_SAFE_INTEGER;
    nums.forEach((val, idx) => {
        if (!m.has(val)) {
            m.set(val, [idx]);
        } else {
            let idxArr = m.get(val);
            idxArr.push(idx);
            m.set(val, idxArr);
        }
    });

    for (let val of m.values()) {
        for (let i = 0; i < val.length - 1; i++) {
            dist = Math.min(dist, val[i + 1] - val[i]);
            if (dist <= k) return true;
        }
    }
    return false;
};
```