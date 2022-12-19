### 解题思路
“IV” 减1 加 5 ＝ 4
“XC” 减10 加 100 
遍历字符，找到相应的数值，加减的判断需要根据下一个数，如果后一个数比前一个数大，则需要减掉前一个数

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    return getInt(s)
};

var matchMap = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000
}
function getInt(inputStr){
    var inputArr = inputStr.split('');
    var result = 0;
    var preStr = inputArr[0];
    var preValue = matchMap[preStr] || NaN;
    for(var i=1; i<inputArr.length;i++){
        var nextStr = inputArr[i];
        var nextValue = matchMap[nextStr] || NaN;
        if(preValue<nextValue){
            result -= preValue
        }else{
            result += preValue
        }
        preValue = nextValue
    }
    result += preValue
    return result;
}
```