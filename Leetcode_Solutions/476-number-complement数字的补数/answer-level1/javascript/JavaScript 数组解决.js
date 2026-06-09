### 解题思路
![image.png](https://pic.leetcode-cn.com/fe99f2275a96244111bbc51a586b58c795ae4655768b66b58fed1089f230cc6b-image.png)

- 通过转换成数组进行遍历替换

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
    let str = num.toString(2).split('')
    for(let i = 0; i < str.length; i++){
        if(str[i] == 0){str[i] = 1}
        else{str[i] = 0}
    }
    return parseInt(str.join(''),2)
};
```