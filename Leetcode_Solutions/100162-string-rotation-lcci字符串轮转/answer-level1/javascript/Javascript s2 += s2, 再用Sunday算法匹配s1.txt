```
var isFlipedString = function (s1, s2) {

    // 长度不一致，返回false
    if (s1.length !== s2.length) {
        return false;
    }

    //开始Sunday算法匹配
    let map =  {};
    for (let i = 0; i < s1.length; i++) {
        map[s1[i]] = s1.length - i;
    }
    s2 += s2;
    
    let n = s1.length,
        m = s2.length,
        i = 0,
        j;
    while (i <= m - n) {
        j = 0;
        while (s1[j] === s2[i + j]) {
            j++;
            if (j >= n) {
                return true;
            }
        }

        i += (map[s2[i + n]] === undefined ? n : map[s2[i + n]]);
    }
    return false;
};
```
