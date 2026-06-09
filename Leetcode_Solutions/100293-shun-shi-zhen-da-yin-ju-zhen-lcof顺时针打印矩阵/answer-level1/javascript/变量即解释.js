### 解题思路
按照向右、下、左、上顺时针旋转

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
  if (!matrix.length) return [];
  const res = [];
  let left = 0;
  let right = matrix[ 0 ].length - 1;
  let top = 0;
  let bottom = matrix.length - 1;
  let direction = 'toRight';
  while(left <= right && top <= bottom) {
    switch(direction) {
      case 'toRight': {
        for (let i = left; i <= right; i++) res.push(matrix[ top ][ i ]);
        top++;
        direction = 'toBottom';
      }; break;
      case 'toBottom': {
        for (let i = top; i <= bottom; i++) res.push(matrix[ i ][ right ]);
        right--;
        direction = 'toLeft';
      }; break;
      case 'toLeft': {
        for (let i = right; i >= left; i--) res.push(matrix[ bottom ][ i ]);
        bottom--;
        direction = 'toTop';
      }
      case 'toTop': {
        for (let i = bottom; i >= top; i--) res.push(matrix[ i ][ left ]);
        left++;
        direction = 'toRight';
      }
    }
  }
  return res;
};
```