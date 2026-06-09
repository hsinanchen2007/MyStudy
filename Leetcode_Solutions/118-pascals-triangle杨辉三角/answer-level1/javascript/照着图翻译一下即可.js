### 解题思路

在杨辉三角中，每个数是它左上方和右上方的数的和。

用伪代码来说就是  n[i] = (n-1)[i] + (n-1)[i-1]

``` js
//如: 5

//我们先建个 数组: 每行长度递增 , 每行的每个元素为1

list = [
          [1],
          [1,1],
          [1,1,1],
          [1,1,1,1],
          [1,1,1,1,1]
        ]

// 在循环这个list, 把从第三项开始实现这个 伪函数 n[i] = (n-1)[i] + (n-1)[i-1]

list = [
          [1],
          [1,1],
          [1,2,1],
          [1,3,3,1],
          [1,4,6,4,1]
        ]

```

### 代码

```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 */

 
var generate = function(numRows) {
  let list = []
  for(let i = 1; i<= numRows; i++){                   // 先建个 数组  每行长度递增 , 每行的每个元素为1
    let arr = Array.apply(null,Array(i)).map(t => 1)
    list.push(arr)
  }

  list = list.map((item,index) => {
    if(index >= 2){                       // 当第三行开始才有这个规律
      let last = list[index-1]
      list[index] = item.map((t,i) => {   // 把list 的 index 重新赋值 , 
        if(i > 0 && i < item.length - 1){ // 去除首尾项
          return last[i] + last[i-1]
        }
        return t
      })
      return list[index]
    }
    return item
  })
  return list
};

```