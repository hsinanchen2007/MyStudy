栈的思路js解法

枚举用反括号匹配，我们把对应的一正一反抵消就代表一对完整括号

比对步骤：

枚举匹配不到的一定是开始符号，压入。

枚举匹配到的分两种情况，一种是已经存在匹配项对应的开始符号，则可以抵消掉。

如果已有的不存在对应的开始符号则也需要压入

判断是否全部抵消掉

```javascript []
const enumObj = {
    ")":"(",
    "]":"[",
    "}":"{",
}

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let cache = [];
    let arr = s.split("");
    for(let i of arr){
        if(enumObj[i]){
            if(cache[cache.length - 1] === enumObj[i]){
               cache.pop()
            }else{
                cache.push(i)
            }
        }else{
            cache.push(i)
        }
    }
    return cache.length === 0
};
```
