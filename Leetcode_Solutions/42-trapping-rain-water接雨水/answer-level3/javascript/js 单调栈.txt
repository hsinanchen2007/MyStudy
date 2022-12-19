```
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    var res = 0
    if(height.length < 3){
        return 0
    }
    var stack = []
    for(var i = 0;i < height.length;i++){
        while(stack.length > 0 && height[i] > height[stack[stack.length - 1]]){
            var top = stack.pop()
            if(stack.length == 0){
                break
            }
            var h = Math.min(height[i],height[stack[stack.length - 1]]) - height[top]
            var dis = i - stack[stack.length - 1] - 1
            res = res + h * dis
        }
        stack.push(i)
    }
    return res 


};
```
