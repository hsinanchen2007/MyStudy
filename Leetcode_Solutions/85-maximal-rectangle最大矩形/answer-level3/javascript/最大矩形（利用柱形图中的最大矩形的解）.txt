### 解题思路
![image.png](https://pic.leetcode-cn.com/977dc1beb943f27a3b7bd9c1850ad63c52d9ea6f9f9e4e3a68fd058b509571bb-image.png)  

柱形高度计算，优化了思路。利用了上一次的高度，而不是每次遍历，速度提升40ms

![image.png](https://pic.leetcode-cn.com/bc4472cdfb014ec24fbedf1093cf177f0aaa953cf90b0dbb6f0886d79e529d31-image.png)

看代码注释，
### 代码

```javascript
/**
 * @param {character[][]} matrix
 * @return {number}
 */
// 柱形图中的最大矩形的解：栈顶法
var largestRectangleArea = function(heights) {
    let large = 0;
    let shift = [{ index: -1, height: -1 }];
    for(let i = 0; i < heights.length; i++) {
       while(shift[shift.length - 1].height !== -1 && shift[shift.length - 1].height > heights[i]) {
           const pop = shift.pop();
           large = Math.max(large, pop.height * (i - 1 - shift[shift.length - 1].index) );
       }
       shift.push({ index: i,height: heights[i] });
    }
    const top = shift[shift.length - 1].index;
    while(shift[shift.length - 1].height !== -1) {
        const pop = shift.pop();
        large = Math.max(large, pop.height * (top - shift[shift.length - 1].index));
    }
    return large
};
// 转化思路，将矩阵构建成柱形图，就可以用柱形图中的最大矩形来求解；
// 两步：
// 构造柱形图：
// 一层，两层，三层，....n层这样叠加；
// 以右边示例为例：
// 一层： [1,0,1,0,0]，最大面积为1
// 二层： [2,0,2,1,1]，最大面积为3
// 三层： [3,1,3,2,2]，最大面积为6
// 四层： [4,0,0,3,0]，最大面积为1
// 这里可以做一个优化，就是不用每次都每一列循环遍历来求高度而是可以利用上一层的高度了来累加
var maximalRectangle = function(matrix) {
    if(!matrix.length) {
        return 0;
    }
    // [1,0,1,0,0]，最大面积为1
    let heights = matrix[0].map(item => +item)
    let large = largestRectangleArea(heights);
    for (let i = 1; i < matrix.length; i++ ) {
        const axis = matrix[i];
        for (let j = 0;j < axis.length; j++) {
/*             let height = 0;
            let k = i;
            while(k >= 0 && matrix[k][j] > 0) {
                k--;
                height++;
            }
            heights.push(height); */
            if(matrix[i][j] > 0) {
                heights[j] = heights[j] + 1;
            } else {
                heights[j] = 0;
            }
        }
        large = Math.max(large, largestRectangleArea(heights));
    }
    return large;
};
```