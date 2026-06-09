```
var isPalindrome = function(x){
    if(x<0) return false;
    var reverse = function(x) {
        var result = 0;
        var remainder;//声明余数变量
        while(x>0){
            reminder = x%10;
            x = (x-reminder)/10;
            result = result*10 + reminder;
        }
        return result
	};
     if(x === reverse(x)){
        return true
    }
}
```
