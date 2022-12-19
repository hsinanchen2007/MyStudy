### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x < 0 ) return false;
    if( x >= 0 && x < 10) return true;
    let n = 1;
    let res = 0;
    // 计算此数字是几位数
    while(Math.floor(x / (Math.pow(10,n)))){
        n++;
    }
    // 算出前半部分数字
    let q = n % 2 ? Math.floor( x / Math.pow(10,(n-1)/2 + 1)) : Math.floor(x / Math.pow(10,n/2));
    // 后半部分数字
    let p = n % 2 ? x % Math.pow(10,(n-1)/2) : x % Math.pow(10,n/2);
    //将前半部分转化为后半部分
    while(q){
        res = res *10 + q % 10;
        q = Math.floor(q / 10);
    }
    // 判断是否相等
    if(res === p) return true;
    return false;
};
```