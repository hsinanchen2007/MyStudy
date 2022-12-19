#### 思路（转字符串）
将`x`转成字符串。
```
var isPalindrome = function(x) {
    // 判断特殊情况
    if (x < 0) return false;
    if (x === 0) return true;
    x += '';
    let i = 0;
    let j = x.length - 1;
    while (i < j) {
        if (x[i++] !== x[j--]) {
            return false;
        }
    }
    return true;
};
```
#### 进阶
取出`x`的每位上的数，放到数组中，用思路一的方式判断。
#### 代码
```
var isPalindrome = function(x) {
    if (x < 0) return false;
    if (x === 0) return true;
    let array = []
    // 判断x除以10的结果，如果没到个位数，就保存余数
    while (parseInt(x / 10) !== 0) {
        array.push(x % 10);
        x = parseInt(x / 10)
    }
    // 将最后一位数保存
    array.push(x);
    let i = 0;
    let j = array.length - 1;
    while (i < j) {
        if (array[i++] !== array[j--]) {
            return false;
        }
    }
    return true;
};
```
