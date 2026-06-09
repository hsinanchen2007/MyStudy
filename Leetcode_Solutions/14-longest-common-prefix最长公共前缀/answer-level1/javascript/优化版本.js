### 解题思路
上一个版本的优化

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let commonStr = '';
    let index = 0;
    let len = strs.length;

    if(len === 0){
        return ""
    }
    
    function xh(){
        let charArr = strs.map(item=>{
            return item.substr(index,1);
        })

        let fChar = charArr[0];

        let res = charArr.every(function (value, index) {
              return value === fChar;
          });

        if(res && fChar !== ""){
            commonStr+=fChar;
            index++;
            xh();
        }
    }
    
    xh();

    return commonStr;
};
```