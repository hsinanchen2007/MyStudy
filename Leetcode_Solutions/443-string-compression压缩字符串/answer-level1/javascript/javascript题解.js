### 解题思路
每次找到相同值的时候，就让标志flag增1，
当找到不同值的时候，先删除flag-1个已知重复值，接着算出flag的长度，将其插入到数组chars中。进入循环。

### 代码

```javascript
var compress = function(chars) {
    let letter = chars[0];
    chars.push('');
    let flag = 0;
    var sliceArr = [];
    for (let i = 0; i < chars.length;) {
        if (letter == '') {
            break;
        }
        if (letter == chars[i]) {
            flag++;
            i++;
        } else {
            letter = chars[i];
            if (flag > 1) {
                sliceArr = flag.toString().split('');
                chars.splice(i-flag+1, flag-1);
                for (let j = sliceArr.length-1, lenj = sliceArr.length; j >= 0; j--) {
                    chars.splice(i-flag+1, 0, sliceArr[j]);
                }
                i = i - flag + flag.toString().length+1;
            }
            flag = 0;
        }
    }
    chars.pop();
    return chars.length;
};
```