原理是下一行的数等于上一行数加上上一行数向左或向右移一位：
- [1,1]
- [1,2,1] = [1,1] + [1,1,0] 或者 [1,1] + [0,1,1]

所以就复制上一个array然后shift或者unshift一个0就好。
```javascript []
var generate = function(numRows) {
  if(!numRows) return [];
  let result = [[1]];
  if(numRows == 1) return result;
  
  let i = 0;
  for(let i = 0; i < numRows - 1; i++){
    let p = result[i];
    let c = p.slice(0);
    c.unshift(0);
    
    for(let num in p){
      c[num] += p[num];
    }
    result.push(c);
  }
  return result;
};


