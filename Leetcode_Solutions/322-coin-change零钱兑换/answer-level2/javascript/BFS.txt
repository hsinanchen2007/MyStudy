### 解题思路
看代码，不会dp

### 代码

```javascript
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    //队列
    const queue = [];
    queue.push(amount);
    //过滤重复的值
    const s =new Set();
    //记录
    let step = 0;
    while(queue.length>0){
        //1
        //3
        let len = queue.length;
        for(let i=0; i<len;i++){
            //11
            //10
            let temp = queue.shift();
            if(temp == 0){
                return step
            }
            for(let coin of coins){
                /**
                 * 11>1 而且减去当前硬币（11-1=10）不存在s中  10 9 8 5
                 * 11>2 而且减去当前硬币（11-2=9）不存在s中   9  8 7 4
                 * 11>5 而且减去当前硬币 （11-5=6）不存在s中  6  5 4 1 
                 */
                if(temp >= coin && !s.has(temp-coin)){
                    s.add(temp-coin)
                    queue.push(temp-coin)
                }
            }
        }
        //11   加1
        step+=1;
    }

    return -1
};
```