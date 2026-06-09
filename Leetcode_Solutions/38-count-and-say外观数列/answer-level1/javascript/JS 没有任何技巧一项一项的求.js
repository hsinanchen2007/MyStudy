### 解题思路
没有任何技校，一项一项的求吧。
击败99.85%

### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    n--;
    let arr = ["1","11","21","1211","111221"];
    function desc(str){
        let result = "";
        for(let i = 0; i < str.length; i++){
            let j = 0;
            while(str[i] == str[i+j]){
                j++;
            }
            result += (j + str[i]);
            i +=j-1;
        }
        return result;
    }
    if(n <= 4){
        return arr[n];
    }
    for(let i = 5; i <= n; i++){
        arr[i] = desc(arr[i-1]);
    }
    return arr[n];
};
```