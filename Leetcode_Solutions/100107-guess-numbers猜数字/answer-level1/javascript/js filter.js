### 解题思路
对比数组每位是否相等

执行用时 :68 ms, 在所有 JavaScript 提交中击败了31.91%的用户
内存消耗 :34.2 MB, 在所有 JavaScript 提交中击败了100.00%的用户

### 代码

```javascript
/**
 * @param {number[]} guess
 * @param {number[]} answer
 * @return {number}
 */
var game = function(guess, answer) {
    return guess.filter((key,index) =>{
        return key == answer[index]
    }).length
};
```