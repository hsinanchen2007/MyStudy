```js
var findTheDistanceValue = function(arr1, arr2, d) {
    let len1 = arr1.length;
    let len2 = arr2.length;
    let result = 0
    for(let i = 0 ; i < len1 ; i++){
        let sign = true
        for(let j = 0 ; j < len2 ; j++){
            const temp = Math.abs(arr1[i]-arr2[j])
            if(temp <= d){
               sign = false 
            }
        }
        if(sign) {
            result+=1
        }
    }
    return result
};
```
