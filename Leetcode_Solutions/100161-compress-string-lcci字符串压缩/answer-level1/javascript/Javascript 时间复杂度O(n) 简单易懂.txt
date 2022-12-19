

```
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let array = S.split('');
    let string = ''; // 生成的字符串
    let index = 1; // 重复项
    for (let i = 0; i < array.length; i++) {
        // 相互两个不相等则拼接字符串，如'a' + 2
        if (array[i] != array[i + 1]) { 
            string += array[i] + index;
            index = 1;
        } // 若相等，则重复项 +1
        else {
            index ++;
        }
        // 生成的字符串长度大于或等于原有字符串，则返回原有字符串，减少耗时
        if (string.length >= S.length) { return S; }
    }
    return string;
};
```
