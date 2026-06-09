### 解题思路
遍历 24 字母，判断每个字母在目标字符串中出现一次时，判断他的下标是否小于结果下标，如果小于就赋值

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
// var firstUniqChar = function(s) {
//     var strLength = s.length;
//     var index = -1;
//     for (var i = 0; i < strLength;i ++) {
//         var char = s.charAt(i);
//         if (s.match(new RegExp(char, 'g')).length === 1) {
//             index = i;
//             break;
//         } 
//     }
//     return index;
// };

var firstUniqChar = function(s) {
    if (!s) {
        return -1;
    }
    var lowCaseStr = 'abcdefghijklmnopqrstuvwxyz';
    var strLength = lowCaseStr.length;
    var minIndex = -1;
    for (var i = 0; i < strLength;i ++) {
        var char = lowCaseStr.charAt(i);
        var matchArr = s.match(new RegExp(char, 'g'));
        if (matchArr && matchArr.length === 1) {
            index = s.indexOf(char);
            if (minIndex === -1 || minIndex > index) {
                minIndex = index;
            }
        } 
    }
    return minIndex;
};
```