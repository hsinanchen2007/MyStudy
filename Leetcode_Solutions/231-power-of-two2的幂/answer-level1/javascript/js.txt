var isPowerOfTwo = function(n) {
    while(n){
        if(n==1){
            return true
        }else{
            n=n/2
        }
    }
    return false
};