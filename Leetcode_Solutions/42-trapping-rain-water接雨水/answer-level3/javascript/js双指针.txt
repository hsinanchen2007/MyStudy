```js
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {

   let result = 0;
    
   let left = 0 ,right = height.length - 1;
    let leftMax = 0,rightMax = 0;
    
    while(left<right){
        leftMax = Math.max(leftMax,height[left]);
        rightMax  = Math.max(rightMax,height[right]);
        
        let cur = 0;
        
        if(leftMax <= rightMax){
            cur = height[left]
            result += leftMax - cur;
            left ++;
        }else{
            cur = height[right]
            result += rightMax - cur;
            right --;
        }
    }
    
    return result;
};
```
