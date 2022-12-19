### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps  = function(num) {
    let count = 0
    while(num > 0) {
        if (!(num % 2)) {
            // 是偶数
            num = num /2
        } else {
            num = num - 1
        }
        count++
    }
    return count
};
```

使用一个变量记录一下步数，再判断积偶数来进入除2或减1，返回步数