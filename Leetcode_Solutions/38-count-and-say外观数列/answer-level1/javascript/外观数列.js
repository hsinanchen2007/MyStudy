### 一、基于递归
上一次的结果给下一次使用，递归在这种场景下最适用了！
#### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */

var countAndSay = function(n) {
   if(n === 1) {
       return '1'
   }
   let str = countAndSay(n-1);
   let chart = str.charAt(0);
   let count = 1;
   let result = '';
   for(let i = 1 ; i < str.length;i++) {
       if(str[i] === chart) {
           count ++;
       } else {
           result = result.concat(count);
           result = result.concat(chart);
           chart = str[i];
           count = 1;
       }
   }
   result = result.concat(count);
   result = result.concat(chart);
   return result;
};
```

### 二、基于迭代
优点:速度比较快
#### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    if(n === 1) {
        return '1'
    };
    let str = '1';
    let flag = 1;
    let result = '';
    while(flag < n) {
        result = ''; // 这里需要每次进循环的时候把result置为空
        let chart = str.charAt(0);
        let count = 1;
        for(let i = 1; i< str.length;i++) {
            if(str[i] === chart) {
                count++
            } else {
                result = result.concat(count);
                result = result.concat(chart);
                count = 1;
                chart = str[i];
            }
        }
        result = result.concat(count);
        result = result.concat(chart);
        str = result; // 更新str的置
        flag++;
    }
    return result;
}
```