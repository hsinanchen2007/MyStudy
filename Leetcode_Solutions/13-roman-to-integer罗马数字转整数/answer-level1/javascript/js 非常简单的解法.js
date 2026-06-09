### 解题思路
需要先考虑小的数字在大的数字左边的情况（IV、IX、XL、XC、CD、CM），但是这六种情况实际上的值，是大的数字-小的数字。所以，遇上这种情况，先跳过一次该循环，在下次循环的时候进行处理。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let map = new Map();
    map.set('I', 1);
    map.set('V', 5);
    map.set('X', 10);
    map.set('L', 50);
    map.set('C', 100);
    map.set('D', 500);
    map.set('M', 1000);
    
    let result = 0;
    for(let i = 0; i<s.length; i++){
        // 如果后一位数比前一位大，说明这是需要特殊处理的数，先跳过，到下一次再进行相应的处理
        if(map.get(s[i]) < map.get(s[i + 1])) continue;
        // 首先看是否是上一次小的数在大的数前面而跳过处理的
        if(map.get(s[i - 1]) < map.get(s[i])){
            // 小的数在大的数前面，其值就是 大的数-小的数；例如：CD(400)=D(500)-C(100)
            result += map.get(s[i]) - map.get(s[i - 1]) 
        }else{
            result += map.get(s[i])
        }
    }
    return result;
};
```