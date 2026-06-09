### 解题思路
1. 将数字的出现次数存成一个数组
2. 求这个数组的最大公约数
3. 判断公约数是否大于等于2

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    if (!deck || !deck.length || deck.length === 1) return false;
    const hash = {};
    for (let i = 0; i < deck.length; i++) {
        if (hash[deck[i]]) {
            hash[deck[i]]++;
        } else {
            hash[deck[i]] = 1;
        }
    }
    function gcd(a,b){
        if(b == 0){
            return a;
        }
        var r = a % b;
        return gcd(b,r);
    }
    let arr = [];
    for (let key in hash) {
        arr.push(hash[key]);
    }
      if (arr.length < 1) return;
      while (arr.length > 1) arr.splice(0,2,gcd(arr[0],arr[1]));
      return arr[0] > 1;
};
```