### 解题思路
js 字符串是只读的……   不能改原字符串，所以放到数组中

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
    let arr = s.split(''),n = arr.length,i= 0,j = n-1;
    while(i<j){
        while(i<n && !['a','e','i','o','u'].includes(arr[i].toLowerCase())){
            i++
        }
        while(j>=0 && !['a','e','i','o','u'].includes(arr[j].toLowerCase())){
            j--
        }
        
        if(i<j){
            [arr[i],arr[j]] = [arr[j],arr[i]]
            i++
            j--
        }
    }
    return arr.join('')
};
```