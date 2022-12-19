```
/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function(ops) {
    let arr = []
    ops.forEach((item,i) => {
        switch(item){
            case '+': 
                if(arr.length >= 2) {
                    arr.push(arr[arr.length - 1] + arr[arr.length - 2])                
                } else if (arr.length === 1){
                    arr.push(arr[0])
                } 
                break;
            case 'D':
                if(arr.length >= 1) {
                    arr.push(arr[arr.length - 1] * 2)                 
                }
                break;
            
            case 'C':
                arr.pop()
                break;
                
            default:
                arr.push(item * 1)
                break;
                
        }
    })
    return arr.length > 0 ? arr.reduce((total, num) => { return total + num}) : 0
};
```
