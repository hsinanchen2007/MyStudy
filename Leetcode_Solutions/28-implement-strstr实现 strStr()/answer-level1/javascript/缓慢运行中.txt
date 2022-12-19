### 解题思路
此处撰写解题思路
前两个if语句很容易理解，接着找第一个匹配的字符，在第一匹配字符的索引开始，匹配needle长度减一个字符进行比较看是否匹配
needle.length == count 匹配 否则j++继续进行寻找，最终找不到返回-1
### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if(needle == "") return 0;
    if(haystack.length < needle.length) return -1;
    for(let j = 0; j < haystack.length - needle.length + 1;j++){
        if(haystack.charAt(j) == needle.charAt(0)){
            let k = 1;
            let count = 1;
            while(k < needle.length){
                if(haystack.charAt(j+k) == needle.charAt(k)){
                    count++;
                }
                k++;
            }
            if(needle.length == count){
                return j;
            }
        }
    }
    return -1;
};
```