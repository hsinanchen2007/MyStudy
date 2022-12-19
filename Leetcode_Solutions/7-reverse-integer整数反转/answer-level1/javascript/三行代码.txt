var reverse = function(x) {
    let arr=0,s=Math.abs(x).toString().split('').reverse().join(''),r=Math.pow(2,31)
    x<0?(-s>=-r?arr=-s:arr=0):(s<=r-1?arr=s:arr=0)
    return arr
};