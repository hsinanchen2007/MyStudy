```
代码块/**
 * @param {string} input
 * @return {number[]}
 */
var diffWaysToCompute = function(input) {
    var result = []
    for(var i = 0;i < input.length;i++){
        var c = input.charAt(i)
        if(c == '+' || c == '-' || c == '*'){
            var left = diffWaysToCompute( input.substring(0,i))
            var right = diffWaysToCompute( input.substring(i+1))
            for(var j = 0; j < left.length;j++){
                for(var n = 0; n <right.length;n++){
                    switch(c){
                        case '+':
                            result.push(left[j]+right[n])
                            break
                        case '-':
                            result.push(left[j]-right[n])
                            break
                        case '*':
                            result.push(left[j]*right[n])
                            break
                    }

                }
            }
        }
    }
    if(result.length == 0){
        result.push(parseInt(input))
    }
    return result


};

```
