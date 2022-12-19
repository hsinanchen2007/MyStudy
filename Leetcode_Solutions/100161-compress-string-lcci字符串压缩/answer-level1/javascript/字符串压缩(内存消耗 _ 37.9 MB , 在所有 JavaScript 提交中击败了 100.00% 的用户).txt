```
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    // 记录原先字符串的长度和分解后的长度
    let count = S.length, now_len = 0, arr = [], r = [], t = S.split("");

    for(let i = 0; i < count; i ++) {
        let l = r.length - 1, j = arr.length - 1;
        if(arr.indexOf(t[i]) === -1 || arr[j] !== t[i]) {
            arr.push(t[i]);
            r[l + 1] = 1;
        } else {
            r[l] += 1;
        }
    }

    // 得到解析后的“字符串”，然后相加得到字符串的长度
    now_len = arr.length + r.length;

    // 若“压缩”后的字符串没有变短，则返回原先的字符串
    if(now_len >= count) {
        return S;
    } else {
        return arr.map(function(item, index) {
            return item + "" + r[index]
        }).join("");
    }
};
```
