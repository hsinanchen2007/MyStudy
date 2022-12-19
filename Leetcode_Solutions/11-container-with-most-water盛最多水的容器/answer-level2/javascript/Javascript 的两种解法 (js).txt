看到题目第一反应是用两个`for`循环，计算每一种组合的长度并记录最大值:

```JavaScript
var maxArea = function(height) {
    max = 0;
    for (let i = 0; i < height.length; i++) {
        for (j = i + 1; j < height.length; j++) {
            max = Math.max(max, (j - i) * Math.min(height[i], height[j]))
        }
    }
    return max;
};
```

上述方法耗时较长，经过一番思考后探索到双指针法。从左右两边开始计算面积，应用较高的线来寻找较长的范围，从而获得较大的面积。因此当左值较小时，左指针增加，右值较小时，右指针减小。

```JavaScript
var maxArea = function(height) {
    let left = 0, right = height.length - 1, max = 0;
    while (left < right) {
        let tmp = (right - left) * Math.min(height[left], height[right]);
        if (tmp > max) {
            max = tmp;
        }
        if (height[left] <= height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max;
};
```