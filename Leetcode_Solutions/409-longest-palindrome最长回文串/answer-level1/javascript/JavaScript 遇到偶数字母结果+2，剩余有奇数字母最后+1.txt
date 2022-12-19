### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    //max为偶数字母*2，flag为奇数字母个数，hashmap记录是否当前为偶数
    var max = 0,flag = 0,hashmap = [];
    //遍历字母处理
    for(var i = 0; i < s.length; i++){
        if(hashmap[s.charCodeAt(i)]){
            flag -= 1;max += 2;hashmap[s.charCodeAt(i)] = 0;
        }else{
            hashmap[s.charCodeAt(i)] = 1;flag += 1;
        }
    }
    if(flag) max += 1;
    return max;
};
```