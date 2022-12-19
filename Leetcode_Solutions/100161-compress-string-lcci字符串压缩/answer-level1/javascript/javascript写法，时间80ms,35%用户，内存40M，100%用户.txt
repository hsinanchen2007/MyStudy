### 解题思路
考虑用hash统计字符串个数，先判断存在，在统计个数，注意点就是加上最后一个字符

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let sarr = S.split('')
    let resObj = {}
    let res = ''
    sarr.forEach((a,i) => {
        if(a in resObj) {
            resObj[a] ++
        }else {
            if(Object.keys(resObj).length == 0){
                resObj[a] = 1
            }else{
                res += sarr[i-1] + resObj[sarr[i-1]]
                resObj = {}
                resObj[a] = 1
            }
        }
        if(i == sarr.length-1){
            res += sarr[i] + resObj[sarr[i]]
        }
    })

    return res.length >= S.length ? S : res
};
```