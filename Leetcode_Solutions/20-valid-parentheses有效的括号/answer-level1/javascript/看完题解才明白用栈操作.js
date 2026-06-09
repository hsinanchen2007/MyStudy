### 解题思路
实在没思路，看的题解。略略略

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var arr=[];
    var obj = {
        '(': 1,
        ')': -1,
        '{':2,
        '}':-2,
        '[': 3,
        ']': -3
    }
    if(s === ""){
        return true
    }
    arr.push(s.charAt(0));
    for(var i = 1;i<s.length;i++){
         var pre = arr.pop();
         if(obj[pre] + obj[s.charAt(i)] !== 0) {
            pre && arr.push(pre); 
            arr.push(s.charAt(i));
         }
         if(arr.length > ~~(s.length/2)){
             return false
         }
    }
    if(arr.length === 0 ){
        return true
    }
    if(arr.length>0){
        return false
    }
 
 };
```