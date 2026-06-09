思路：
如果栈为空或者栈顶的元素等于当前元素，就push，否者就pop

PS：有于js中没有栈，只能用数组代替栈，增加一个变量代表栈顶元素的指针

```
/**
 * @param {string} S
 * @return {string}
 */
var removeDuplicates = function (S) {
    let s = []
    let j = -1;
    for(let i of S){
        if(s[j] === i){
            s.pop()
            j--
        }else{
            s.push(i)
            j++
        }
    }
    return s.join('')
};
```
