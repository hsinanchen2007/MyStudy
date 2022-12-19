### 解题思路
桶排序，复杂度O(M+N)
![image.png](https://pic.leetcode-cn.com/81a6f4b02fda023a18804ceaa5274e13f7b4c359c0c424bb32f9c8158d12cd06-image.png)


### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    if(matrix.length==0) return false;
    var i=0,j;
    j=matrix[0].length-1;
    var rowlen = matrix.length;
    var celilen = matrix[0].length;
    while(i<rowlen&&j<celilen){
        var num = matrix[i][j];
        if(num==target) return true;
        if(num>target){
            j--;
        }else{
            i++
        }
    }
    return false;
};
```