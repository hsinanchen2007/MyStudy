### 解题思路
时间复杂度：O(n),空间复杂度：O(n)。在此基础上可以改进成双指针，空间复杂度降为O(1)。

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function (height) {
    if (height.length < 3) return 0
    let count = 0,
        leftMax = [height[0]],
        rightMax = [];
    // 从左向右扫描，获取除两端之外的每个位子左侧的最高值
    for (let i = 1; i <= height.length - 2; i++) {
        leftMax[i] = Math.max(leftMax[i - 1], height[i - 1]);
    }
    rightMax[height.length - 1] = height[height.length - 1];
    // 从右向左扫描，获取除两端之外的每个位子右侧的最高值
    for (let i = height.length - 2; i >= 1; i--) {
        rightMax[i] = Math.max(rightMax[i + 1], height[i + 1]);
    }
    for (let i = 1; i <= height.length - 2; i++) {
        let increment = Math.min(leftMax[i], rightMax[i]) - height[i];
        count = increment > 0 ? count + increment : count;
    }
    return count
};
```