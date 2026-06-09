```javascript
/**
 * @param {string} s
 * @return {string}
 */
// 解法一 转数组 再转回 string
var replaceSpace = function(s) {
    return s.split(' ').join('%20')
};
// 解法二 用正则写一个replaceAll的方法 替换掉所有空格
function replaceAll(str , replaceKey , replaceVal){
    var reg = new RegExp(replaceKey , 'g');//g就是代表全部
    return str.replace(reg , replaceVal || '');
}
var replaceSpace = function(s) {
    return s.replaceAll(' ', '%20')
}
```