### 解题思路

 * 数出所有数字卡牌的个数
 * 求这一组的最大公约数，如果大于1则返回true，否则false
 
### 代码

```javascript
/**
 * 数出所有数字卡牌的个数
 * 如果，个数都是偶数，返回true
 * 求这一组的最大公约数，如果大于1则返回true，否则false
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    let list = [];
    for(let e of deck) {
        list[e] = list[e] ? list[e]+1 : 1
    }
    
    //去除undefined
    list = list.filter(e=>e);
    let gcdNum = list[0];
    for(let e of list) {
        gcdNum = gcd(gcdNum, e);
        if(gcdNum < 2) {
            return false;
        }
    }

    return true;
};

function gcd(num1, num2) {
    if(num2 === 0) throw Error('no 0');
    let tmp = num1 % num2;
    if (tmp === 0) {
        return num2;
    } else {
        return gcd(num2, tmp)
    }
}
```