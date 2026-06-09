### 解题思路
贪心算法，按从大到小取
![Screenshot from 2020-04-02 16-12-16.png](https://pic.leetcode-cn.com/1337dbe4d02f3063c38888e8abcd237fd6ba1172a2435c6ab9a7d9af91ddbce4-Screenshot%20from%202020-04-02%2016-12-16.png)
### 代码

```javascript
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function (num) {
    let keys = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1],
        values = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];
    let res = "";
    for (let i = 0; i < keys.length; i++) {
        while (num >= keys[i]) {
            num -= keys[i];
            res += values[i];
        }
    }
    return res;
};
```