### 解题思路
第一种：一行代码解决
第二种：暴力循环
第三种：通过判断右上角（左下角也可以）的值对数组进行缩小，直到找到对应的值
![image.png](https://pic.leetcode-cn.com/a9db01d3e75effb5c818aa8a2c222e5c9ad9de6d396841995fa6b8a74f1bc1c5-image.png)

### 代码
```javascript
var findNumberIn2DArray = function(matrix, target) {
    //使用es6语法一行就可以解决，但是leetcode不支持
    return matrix.flat().includes(target)
};
```

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    for(let arr of matrix){
        if(arr.includes(target)){
            return true
        }
    }
    return false
};
```

```javascript
var findNumberIn2DArray = function(matrix, target) {
    //获取矩阵右上角的值
    function get(arr){
        return arr[0][arr[0].length-1]
    }
    while(matrix.length !== 0){ //只要矩阵中还有内容就继续循环
        if(get(matrix) !== target){
            if(get(matrix) > target){ //右上角值大于target
                //删除该列
                for(let arr of matrix){
                    arr.pop()
                }
            }else{ //右上角值小于target
                //删除该行
                matrix.shift()
            }
        }else{
            return true
        }
    }
    return false
};
```