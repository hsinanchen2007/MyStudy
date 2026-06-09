###思路：
尝试了递归，可行，但是会超时，说明计算量太大
###代码：
```javaScript
var coinChange = function(coins, amount) {
    if(amount===0){
        return 0;
    }else if(coins.indexOf(amount)>=0){
        return 1;
    }else{
        let mini = [];
        for(let item of coins){
            if(amount-item>=0){
                mini.push(coinChange(coins,amount-item));
            }
        }
        if(mini.length){
            return Math.min(...mini)<0?-1:Math.min(...mini)+1;
        }else{
            return -1;
        }
    }
};
```