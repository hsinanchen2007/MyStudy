### 解题思路
分析题意及示例，取每个数出现次数之间的最大公约数，且最大公约数范围大于等于2
### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    // 计次
    let deckMap = new Map();
    for(let i = 0; i < deck.length; i++){
        let item = deck[i];
        if(deckMap.has(item)){
            deckMap.set(item, deckMap.get(item) + 1);
        }else{
            deckMap.set(item, 1);
        }
    }
    // 取最大公约数
    let gcdNum = Array.from(deckMap.values()).reduce(function(a, b){
        return gcd(a, b);
    });
    // 最大公约数范围 大于等于2
    return gcdNum >=2;
};

// 更相减损 执行次数较多
// function gcd (a, b){
//     if(a === b){
//         return a;
//     }
//     let min = Math.min(a, b);
//     let max = Math.max(a, b);
//     return gcd(max - min, min);
// }

// 辗转相除
function gcd (a, b){
    return a? gcd(b%a, a) : b;
}
```