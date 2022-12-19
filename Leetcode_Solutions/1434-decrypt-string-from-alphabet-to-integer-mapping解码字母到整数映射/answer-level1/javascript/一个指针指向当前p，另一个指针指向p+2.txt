### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var freqAlphabets = function(s) {
    const toChar = comb => String.fromCharCode(+comb+96); //把数字转成字母的函数
    const cache = [];
    let i=0, j=2;
    while(i<s.length){
        if(s[j]=='#'){ //如果i+2也就是j位置是#就说明前面两个表示的字母是超过10的
            const str = s.substring(i, j); //所以要截取他们俩出来做转换
            cache.push(toChar(str));
            i=j+1;
        }else{
            cache.push(toChar(s[i])); //否则就说明表示的字母在10以内直接转换当前字符就好了
            i++;
        }
        j=i+2;//j指针始终为当前位置后移2的位置检测是否为#
    }
    return cache.join('');
};
```