```javascript
var setZeroes = function(matrix) {
  let clr = false, clc = false
  matrix.map((v, m) => {
    // 使用第一行记录列是否要清空
    for(let [n, item] of v.entries()){
      if(item == 0){
        if(m == 0) clr = true
        else clc = true
        matrix[0][n] = true
      }
    }
    // 清空除第一行之外的行
    if(clc && m != 0){
      matrix[m] = new Array(matrix[0].length).fill(0)
      clc = false
    }
  })
  // 清空列
  matrix[0].map((_, i)=>{
    if(_ === true){
      for(let t = 0; t < matrix.length; t++){
      matrix[t][i] = 0
    }}
  })
  // 清空行
  if(clr) matrix[0] = new Array(matrix[0].length).fill(0)
  return matrix
};
```
