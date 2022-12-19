### 解题思路
设第一条线的下标为数组中的`l`, 第二条线为`r`;

理解容器的面积实际就是`(r - l) * Math.min(height[l], height[r])`的最大值.

**解法一**

暴力破解法(不推荐)

利用两个`for`循环遍历出所有的情况, 并进行比较出最大值;

**解法二**

双指针法:

设置双指针`l`和`r`分别位于容器的一头一尾,根据规则移动指针, 并且更新面积最大值 `maxS`，直到 `l == r` 时返回 `maxS`。

1. 考虑输入的数组长度为`0, 1, 2`的情况;
2. 设置双指针`l`和`r`分别位于容器的一头一尾;
3. 使用`while`循环, 当`l == r`时结束循环;
4. 判断每次`height[l]`和`height[r]`的高度, 若是后者大,则指针`l`向前移动, 反之则移动`r`;
5. 其实本质就是在移动的过程中不断消去不可能成为最大值的状态.

### coding

**解法一**
```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    if (!height || height.length <= 1) return 0;
    const len = height.length;
    if (len === 2) return Math.min(height[0], height[1]);
    let maxS = 0;
    for (let i = 0; i < len; i++) {
        for (let j = i + 1; j < len; j++) {
            maxS = Math.max(maxS, (j - i) * Math.min(height[i], height[j]));
        }
    }
    return maxS;
};
```
执行用时**820ms**, 内存消耗**35.4MB**.

**解法二**
```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    if (!height || height.length <= 1) return 0;
    const len = height.length;
    if (len === 2) return Math.min(height[0], height[1]);
    let maxS = 0,
        l = 0,
        r = len - 1;
    while (l < r) {
        maxS = height[l] < height[r] ? 
            Math.max(maxS, (r - l) * height[l++]) :
            Math.max(maxS, (r - l) * height[r--]);
    }
    return maxS;
};
```
执行用时**76ms**, 内存消耗**35.4MB**.