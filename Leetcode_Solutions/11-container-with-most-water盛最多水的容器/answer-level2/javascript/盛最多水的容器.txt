*法一：暴力双循环*

```js
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let max = 0
    for (let i = 0; i < height.length - 1; i++) {
        for (let j = i + 1; j < height.length; j++) {
            max = Math.max(max, Math.min(height[i], height[j]) * (j-i))
        }
    }
    return max
};
var height = [1,8,6,2,5,4,8,3,7]
console.log(maxArea(height));
```

*法二：双指针*

算法

这种方法背后的思路在于，两线段之间形成的区域总是会受到其中较短那条长度的限制。此外，两线段距离越远，得到的面积就越大。

我们在由线段长度构成的数组中使用两个指针，一个放在开始，一个置于末尾。 此外，我们会使用变量 maxareamaxarea 来持续存储到目前为止所获得的最大面积。 在每一步中，我们会找出指针所指向的两条线段形成的区域，更新 maxareamaxarea，并将指向较短线段的指针向较长线段那端移动一步。

```js
var maxArea2 = function(height) {
    let i = 0;
    let j = height.length-1;
    let max = Math.min(height[i],height[j]) * (j-i);
    while(i < j) {
        max = Math.max(max, Math.min(height[i], height[j]) * (j-i))
        if (height[i] < height[j]) {
            i++
        } else {
            j--
        }
        
    }
    return max
};
```

