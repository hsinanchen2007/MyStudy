### 解题思路
题目说 有一个n * m 矩阵 ( 行 * 列 ) ,然后又一个坐标点列表, 每个坐标点对应的矩阵 横 竖 都加上1, 拿到加完后的矩阵,找出其中奇数点的个数 

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @param {number[][]} indices
 * @return {number}
 */
var oddCells = function(n, m, indices) {
   // 获取矩阵 这里写在一起 之前拆开来写  发现结果不对  找了半天
    let nm = Array.apply(null,Array(n)).map(item=>{
      return Array.apply(null,Array(m)).map(item=>{
        return 0
      })
    })
    // 遍历坐标点, 坐标点在的 横竖 都加上1
    indices.forEach(item=>{
      let x = item[0]
      let y = item[1]
      nm[x] = nm[x].map(t=>{
        return ++t
      })
      nm.forEach(arr=>{
        arr[y]++
      })
    })
    let num = 0
    // 得到增量操作后的矩阵nm  遍历 然后 筛选出奇数
    nm.forEach(i=>{
      num += i.filter(t=>{
        return t % 2 === 1
      }).length
    })
    return num
};

```