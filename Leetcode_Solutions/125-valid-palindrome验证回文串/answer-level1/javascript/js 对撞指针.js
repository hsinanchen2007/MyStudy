
时间复杂度 O(n)
```
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    var reg = /[a-z0-9]/ig
    var arr = s.match(reg)
    if(arr == null) return true
    var i = 0,j = arr.length - 1
    while(i < j){
        if(arr[i].toLowerCase() == arr[j].toLowerCase()){
            i++
            j--
        }else {
            return false
        }
    }
    return true
};
```
