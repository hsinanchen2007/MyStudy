### 解题思路
此处撰写解题思路
最老实人的想法。。。

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */

var numberOfSteps = function (num) {
    var a = 0;
    function numsolve(num) {
        if (num % 2 == 0) {
            num = num / 2;
            ++a;
        } else {
            num = num - 1;
            ++a;
        }
        if (num == 0) {
            return a;
        }
        return numsolve(num);
    }
    numsolve(num);
    return a;
};
```
