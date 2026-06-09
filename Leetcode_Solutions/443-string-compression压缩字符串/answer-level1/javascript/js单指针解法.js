```
var compress = function(chars) {
    let count = 1;
    let i = 0;
    while (i < chars.length) {
        if (chars[i] === chars[i + 1]) {
            count++;
            chars.splice(i,1);
        } else {
            if (count > 1) {
                i++;
                let str = count + "";
                let len = str.length;
                for (let k = 0; k < len; k++) {
                    chars.splice(i, 0, str.charAt(k));
                    i++;
                }
                count = 1;    // 重新开始计数
            } else {
                i++;        // 只有一个独特的字符，不重复，指针后移
            }
        }
    }
    return chars.length;
};
```
