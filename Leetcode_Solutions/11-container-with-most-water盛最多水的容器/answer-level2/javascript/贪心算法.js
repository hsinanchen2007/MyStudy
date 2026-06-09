
贪心，最大面积取决于左右两根柱子最小的高度，和两根柱子的距离
思路：
- 把一根柱子替换成另一根柱子要保证被替换的是小的那根 
- `area = [left-right]*min(leftHeight,rightHeight); `

- `area1 = [(left+1)-right]*min(height(left+1),height(right)) = [(left-right+1)]*min(height(left+1),height(right))`

- `area2 = [left-(right-1)]*min(height(left),height(right-1)) = [(left-right+1)]*min(height(left),height(right-1))`
- 若要每次都保证移动一根柱子的面积最大可以看出不取决于横坐标的移动，而是取决于被替换的柱子的高度那个更低
- 因此如果height(left+1)<height(right-1)则移动左边的柱子left+1,否则移动右侧柱子right-1;
### 代码
```js
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    if(height.length === 2){
        return Math.min.apply(null,height);
    }
    // 贪心，最大面积取决于左右两根柱子最小的高度，和两根柱子的距离
    // 把一根柱子替换成另一根柱子要保证被替换的是小的那根
    // 两根柱子从远往近，同样高度的柱子肯定是越远面积越大
    var maxAreaValue = 0,
        left = 0,
        right = height.length - 1;
    while(left<right){
        maxAreaValue = Math.max(maxAreaValue,Math.abs(Math.min(height[left],height[right])*(left-right)));
        if(height[left]<height[right]){
            left++;
        }else{
            right--;
        }
    }
    return maxAreaValue;
};
```