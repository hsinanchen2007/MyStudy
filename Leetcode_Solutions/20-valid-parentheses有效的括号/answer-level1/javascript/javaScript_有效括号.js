**实现起来很简单，但是没看题解之前，纠结了很久**
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var stack = []
    for(var index = 0; index < s.length; index++){
        switch(s[index]){
            case "(":
            case "[":
            case "{":
                stack.push(s[index]);
                break;
            case ")":
                if(stack.pop() !== "(")
                    return false;
                break;
            case "]":
                if(stack.pop() !== "[")
                    return false;
                break;
            case "}":
                if(stack.pop() !== "{")
                    return false;
                break;
        }
    }
    return stack.length == 0 ? true : false;
};

