### 解题思路
数组长度除以2 得到数组交换的次数，不管是偶数的还是基数的 然后进行一次循环交换就可以拉

### 代码

```javascript
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function(s) {
    if(s.length){
            let arrLen = s.length
            let changeCount = parseInt(arrLen / 2)

            for(let i = 0;i < changeCount;i++){
                let tmp = s[arrLen - i - 1]
                s[arrLen - i - 1] = s[i]
                s[i] = tmp
            }
        }

        return s
};
```