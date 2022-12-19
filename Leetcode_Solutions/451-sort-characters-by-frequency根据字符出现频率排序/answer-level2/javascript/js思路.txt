### 解题思路
把字符串每个字符出现的数量放入一个对象中，然后按照大到小的顺序来输出排列~

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
    var arr = s.split('');
    var obj  = arr.reduce((prev, item, index) => {
        if(prev[item] == undefined) {
            prev[item] = 1;
        } else {
            prev[item] += 1;
        }
        return prev;
    }, {});
    var sortArr = Object.values(obj).sort((a, b) => b - a);
    var str = '';
    sortArr.forEach(item => {
        for(var key in obj) {
            if(obj[key] == item) {
                while(item--) {
                    str += key;
                }
                obj[key] = 0;
                break;
            }
        }
    });
    return str;
};
```