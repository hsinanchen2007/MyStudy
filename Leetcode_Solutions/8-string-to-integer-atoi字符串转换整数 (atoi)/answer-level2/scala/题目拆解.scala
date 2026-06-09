1：把开头的空格全部去除，将空格去除后，开头必须是'+'、-、0-9的符号，不然返回0，如果数字已经开始（前面已经出现了+、-、0-9的字符了），如果再遇到非0-9的字符可以将前面已经累加的数返回。
2：要注意数字是否越界


object Solution {
    def myAtoi(str: String): Int = {
        var x = 0
        var index = 0
        var sign = 1
        var start = false
        while(index< str.length){
            var a = str.charAt(index)
            if(start && !(a >= '0' && a<= '9' ))
                return sign*x
            else if( a != ' '){
                if(!start && !((a >= '0' && a<= '9' ) || a == '-' || a=='+'))
                    return sign*x
                else if(start && !(a >= '0' && a<= '9' ))
                    return sign*x
                else{
                    start=true
                    if(a == '-')
                        sign = -1
                    else if(a=='+'){
                        
                    }
                    else {
                        var b = a - 48
                        if ((**sign * x) > Int.MaxValue / 10 || ((sign * x) == Int.MaxValue / 10 && b > Int.MaxValue % 10))
                            return Int.MaxValue
                        else if ((sign * x) < Int.MinValue / 10 || ((sign * x) == Int.MinValue / 10 && b > Int.MaxValue % 10)) {
                            return Int.MinValue**
                        } else {
                            x = x * 10 + b
                        }
                    }
                }

            }
            index+=1
        }
        return sign*x
    }
}