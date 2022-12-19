### 解题思路
此处撰写解题思路
将字符串按k分割存储到数组，然后反转数组奇数位存储的字符串
### 代码

```javascript
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function(s, k) {
    var res = '';
    var tmpstr = [];
    while(s.length > k){
        tmpstr.push(s.substr(0,k));
        s = s.slice(k);
    }
    tmpstr.push(s.slice(0));
    for(var i = 0; i < tmpstr.length; i++){
        if(i&1) continue;
        tmpstr[i] = tmpstr[i].split('').reverse().join('');
    }
    return tmpstr.join('');
};
```