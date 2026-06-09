### 解题思路
每一步都是取出X的最后一位,然后同步X删掉最后一位
当不断取出和删除的时候，后半部分等于或者大于前半部分就停止
此时注意有可能后半部分是大的，所以除以10，取整
### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x !=0 && x% 10 == 0){return false}

    let temp = 0;
    while(x > temp){
        temp = temp * 10 + x%10
        x= Math.floor(x/10)
    }
    return x == temp ||  Math.floor(temp/10) == x
};
```