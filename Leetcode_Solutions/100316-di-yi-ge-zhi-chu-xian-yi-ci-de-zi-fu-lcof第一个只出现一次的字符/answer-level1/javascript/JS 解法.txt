### 代码

```javascript
var firstUniqChar = function(s) {
    if(s.length === 1) return s
    let arr = s.split('');
    for(let i = 0; i < arr.length; i++){
        let arr1 = arr.slice(0, i);
        let arr2 = arr.slice(i+1);
        if(arr1.indexOf(arr[i]) === -1 && arr2.indexOf(arr[i]) === -1){
            return arr[i]
        }
    }
    return ' '
};
```