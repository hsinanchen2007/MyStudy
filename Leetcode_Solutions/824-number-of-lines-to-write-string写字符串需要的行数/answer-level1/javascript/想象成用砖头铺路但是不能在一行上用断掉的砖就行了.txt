### 解题思路
1. 遍历字符串，然后根据拿出来的字符获取到它需要占用的空间
2. 累加这个空间
3. 如果超过100，就增加一行，也就是记录行的变量递增1

### 代码

```javascript
/**
 * @param {number[]} widths
 * @param {string} S
 * @return {number[]}
 */
var numberOfLines = function(widths, S) {
    const ofSpace = letter=> widths[letter.charCodeAt()-'a'.charCodeAt()];
    const W = 100;
    let ROW = 1, TAKEN = 0; //因为至少会有一行所以初始化ROW=1
    
    for(let i=0; i<S.length; i++){
        const space = ofSpace(S.charAt(i)); //获取该字符的所需空间
        const spaceTaken = TAKEN + space; //累加空间
        if(spaceTaken>W){ //如果这一行已经放不下了就让ROW增加1，也就是准备铺下一行，所以TAKEN累加变量重置为当前字符的宽度
            TAKEN=space;
            ROW++;
            continue;
        }
        TAKEN=spaceTaken; //如果还能放得下这行继续累加
    }
    return [ROW, TAKEN];
};
```