### 解题思路
取一点做初始值，然后计算出这一点的去处坐标，然后赋值过去，记得保存去处坐标的值。
然后再计算出上面这个去处坐标的去处，因为是转，所以循环4次就可以了。

下面的问题是要找出那些坐标作初始值。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    var len = matrix.length;
    var r = parseInt(len / 2);
    var i = 0;
    var j = 0;
    var ti = 0;
    var tj = 0;
    var temp1 = matrix[ti][tj];
    var temp2 = temp1;
    for(var k = 0; k < r; k++) {
        for(var l = k; l < len - 1 - k; l++) {
            var c = 4;
            ti = i = k;
            tj = j = l;
            temp1 = matrix[ti][tj];
            temp2 = temp1;
            while(c > 0) {
                ti = j;
                tj = len - 1 - i;
                temp2 = matrix[ti][tj];
                matrix[ti][tj] = temp1;
                temp1 = temp2;
                i = ti;
                j = tj;
                c--;
            }
        }
    }
};
```