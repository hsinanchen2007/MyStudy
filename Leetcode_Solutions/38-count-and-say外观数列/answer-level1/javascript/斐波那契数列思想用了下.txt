var countAndSay = function(n) {
    let m = 1
    if (n === 1) return '1'
    while(n - 1 > 0) {
        m = change(m)
        n-=1
    }
    return m
}

function change(m) {
    let mArr =  m.toString().split('')
    let n = 0
    let nString = ''
    for(let i = 0; i < mArr.length; i+=1) {
        n+=1
        if (mArr[i] !== mArr[i+1]) {
            nString += `${n}${mArr[i]}`
            n = 0
        }
    }
    return nString
}