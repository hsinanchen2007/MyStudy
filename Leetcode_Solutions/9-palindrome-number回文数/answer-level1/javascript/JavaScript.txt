想到的是 利用不断对10求余来倒推，最后判断倒推的数和开始的数是否相等

    var isPalindrome = function(x) {
        if(x >= 0 && x < 10){ return true }
        if(x < 0 || x%10 == 0){ return false }
    
        let temp = x
        let newNum = 0
        while(temp > 0){
            newNum = newNum*10 + temp%10
            temp = (temp-temp%10)/10
        }
        return newNum == x
    };
