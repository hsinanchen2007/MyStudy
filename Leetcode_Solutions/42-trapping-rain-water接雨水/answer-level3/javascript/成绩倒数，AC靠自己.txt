### 解题思路
![image.png](https://pic.leetcode-cn.com/d3451fab269a537a8334488b0791cb8706052321186b1e25f3397a80ce6ae0fe-image.png)

遍历数组，每次朝两边遍历检查，若两侧有比自己高的，把当前点修改为“两边比自己高的，取其矮”，得到“积水后“的数组，再遍历一次，得到雨水量。

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function (height) {
    let leftH = 0,
        rightH = 0,
        heightCopy = height.slice(0),
        rain = 0;

    for (let i = 1; i < height.length - 1; i++) {
        leftH = 0;
        rightH = 0;
        for (let j = i - 1; j >= 0; j--) {
            if (height[j] > height[i]) leftH = Math.max(leftH, height[j])
        }
        for (let k = i + 1; k < height.length; k++) {
            if (height[k] > height[i]) rightH = Math.max(rightH, height[k]);
        }
        if (leftH > height[i] && rightH > height[i]) height[i] = leftH < rightH ? leftH : rightH;
    }

    for (let i = 0; i < height.length; i++) {
        rain += (height[i] - heightCopy[i]);
    }

    return rain;
};
```