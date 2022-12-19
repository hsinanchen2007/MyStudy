### 解题思路
**把拿到的数组 的 行弄成列, 列弄成行, 得到一个二维数组**

比如说: 传入一个["cba", "daf", "ghi"]

把它处理成: 
```
          [ 
            ['c','d','g'], 
            ['b','a','h'], 
            ['a','f','i']
          ]
```

**筛选出哪一行是递增的 得到一个数组,  这个数组的长度就是就是剩下的**

筛选剩下:

```
          [ 
            ['c','d','g'], 
            ['a','f','i']
          ]
```
剩下长度为2.

**再拿最初数组任意一项的长度减去 这个数组的长度**

任意一项: 比如'cba' 长度为3, 相当于 把 'b' 拿掉了, 剩下'ca', 他要的就是拿掉的个数

返回 3 - 2 = 1

我觉得这样展开来弄可能比较容易理解.

### 代码

```javascript
/**
 * @param {string[]} A
 * @return {number}
 */
  var minDeletionSize = function(A) {
    // 处理成一个 行列对调 的数组
    let n = A.length
    let m = A[0].length
    let lis = Array.apply(null,Array(m)).map(item=>{
      return Array.apply(null,Array(n)).map(item=>{
        return ''
      })
    })
    for(let i=0;i<m; i++){
      for(let j = 0;j<n; j++){
        lis[i][j] = A[j][i]
      }
    }
    // 筛选出递增的项
    let arr = lis.filter((item,index)=>{
      let flag = true
      let x = item
      for(let i=0;i < x.length-1;i++ ){   // 没想到有什么优雅的方法判断一个数组是否递增
        if(x[i] > x[i+1]){
          flag = false
        } 
      }
      return flag
    })
   // 题目要的是 删掉的项的数量, 所以把原来的数 减去 剩下的数 
    return m-arr.length
};
```