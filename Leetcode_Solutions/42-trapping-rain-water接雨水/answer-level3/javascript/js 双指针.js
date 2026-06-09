### 解题思路
双指针
注意一点：
1. 如果后面的存在比当前柱子高的，那么就用那个高的柱子作为right, 把当前柱子的高度作为height，然后遍历 left -> right 挨个计算可以接的雨水。
2.  当后面的柱子都比left柱子低，那么就要在 left -> length-1之间找一个最高的柱子maxHeight，然后，从left+1 -> max开始遍历，挨个计算可以接的雨水。

时间复杂度，虽然看起来很像o(n^2)，但是所有被遍历过的，都会再下次跳过，所以时间复杂度还是O(n)。
但是空间复杂度是 O(1);
代码执行速度超过80%， 空间超过 93+%，

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let result = 0;
    for(let i = 0; i < height.length; i++){
        if(height[i] != 0){
            let leftHeight = height[i];
            let left = i;
            let right = left + 1;
            let maxHeight = 0;
            let max = right;
            while( right < height.length && height[right] < leftHeight) {
                if(height[right] >= maxHeight){
                    maxHeight = height[right];
                    max = right;
                }
                right++;
            }
            if(right == height.length){
                left++;
                while(left < max){
                    result += maxHeight - height[left];
                    left++;
                }
                i = max-1;
            }else{
                while(left < right){
                    result += leftHeight - height[left];
                    left++;
                }
                i = right-1;
            }
        }
    }
    return result;
};
```