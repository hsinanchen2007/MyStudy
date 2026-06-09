因为数组提供了倒序排列的方法,所以首先想到了把整数拆分成集合后反转拼成字符串再转整数
var reverse = function(x) {
    var isPositive = x > 0?true:false;
    x = Number(String(Math.abs(x)).split('').reverse().join(''))
    if(!isPositive){
        x = -x
    }
    if(x < Math.pow(-2,31) || x > Math.pow(2,31)){
        return 0
    }else{
        return x
    }
};