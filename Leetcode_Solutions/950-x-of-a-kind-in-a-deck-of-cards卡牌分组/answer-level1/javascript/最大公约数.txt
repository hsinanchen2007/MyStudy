### 解题思路
其实就是对每一个数出现次数的数组求最大公约数，如果大于1则返回true。

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var gcd = function(x, y){
    return x === 0?y:gcd(y%x,x)
}

var hasGroupsSizeX = function(deck) {
    let min = -1
    if(deck.length <=1){
        return false
    }
    let arr = []
    for(let i = 0; i<10000; i++){
        arr[i] = 0
    }

    for(let i = 0; i<deck.length; i++){
        arr[deck[i]]++;
    }
    
    for(let i = 0; i<arr.length; i++){
        if(arr[i] !== 0){
            if(min === -1){
                min = arr[i]
            }else{
                min = gcd(min, arr[i])
            }
        }
    }
    console.log(min)
    return min >1
};
```