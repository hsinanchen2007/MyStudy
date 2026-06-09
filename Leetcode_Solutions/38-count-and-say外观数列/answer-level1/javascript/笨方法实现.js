我看题解里大多是正则加递归的方法，然后就写了个普通的笨实现方法实现。
都是灵活运用基础函数。。。
```
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    let s = '1', str = '', arr = '', j = 0, ss = '';
    if(n == 1) return '1';
    n--;
    while(n--){
        str = '';
        while(s.length){
            for(let i = 0; i < s.length; i++){
                ss = s[0];
                if(s[0] === s[i]){
                    j = i;
                }else{
                    break;
                }
            }
            arr = s.slice(0, j + 1);
            s = s.slice(j + 1);
            str += (arr.length + ss);
        }
        s = str;
    }
    return str;
};
```
