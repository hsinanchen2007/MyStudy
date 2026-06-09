**1.递归加缓存**
```
var minimumTotal = function(triangle) {
  let cache={};
  function findMinSum(i,j){
    let key=i+','+j;
    if(cache[key]){
      return cache[key];
    }
    
    if(i==triangle.length-1){
      return triangle[i][j];
    }
    
    cache[key]=triangle[i][j]+Math.min(findMinSum(i+1,j),findMinSum(i+1,j+1));
    return cache[key];
  }
  
  return findMinSum(0,0);
};
```

**2.动态规划 自顶向下**
```
var minimumTotal = function(triangle) {
  for(let i=1;i<triangle.length;i++){
    for(let j=0;j<triangle[i].length;j++){
      if(j==0){
        triangle[i][j]+=triangle[i-1][j];
      }
      else if(j==triangle[i].length-1){
        triangle[i][j]+=triangle[i-1][j-1];
      }
      else{
        triangle[i][j]+=Math.min(triangle[i-1][j-1],triangle[i-1][j]);
      }
    }
  }
  return Math.min(...triangle[triangle.length-1]);
}
```
**3.动态规划 自底向上 只会改变最后一行数据**

  参考了别人的答案

```
var minimumTotal = function(triangle) {
  let line=triangle[triangle.length-1];
  for(let i=triangle.length-2;i>=0;i--){
    for(let j=0;j<=i;j++){
      line[j]=triangle[i][j]+Math.min(line[j],line[j+1]);
    }
  }
  return line[0];
};
```




