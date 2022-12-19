### 解题思路
![image.png](https://pic.leetcode-cn.com/702facd6e5f261d7913b5786e88cc341671bcfab341663631e0b13a3be4cfaf4-image.png)

- 因为只有 1 个 二进制的数，则通过 (n & (n-1)) 可以将最后一位二进制的 1 转化成 0

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    if(n > 0){
        return (n & (n-1)) == 0;
    }else{
        return false
    }
};
```