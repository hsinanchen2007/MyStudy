### 解题思路
1. 一开始想把集中特殊情况都集合起来单独处理，后面发现没有必要，因为特殊情况下的情况比较唯一：就是前一位的代表的数字比后一位代表的数字的值要小，所有就想到了使用数组固定每个字符的顺序来判断是否是小数在大数前面的想法，例如：line = ['I', 'V', 'X', "L", "C", 'D', 'M'];
2. 接下来就是遍历了，遍历的时候要注意同时看前后两位，如果不是1中的特殊情况，就走正常逻辑，否则取前两位做减法

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let mp = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    },

    line = ['I', 'V', 'X', "L", "C", 'D', 'M'];

    let res = 0;
    while(s.length){
        let firstChar = s.slice(0, 1);
        let secondChar = s.slice(1, 2);
        
        if(line.indexOf(firstChar) < line.indexOf(secondChar)){
            res += ( mp[secondChar] - mp[firstChar] )
            s = s.slice(2);
        }else{
            res += mp[firstChar];
            s = s.slice(1);
        }
        
        
    }
    return res;


};
```