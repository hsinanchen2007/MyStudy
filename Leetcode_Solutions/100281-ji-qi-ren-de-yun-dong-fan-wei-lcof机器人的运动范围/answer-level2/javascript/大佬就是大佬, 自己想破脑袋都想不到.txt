### 解题思路


```js
// 如 let m = 20, n = 15, k = 9, 满足不大于k时的图, 红色区域不满足, 来张图可能会更好理解
```
![image.png](https://pic.leetcode-cn.com/37e7da57849bdcd02e126ca54ca8a37f3b5a6d734a380b3facaf6ebe7085ba20-image.png)
```js
// 再加上能走通的条件, 就是写个函数执行 每一块都 上下左右 走一下, 判断走过的就不走了 碰到边界也不走
```

![image.png](https://pic.leetcode-cn.com/4f6e5c56326434f0986225f86079fbbb619a473d6cfa917f145e0d4c4ae3b7a7-image.png)


### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
  let total = 0
  let obj = {}
  function runing(i,j){
    //边界直接返回
    if(i < 0 || j < 0 || i >= m || j >= n) return
    let sum = (i + '' + j).split('').reduce((a,b) => +a + +b)
    let axis = JSON.stringify([i,j])
    if(sum <= k && !obj[axis]){  // 当该点还没走过 和 满足 不大于k 时 继续执行
      total++
      obj[axis] = true  // 标识该点已经走过, 下次不进
      // 当前的继续 上下左右 走
      runing(i + 1, j)
      runing(i, j + 1)
      runing(i - 1, j)
      runing(i, j - 1)
    }
  }
  runing(0,0)
  return total
};
```