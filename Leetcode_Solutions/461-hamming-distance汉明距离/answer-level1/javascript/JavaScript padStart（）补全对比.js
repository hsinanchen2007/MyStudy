### 解题思路
![image.png](https://pic.leetcode-cn.com/02bcef3b4d3a686fb34493f6bc4abd89dc6dadc0fc655ec101ae824f07c11848-image.png)

- 通过 padStart()，用 0 补全到 32 位
- 然后对比差异

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    let arrA = x.toString(2).padStart(32,0).split('')
    let arrB = y.toString(2).padStart(32,0).split('')
    let sum = 0
    for(let i = arrA.length - 1 ; i >= 0; i--){
        if(arrA[i] != arrB[i]){
            sum++
        }
    }
    return sum
};
```