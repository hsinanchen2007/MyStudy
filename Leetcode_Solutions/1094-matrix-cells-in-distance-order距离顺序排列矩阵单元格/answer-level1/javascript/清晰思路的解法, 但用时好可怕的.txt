### 解题思路
![image.png](https://pic.leetcode-cn.com/4228afde3c9f2bdf9d97475dfe640fd4db06f78d6ecec794f04762a941fff696-image.png)


```js
// 如: let R = 2, C = 2, r0 = 0, c0 = 1

//先循环获取所有坐标值 同时计算 曼哈顿距离, 把该距离与坐标值放入同一数组

arr = [[0,0,1],[0,1,0],[1,0,2],[1,1,1]]

// 再使用sort排序

arr = [[0,1,0],[0,0,1],[1,1,1],[1,0,2]]

// 再去掉arr每项的距离值

arr = [[0,1],[0,0],[1,1],[1,0]]

```


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
  return arr.map(t => {
      t.length = 2
      return t
    }
  )
};
```