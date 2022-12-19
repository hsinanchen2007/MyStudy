### 解题思路
性能提升到前百分之九十
![image.png](https://pic.leetcode-cn.com/04dbf46288d93aa663ab5a10db34d3984b7e528d2bb0a1b69e5e35fdbe7931ba-image.png)

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
        if(num==target) return true;
        if(num<target){
            var numlength = matrix[i].length;
            for (var j=0;j<numlength;j++) {
                if(matrix[i][j]==target) return true;
                if(matrix[i][j]>target) return false;								
            }
        }			
    }	
    return false;	
};
```