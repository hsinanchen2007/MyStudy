### 解题思路
第一次循环找出最多出现元素出现的次数，例如[1, 2, 3, 2, 1] 求出size = 2;
第二次循环，当某个数出现的次数 = size，取当前索引减去数字初始位置(indexOf) + 1

### 代码

```javascript
var findShortestSubArray = function(nums) {
    // 先找到出现最多次数的元素次数
    let map = new Map(), size = 1, distance = nums.length;

    for (let n of nums) {
        map.set(n, map.has(n) ? map.get(n) + 1 : 1);
        size = Math.max(size, map.get(n));
    }

    let h = new Map();

    for (let i = 0; i < nums.length; i++) {
        let cur = nums[i];

        h.set(cur, h.has(cur) ? h.get(cur) + 1 : 1);
        if (h.get(cur) == size) {
            let start = nums.indexOf(cur);
            distance = Math.min(distance, i - start + 1);
        }
    }
    return distance;
};
```