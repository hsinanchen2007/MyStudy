var myAtoi = function(str) {
    if(str.length==0) return 0
    let patt = /^\s*([+-]?)\d+/,res=str.match(patt)
    if(res!=null){
        res = res[0]
        if(res>2147483647) return 2147483647
        if(res<-2147483648) return -2147483648
    }
    return res
};