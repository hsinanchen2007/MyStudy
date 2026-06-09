### 解题思路
用双指针分别指向数组的首尾。
面积 := 较短木板长度 * 容器宽度
当容器宽度缩小时，只有较短木板长度增加，面积才可能增加。
所以我们把 height 较小的指针向内移。


### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    if (!height.length) return 0;
    let max = 0, start = 0, end = height.length - 1;
    while (start < end) {
        const current = (Math.min(height[start], height[end])) * (end - start);
        if (current > max) {
            max = current;
        }
        if (height[start] > height[end]) {
            --end;
        } else {
            ++start;
        }
    }
    return max;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)