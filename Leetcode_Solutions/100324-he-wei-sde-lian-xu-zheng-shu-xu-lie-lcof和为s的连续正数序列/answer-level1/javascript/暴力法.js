### 解题思路
暴力法

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
const getSequence = (arr, target, start) => {
    const temp = [];
    let currentTarget = target;
    for (let i = start; i < target; ++i) {
        temp.push(i);
        if (i === currentTarget) {
            arr.push(temp);
            return;
        }
        if (i > currentTarget) {
            return;
        }
        currentTarget -= i;
    }
}

var findContinuousSequence = function(target) {
    const result = [];
    for (let i = 1; i < target/2; ++i) {
        getSequence(result, target, i);
    }
    return result;
};
```

### 复杂度
- 时间复杂度 O(N*sqrt(N))
- 空间复杂度 O(1)