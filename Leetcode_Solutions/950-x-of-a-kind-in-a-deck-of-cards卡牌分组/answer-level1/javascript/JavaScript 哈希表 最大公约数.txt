### 解题思路
求所有数字个数的最大公约数

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    if(deck.length === 0) return false;
    let hs = [];
    //哈希求各个数字个数
    deck.forEach((item)=>{
        hs[item] = hs[item] ? hs[item] + 1 : 1;
    })
    //数组去重
    let temp = [...new Set(hs)];
    let result = 1;
    if(temp.length) result = temp[0];
    //最大公约数函数
    let gcd = (x,y) => {
        let a=x%y;
        while(a){
            x=y;y=a;a=x%y;
        }
        return y;
    }
    //求数组的所有值的最大公约数
    while(temp.length > 1){
        let num1 = temp[0], num2 = temp[1];
        result = gcd(num1,num2)
        if(result == 1){
            return false
        } else {
            temp.splice(0,2,result)
        }
    }
    //最大公约数是否大于1
    return result > 1;
};
```