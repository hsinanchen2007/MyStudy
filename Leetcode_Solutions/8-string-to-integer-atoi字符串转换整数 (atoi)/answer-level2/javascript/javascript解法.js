```
/*
分成两种情况进行考虑。一种是已经找到了合法字符，一种是未找到合法字符，
需要注意的是返回结果需要是一个整形，后台可能加了类型验证
对于内部出错的，建议检查在比较是否超出整数范围之前判断是否是NaN，由于是从字符串转过来的，在比较时，可能已经是NaN了，之后再比较是否超出整数范围时，就会出现内部出错。
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    let res = '',
        findedNum = false;
    if(str.length == 0){
        return 0;
    }
    for(let i = 0; i < str.length; i++){
        let current = parseInt(str[i]);
        if(!findedNum){
            if(str[i] == ' ')
                continue;
            if(isNaN(current) && (str[i] != '+' && str[i] != '-')){a
                return 0;
            }else{
                findedNum = true;
                res = res + str[i];
                continue;
            }
        }else{
            if(isNaN(current)){
                break;
            }else{
                res = res + str[i];
            }
        }
    }
    let resInt = parseInt(res);
    if(isNaN(resInt)){
        return 0;
    }else{
        if(resInt > (Math.pow(2,31) - 1))
            return Math.pow(2,31) - 1;
        else if(resInt < (-Math.pow(2,31)))
            return -Math.pow(2,31);
    }
    return resInt;
};
```