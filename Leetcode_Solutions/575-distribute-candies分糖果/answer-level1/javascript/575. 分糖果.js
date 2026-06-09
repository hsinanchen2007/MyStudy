### 解题思路

由题可知：$nums.length$ 为偶数，令糖果种类为 $category$，那么容易知道：

$y=\begin{cases}
category,\quad category\leq nums.length / 2\\
nums.length / 2, \quad category > nums.length / 2
\end{cases}$

### 代码

```javascript
/**
 * @param {number[]} candies
 * @return {number}
 */
var distributeCandies = function(candies) {
    let len = candies.length
    let map = new Map()
    // 遍历一次，
    candies.forEach((candy, index) => {
        let val = map.get(candy)
        if (!map.has(candy)) {
            map.set(candy, true)
        }
    })
    // 获取种类数
    let category = map.size
    // 超过一半直接返回数组的一半长度
    if (category > len / 2) {
        return len / 2
    }
    // 否则直接取种类数
    return category
};
```

- 时间复杂度：$O(n)$
- 空间复杂度：$O(n)$