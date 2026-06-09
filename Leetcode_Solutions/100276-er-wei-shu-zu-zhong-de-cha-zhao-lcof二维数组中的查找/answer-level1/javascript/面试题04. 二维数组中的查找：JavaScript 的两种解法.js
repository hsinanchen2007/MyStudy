## 方法一：暴力遍历

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    for (let row = 0; row < matrix.length; row++) {
        for (let column = 0; column < matrix[0].length; column++) {
            if(matrix[row][column] === target) return true;
        }
    }
    return false;
};
```

**复杂度分析：**

- 时间复杂度：O(mn)。二维数组中的每个元素都被遍历，因此时间复杂度为二维数组的大小。
- 空间复杂度：O(1)


## 方法二：整行整列地排除选项

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    let row = matrix.length - 1;
    let col = 0;

    while(row >= 0 && col < matrix[0].length) {
        if(matrix[row][col] > target) {
            row -= 1;
        } else if(matrix[row][col] < target) {
            col += 1;
        } else {
            return true;
        }
    }

    return false;
};
```

**复杂度分析：**

- 时间复杂度：O(m + n)
- 空间复杂度：O(1)

---

**更多题解请关注**：[https://github.com/leviding/leetcode-js-leviding](https://github.com/leviding/leetcode-js-leviding)
