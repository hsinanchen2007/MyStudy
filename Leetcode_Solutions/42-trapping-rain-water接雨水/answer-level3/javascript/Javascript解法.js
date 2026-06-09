首先先感谢题解区的某位C++大佬，果然数学学得好看问题的角度就是不同.....
```
var trap = function(height) {
    if (height.length == 0) {
        return 0
    }
    let result = 0, maxHeight_y = 0, maxHeight_x = 0
    for (let i = 0; i < height.length; i++) {
        if (height[i] > maxHeight_y) {
            maxHeight_y = height[i]
            maxHeight_x = i
        }
    }
    let maxLeft = -1
    for (let i = 0; i < maxHeight_x; i++) {
        if (maxLeft == -1 & height[i] == 0) {
            continue
        }
        if (height[i] < maxLeft) {
            result += maxLeft - height[i]
        }
        if (height[i] >= maxLeft) {
            maxLeft = height[i]
        }
    }
    let maxRight = -1
    for (let i = height.length - 1; i > maxHeight_x; i--) {
        if (maxRight == -1 & height[i] == 0) {
            continue
        }
        if (height[i] < maxRight) {
            result += maxRight - height[i]
        }
        if (height[i] >= maxRight) {
            maxRight = height[i]
        }
    }
    return result;
};
```

思路，先获取数组的最大值，然后从左边和右边对到这个值进行遍历，以左边为例，先取第一个不为0的为最大值，如果遇到的值比这个值小，就加上他们之间的差值，如果比它大，就替换最大值。
