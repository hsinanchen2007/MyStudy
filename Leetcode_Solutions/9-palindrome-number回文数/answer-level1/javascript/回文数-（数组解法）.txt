```
var isPalindrome = function(x) {
    //先处理负数，由题知负数一定不是回文数
    if(x<0){
        return false
    }
    else{
        var cur = x
        var arr = []
        var count = -1
        //将x存入数组
        while(cur){
            count++
            arr[count] = cur % 10
            cur = Math.floor(cur / 10)           
        }
        for(var i = 0;i < count / 2;i++){   //只需判断一半的数便可
            if(arr[i] != arr[count-i]){     //第一个数与最后一个数对比，第二与倒二...
                return false
            }
        }
        return true
    }
};
```
