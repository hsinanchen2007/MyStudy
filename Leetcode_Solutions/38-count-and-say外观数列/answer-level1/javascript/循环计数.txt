var countAndSay = function(n) {
    let count = 1
    let str = '1'
    while(count < n) {
        let index = 1;
        let res = ''
        for(let i = 0; i < str.length; i++) {
            if (str[i + 1] && str[i] === str[i + 1]) {
                index++
                continue;
            } else {
                res = res.concat(index, str[i])
                index = 1
            }
        }
        count++
        str = res
    }
    return str
};