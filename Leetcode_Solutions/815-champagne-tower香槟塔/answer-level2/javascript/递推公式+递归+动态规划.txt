流经标号为`(i,j)`的杯子的香槟可能来自： 
1. 上一层左边的杯子，标号为：`(i-1,j-1)`  
2. 上一层右边的杯子，标号为：`(i-1,j)`   
3. 当i=0,j=0的香槟来自于倒入的所有香槟即：`poured`  
**注意当`j<0`或者`j>i`时，此处不存在杯子，因此来自此处的香槟恒为0**

又因为其上一层杯子的香槟会平分为2个部分，因此：  
`f(i,j)(left)=Math(f(i-1,j-1)-1,0)/2`  
`f(i,j)(right)=Math(f(i-1,j)-1,0)/2`  
因此有：  
`f(i,j)=Math(f(i-1,j-1)-1,0)/2 + Math(f(i-1,j)-1,0)/2` 

方法一：递归+备忘录
```javascript
var champagneTower = function(poured, query_row, query_glass) {
    let dp = new Array(101).fill(0).map(_=>new Array(101).fill("#"));
    let result =  Math.min(M(query_row,query_glass),1);
    return result;
    
    //流经i行，j列的香槟的量
    function M(i,j){
        if(i===0 && j===0){
            return poured;
        }
        if(j<0||j>i)return 0;
        if(dp[i][j]!="#")return dp[i][j];
        let left = Math.max(M(i-1,j-1)-1,0)/2;
        let right = Math.max(M(i-1,j)-1,0)/2;
        return dp[i][j]=left+right;
    }
};
```
方案二：动态规划
```javascript
var champagneTower = function(poured, query_row, query_glass) {
    let dp = new Array(query_row+1).fill(0).map(_=>new Array(query_row+1));
    
    dp[0][0]=poured;
    for(let r = 1;r<=query_row;r++){
        dp[r][0]=Math.max(dp[r-1][0]   -1,0)/2;
        dp[r][r]=Math.max(dp[r-1][r-1] -1,0)/2;
        for(let j=1;j<r;j++){
            let left  = Math.max(dp[r-1][j-1]-1 ,0)/2;
            let right = Math.max(dp[r-1][j]-1   ,0)/2;
            dp[r][j]=left+right;
        }
    }
    return Math.min(dp[query_row][query_glass],1);
}
```