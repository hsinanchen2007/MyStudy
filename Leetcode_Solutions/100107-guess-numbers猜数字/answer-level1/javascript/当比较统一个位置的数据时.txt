### 解题思路
两个数比较的都是同一个位置的数据，所以只需要一个索引就可以了

### 代码

```javascript
/**
 * @param {number[]} guess
 * @param {number[]} answer
 * @return {number}
 */
var game = function(guess, answer) {
    let sum = 0;

    for(let i = 0 ; i < guess.length; i++){
        if(guess[i] == answer[i]){
            sum++
        }
    }
    return sum
};
```