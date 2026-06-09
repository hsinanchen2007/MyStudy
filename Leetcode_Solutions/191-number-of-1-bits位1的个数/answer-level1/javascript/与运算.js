### 解题思路
核心思想就是n & (n -1) 就是去掉最后一位的1 ，然后不断的操作，判断消掉多少次

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let index = 0;
    while(n){
      ++index
      n =  n & (n-1)
    }
    return index
};
```