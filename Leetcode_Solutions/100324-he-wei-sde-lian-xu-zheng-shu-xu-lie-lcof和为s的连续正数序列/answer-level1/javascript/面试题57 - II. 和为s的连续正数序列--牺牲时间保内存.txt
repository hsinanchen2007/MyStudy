### 执行结果
![image.png](https://pic.leetcode-cn.com/d68f55dabdf2226c2f9e5d90c43a55946f7c7cbe584fcd1d0f147e24d93c1de1-image.png)

### 解题思路
1. 当索引 i 大于 target 一半的时候，就不用继续执行了，因为 i + i + 1 肯定大于 target 了。
2. 利用等差数列求和公式求出 end 值，即 (首项+末项)*项数/2, 解出末项的值即为： `end = Math.sqrt(2*target + i**2 - i + 0.25) - 0.5`
3. 利用 Array.from 创建一个从 i 到 end 的数组，并放入 result 数组

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    if (target === 1 || target === 2)  return []
    let tmp = []
    let result = []
    let half = Math.ceil(target/2)
    let end = 0
    for (let i = 1; i < half; i++) {
        end = Math.sqrt(2*target + i**2 - i + 0.25) - 0.5
        if (parseInt(end) === end) {
            tmp = Array.from({ length: (end - i + 1)}, (item, index) => (index + i))
            result.push([...tmp])
        }
    }
    return result
};
```