var addBinary = function(a, b) {
    let sum = []
    let temp = 0;
    let cal = 0
    // 对其二进制数，长度短的前面补0
    if(a.length >= b.length){
        b = b.padStart(a.length, '0')
    }else{
        a = a.padStart(b.length, '0')
    }
    // 从后往前遍历两个一样长的字符串
    for(let i=a.length-1; i>=0; i--){
        // 字符串相加，加上进位
        temp = parseInt(a[i]) + parseInt(b[i]) + cal;
        // 判断进位是0还是1与需要进位的当前位的值
        if(temp >= 2){
            sum[i] = temp - 2;
            cal = 1;
        }else{
            sum[i] = temp;
            cal = 0;
        }
    }
    // 最后一位（第一位）的进位数，是1的话前面补1
    if(cal > 0){
        sum.unshift(1)
    }
    // 组合字符
    return sum.join('')
# };