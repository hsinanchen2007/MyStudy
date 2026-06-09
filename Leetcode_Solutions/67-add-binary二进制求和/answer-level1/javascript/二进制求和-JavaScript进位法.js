采用将a,b用parseInt转换成二进制数相加后，调用toString(2)转二进制的方法会导致溢出。

/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let len1 = a.length;
    let len2 = b.length;
    let len = Math.max(len1, len2);
    // 是否进位
    let isCarry = false;
    // 用0补齐，让两个字符串长度相同
    function addZero(s, len) {
        if (len > 0) {
            for(let i = 0; i < len; i++) {
                s = "0" + s;
            }
        }
        return s;
    }
    a = addZero(a, len - len1);
    b = addZero(b, len - len2);
    let res = '';
    let posVal;

    for(let i = len - 1; i >= 0; i--) {
        // 进位则加1
        posVal = Number(a[i]) + Number(b[i]) + (isCarry ? 1 : 0 );
        // 大于1则进位
        isCarry = posVal > 1 ? true : false;
        // 进位后该位置值减2
        posVal = isCarry ? (posVal - 2).toString() : posVal.toString();
        res = posVal + res;
    }
    // 最后如果是进位，首位为1
    if (isCarry) {
        res = "1" + res;
    }
    return res;
};