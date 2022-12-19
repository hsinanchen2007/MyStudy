var longestPalindrome = function(s) {
    // 获取所有的字符的个数
    let cMap = new Map();
    for(let item of s){
        cMap.set(item , cMap.has(item) ? cMap.get(item) + 1 : 1)
    }
    // 对每个字符进行与2相除，商*2为可收录长度，余数存在为1的值则长度加1
    let isGotRemainder = false, quotient = 0
    for(let m of cMap){
        // 商
        quotient += Math.floor(m[1] / 2)
        // 余数
        if(!isGotRemainder && m[1] % 2 === 1){
            isGotRemainder = true
        }
    }
    return isGotRemainder ? (quotient * 2) + 1 : (quotient * 2)
};