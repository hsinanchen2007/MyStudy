### 解题思路
1. 获取第一个字符串，取出第n个字母
2. 遍历剩余的字符串，并且每次遍历到一个的时候，取出第n个字母
3. 把这个字母跟步骤1取出的那个字母对比
4. 相同的话，加入返回的字符串结果上，不同的话立刻返回

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(!strs.length)return '';
    const [first, ...rest] = strs;
    let index = 0, commonStr = '';
    let letter = first.charAt(index);
    while(letter){
        for(let word of rest){
            if(letter == word.charAt(index))continue;
            return commonStr;
        }
        commonStr += letter;
        letter = first.charAt(++index);
    }
    return commonStr;
};
```