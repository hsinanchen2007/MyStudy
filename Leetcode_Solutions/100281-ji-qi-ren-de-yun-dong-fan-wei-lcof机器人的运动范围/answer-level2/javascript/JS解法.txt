### 代码

```javascript

var movingCount = function(m, n, k) {
    let flag = [];
    for(let i = 0; i < m; i++){
        let row = new Array(n).fill(0);
        flag.push(row)
    }
    return helper(0, 0, m, n, flag, k)
};

const helper = (i, j, m, n, flag, k) => {
    if(i<0 || j<0 || i>=m || j>=n || getSum(i)+getSum(j)>k || flag[i][j]==1){
        return 0
    }
    flag[i][j] = 1;
    return helper(i-1, j, m, n, flag, k) + 
           helper(i+1, j, m, n, flag, k) +
           helper(i, j-1, m, n, flag, k) +
           helper(i, j+1, m, n, flag, k) +
           1
}  

const getSum = (num) => {
    let sum = 0;
    do{
        sum += num % 10 
    }while((num = Math.floor(num/10)) > 0)
    return sum 
}
```