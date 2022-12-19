```
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
  if(numRows===0) return [];
  if(numRows===1) return [[1]];
  let trigle=[[1],[1,1]];
  for(let i=2;i<numRows;i++){
    let prevArr=trigle[i-1];//上一行数组
    let curArr=[1]; //当前数组，将第一位1先传入
    for(let j=1;j<=i-1;j++){
      let num=prevArr[j-1]+prevArr[j]; //当前数i是上一行的i-1与上一行的i之和
      curArr.push(num);
    }
    curArr.push(1)  //将最后一个数1传入，每一行的第一个和最后一个都是0，所以要计算的只有除了首末之外的数，也可以用三元表达式判别上一行的i是否存在，不存在则加0
    trigle.push(curArr)
  }
  return trigle
};
```
