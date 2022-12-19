### 解题思路
执行用时 :60 ms, 在所有 JavaScript 提交中击败了99.17%的用户
内存消耗 :38.8 MB, 在所有 JavaScript 提交中击败了100.00%的用户

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let compresS = "";
    let curr_item = S[0];
    let count = 0;
    for(let i = 0; i < S.length; i++){
        if(S[i] !== curr_item){
            compresS += curr_item + count;
            curr_item = S[i];
            count = 1;
        }else{
            count += 1;
        }
    }
    compresS += curr_item + count;
    return compresS.length < S.length ? compresS : S;
};
```