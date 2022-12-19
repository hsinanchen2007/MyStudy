
杨辉三角的第i行第j列应该为arr[i][j]=arr[i-1][j]+arr[i-1][j-1]，当arr[i-1][j]或者arr[i-1][j-1]不存在时，可以通过三元表达式将其设为0（即arr[i][0]=arr[i-1][0]+0;i行末尾的j为（i+1）,arr[i][j]=0+arr[i-1][j-1]]）
```
var generate = function(numRows) {
    let arr = []
    if(numRows>=1){
        arr = [[1]]
        for(let i=1;i<numRows;i++){
            arr[i]=[]
            for(let j=0;j<i+1;j++){
                arr[i][j]=(arr[i-1][j]?arr[i-1][j]:0)+(arr[i-1][j-1]?arr[i-1][j-1]:0)
            }
        }
    }
    return arr
};
```
