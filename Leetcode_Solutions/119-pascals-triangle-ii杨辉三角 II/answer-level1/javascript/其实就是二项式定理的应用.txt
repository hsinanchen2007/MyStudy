![binomial.svg](https://pic.leetcode-cn.com/21369ff914866d5534e2805cb9b2be617a5962582b48b405aff1c6b0c820caf0-binomial.svg)

![binomial.jpg](https://pic.leetcode-cn.com/48662d77ca0b00608438743752e72ab055a07f323b476a13764bd01f99875455-binomial.jpg)

耐心看一下，不难理解~

```js
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    let arr = [1];
    for(let i=1;i<=rowIndex;i++){
        arr.push([arr[i-1]*(rowIndex-i+1)/i]);
    }
    return arr;
};```


