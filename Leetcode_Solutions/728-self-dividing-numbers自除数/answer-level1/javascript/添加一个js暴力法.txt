
直接上代码
var selfDividingNumbers = function(left, right) {
    let result = [];

    while(left <= right){
        let wei = String(left).length;
        let danwei = 10;
        let curr = left;
        
        while(wei > 0){
            num = curr % 10;
            
            if(num === 0)
                break;
            if(left%num !== 0)
                break
            curr = Math.floor(curr/10)
            wei--;
        }
        
        console.log(num, wei);
        if(wei === 0 )
            result.push(left);
        
        left++
    }
    return result
};
