### 解题思路
这题更像是考察对Date对象的api熟练度而不像是一道算法题。。。

### 代码

```javascript
/**
 * @param {number} day
 * @param {number} month
 * @param {number} year
 * @return {string}
 */
var dayOfTheWeek = function(day, month, year) {
    const date = new Date(`${year}-${month}-${day}`);
    const weeks = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    return weeks[date.getDay()];
};
```