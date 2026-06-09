var isPalindrome = function(x) {
    if(x<0)return false
    let str=x+''
    for(let i=0;i<=str.length/2;i++){
        if(str[i]!=str[str.length-1-i]){
            return false
        }
    }
    return true
};