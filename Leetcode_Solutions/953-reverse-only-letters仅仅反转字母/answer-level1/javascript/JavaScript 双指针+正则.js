### 解题思路
将字符串分割为数组，然后循环遍历，头指针遇到字母则和尾指针遇到字母进行交换
### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var reverseOnlyLetters = function(S) {
    let tmp = S.split('');
    var i = 0,j = tmp.length-1;
    var tmpstr = '';
    while(i<j){
        if(!/([a-z]|[A-Z])+/.test(tmp[i])){
            i++;continue;
        }
        if(!/([a-z]|[A-Z])+/.test(tmp[j])) {
            j--;continue;
        }
        tmpstr = tmp[i];
        tmp[i] = tmp[j];
        tmp[j] = tmpstr;
        i++;j--;
    }
    return tmp.join("");
};
```