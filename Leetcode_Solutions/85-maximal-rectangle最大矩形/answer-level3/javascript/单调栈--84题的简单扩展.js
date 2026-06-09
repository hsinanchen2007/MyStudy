### 解题思路
假设矩阵中存在一个最大矩形，我们不妨将它底边一下的矩阵挡住，把“1”看作实心柱体，把“0”看作空心，跟84题就非常相似了。唯一不同的就是，我们这里还有一些悬空的柱子。不过没有关系，我们把它的高度记为0之后，并不会影响计算最大的面积。那么接下来就很思路清晰了：
+ 将矩阵的每一层单独拿出来，看作是一个84题的重复
+ 计算之前，我们先更新每一层的高度数组
+ 重复84题的计算

### 代码

```javascript
/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalRectangle = function(matrix) {
    let heights = [], max = 0;
    for (let i=0;i<matrix.length;i++) {
        if (heights.length == 0) {
            // init 
            // 前后补0，使代码更简洁
            for (let k=0;k<matrix[i].length+2;k++) {
                heights[k] = 0;
            }
        }
        let stack = [];
        for (let j=0;j<heights.length;j++) {
            // 同步更新每一个柱子的高度
            heights[j] = j>0&&j<=matrix[i].length&&'1'==matrix[i][j-1] ? heights[j]+1 : 0;
            // 计算每一个单调递增栈
            while (stack.length>0 && heights[j] < heights[stack[stack.length-1]]) {
                max = Math.max(max, heights[stack.pop()]*(j-stack[stack.length-1]-1));
            }
            stack.push(j);
        }
    }
    return max;
};
```