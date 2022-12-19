思路一：循环遍历每一种可能的面积，取最大值即可，时间复杂度：**O(n^2)**。
```
var maxArea = function(height) {
    let area = 0;
    for (let i = 0; i < height.length; i++) {
        for (let j = i + 1; j < height.length; j++) {
            let temp = (j - i) * Math.min(height[i], height[j]);
            area = Math.max(area, temp);
        }
    }
    return area;
};
```
思路二：从最左边和最右边开始计算面积，哪边高度小，就往中间进一步，比较面积大小，时间复杂度：**O(n)**。
```
var maxArea = function(height) {
    let area = 0;
    let i = 0;
    let j = height.length - 1;
    while (i < j) {
        let temp = (j - i) * Math.min(height[i], height[j]);
        area = Math.max(temp, area);
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return area;
};
```
思路二的优化方法：
```
var maxArea = function(height) {
    let area = 0;
    let i = 0;
    let j = height.length - 1;
    while (i < j) {
        let temp = (j - i) * Math.min(height[i], height[j]);
        area = Math.max(temp, area);
        if (height[i] < height[j]) {
            // 这里判断一下后一个高度，如果比前一个高度还小，直接跳过，直到找到比当前高度大的高度
            while (i < j && height[i+1] < height[i]) i++;
            i++;
        } else {
            // 同理，判断一下前一个高度，如果比前一个高度还小，直接跳过，直到找到比当前高度大的高度
            while (i < j && height[j-1] < height[j]) j--;
            j--;
        }
    }
    return area;
};
```


