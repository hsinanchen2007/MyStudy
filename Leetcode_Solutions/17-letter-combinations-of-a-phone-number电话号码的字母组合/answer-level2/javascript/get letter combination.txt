### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if(digits == "") return [];
    let letter = new Map();
    //将组合以数组形式存入map
    letter.set('2',['a','b','c']);
    letter.set('3',['d','e','f']);
    letter.set('4',['g','h','i']);
    letter.set('5',['j','k','l']);
    letter.set('6',['m','n','o']);
    letter.set('7',['p','q','r','s']);
    letter.set('8',['t','u','v']);
    letter.set('9',['w','x','y','z']);

    digits = digits.split('');
    let res = letter.get(digits[0]);//设置初始值
    for(let i = 1; i < digits.length; i++){//对digits进行遍历
        let tmp = res.slice(0);//当前res设置为tmp
        let res2 = [];//新res2用于存储新的res
        let next = letter.get(digits[i]);//tmp和next的字母一一进行组合push到res2
        for(let j = 0; j < tmp.length; j++){
            for(let k = 0; k < next.length; k++){
                res2.push(tmp[j]+next[k]);
            }
        }
        res = res2.slice(0);//res2赋给res
    }
    return res;
};
```