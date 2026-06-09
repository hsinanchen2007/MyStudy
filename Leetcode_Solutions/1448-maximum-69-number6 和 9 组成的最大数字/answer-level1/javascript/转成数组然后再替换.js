### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var maximum69Number  = function(num) {
    const arr = [];
    const tmp = (''+num).split('');
    for(let i=0; i<tmp.length; i++){
        let n = tmp[i];
        if(n==9){
            arr.push(n);
        }else{
            arr.push('9');
            arr.push(...tmp.slice(i+1));
            break;
        }
    }
    return +(arr.join(''))
};
```