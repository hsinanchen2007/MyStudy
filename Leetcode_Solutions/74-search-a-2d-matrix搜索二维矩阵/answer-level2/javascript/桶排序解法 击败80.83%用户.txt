### 解题思路
方法一：这个二维数组是典型的升序数组自然可以，因此可以跟每一行的首元素比大小来优先获取目标元素可能属于哪一行，之后再此行中遍历寻找是否包含此目标元素，而在目标行中，一旦遇到比目标数大的元素立刻返回false，遇到了目标元素则返回true，但是还需要考虑一种情况，就是在遍历每一行的第一个元素的时候，如果出现了与目标数相等的元素，则一样返回true。
![image.png](https://pic.leetcode-cn.com/516061a8c8d5776a13005421ef11560d7e37e6b3f58429aa02359dde9b5dd692-image.png)

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    var length = matrix.length;
    for(var i=matrix.length-1;i>=0;i--){
        var num = matrix[i][0];
        if(num<target){
            var numlength = matrix[i].length;
            for (var j=0;j<numlength;j++) {
                if(matrix[i][j]==target){
                    return true;
                }
            }
            return false;
        }else if(num==target){
            return true;
        }				
    }	
    return false;	
};
```