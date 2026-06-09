### 解题思路
此处撰写解题思路

### 代码

解法一：
如果`bits[i] === 1`则这个 1 一定属于二比特的，这时候可以再循环中 +2，如果不是则加一，最后判断和是否是最后一个数的索引
```javascript
var isOneBitCharacter = function(bits) {
    let i = 0
    while(i < bits.length - 1){
        i += (bits[i] + 1)
    }
    return i === bits.length - 1
};
```

解法二：
正则

```javascript
var isOneBitCharacter = function(bits) {
    return /^(0|10|11)*0$/.test(bits.join(''))
};
```