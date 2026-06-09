通过对题目以及网友的见解，最终形成一种思路

> 首先对数独进行分析
 + 每行不能重复
 + 每列不能重复
 + 将数独分成 **9** 个小盒子，每个盒子不能重复

采用最笨的办法，把每行，每列，每个盒子分别组成一个新的数组，只需要当前数据没有重复即为 `true`， 反之为 `false`


![nine.jpg](https://pic.leetcode-cn.com/196f99f4c5536e4b289d8013c6f4ae101ee8cb4d8bd958da045f2fb742d78f4e-nine.jpg)



```javascript []
  // 行
  const rows = board
  // 列
  const columns = [
    [],
    [],
    [],
    [],
    [],
    [],
    [],
    [],
    []
  ]
  for (let i = 0; i < 9; i ++) {
    const item = board[i]
    for (let j = 0; j < 9; j ++) {
      columns[j][i] = item[j]
    }
  }
  
  // 盒子
  const boxes = {}
  for (let i = 0; i < 9; i ++) {
    const row = Math.floor(i / 3)
    for (let j = 0; j < 9; j ++) {
      /**
       * 区分象限
       * Math.floor(i/3) 列中属于哪儿
       * Math.floor(j/3) 列中属于哪儿
       * 
       * 行列合并便知道具体是第几个啦
       */
      const column = Math.floor(j / 3)
      const item = board[i][j]
      
      const key = row + '' + column

      if (boxes[key]) {
        boxes[key].push(item)
      } else {
        boxes[key] = [item]
      }
    }
  }

   // 是否9行
  const isRows = isRepeat(rows)

  // 是否 9列
  const isColmns = isRepeat(columns)
  
  // 盒子是否
  const isBoxes = isRepeat(Object.values(boxes))

  return isRows && isColmns && isBoxes
}

/**
 * @description: 判断数组是否重复
 * @param {Array} nums 二维数组
 * @return: boolean
 */
function isRepeat (nums) {
  return nums.every(item => {
      const temp = item.map(val => { if (val !== '.') return val }).filter(item => item)
      return (new Set(temp)).size === temp.length        
  })
}
```

> 上面代码使用了多次 `for` 循环，完全可以再进行优化一下，但是作为讲解原理，应该足够了