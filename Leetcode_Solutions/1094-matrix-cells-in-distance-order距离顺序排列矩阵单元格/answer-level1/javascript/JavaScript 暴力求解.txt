### 解题思路
![image.png](https://pic.leetcode-cn.com/6485ce8443e18d025767b2ce15ffd4f38bc5b2d5ed2985ece96e495051a6b65a-image.png)

- 存一下思路
### 代码

```javascript
/**
 * @param {number} R
 * @param {number} C
 * @param {number} r0
 * @param {number} c0
 * @return {number[][]}
 */
var allCellsDistOrder = function(R, C, r0, c0) {
  let arr = []
  for(let i = 0; i < R; i++){
    for(let j = 0; j < C; j++){
      let a = Math.abs(i - r0) + Math.abs(j - c0)
      arr.push([i,j,a])
    }
  }
  arr.sort((a,b) => a[2] - b[2])
  return arr.map(item => {
      item.splice(2,1)
      return item
    }
  )
};

```