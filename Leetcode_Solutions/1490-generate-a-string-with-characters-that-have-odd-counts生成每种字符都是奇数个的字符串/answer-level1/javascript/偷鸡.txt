### 解题思路
偷鸡的解法
偶数1个x,n-1个y,
奇数全x,
然后排除0返回空
### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var generateTheString = function(n) {
    if(n == 0 ){
        return '';
    }
    else if (n%2 ==0) {
        return 'x' + 'y'.repeat(n-1);
    }
    else{
        return 'x'.repeat(n);
    }
};
```