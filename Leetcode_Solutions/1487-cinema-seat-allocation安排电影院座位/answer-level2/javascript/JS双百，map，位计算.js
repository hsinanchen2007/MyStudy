### 解题思路

JS个人第一个双百，值得记录

![image.png](https://pic.leetcode-cn.com/736db9edf3b2da2582e3a267532b671ecedc567fc615cebf1bc6a3c81b8fefb6-image.png)

用map存放，key = 有预定的“行号”，value = 预定列号的数组。
只需要构建map数量的10列二维数组，因为1 <= reservedSeats.length <= min(10*n, 10^4)。每行用0，1来代表是否空，0是已预定，1是可预定，则：

该行可预定家庭数量为：Math.max(列1，2，3，4的AND + 列5，6，7，8的AND), (中间4列，即3，4，5，6的AND);

最后加上reservedSeats中没有的行数，每行可预定两个家庭。

（有个test case的n是1000000000，直接创建n*10的二维数组会报错，或者TLE的）

### 代码

```javascript
/**
 * @param {number} n
 * @param {number[][]} reservedSeats
 * @return {number}
 */
var maxNumberOfFamilies = function (n, reservedSeats) {
    let familyNum = 0,
        seat = [],
        resvMap = new Map();

    reservedSeats.forEach((val, idx, arr) => {
        let col = [];
        if (!resvMap.has(val[0] - 1)) {
            col.push(val[1] - 1);
        } else {
            col = resvMap.get(val[0] - 1);
            col.push(val[1] - 1);
        };
        resvMap.set(val[0] - 1, col);
    });

    resvMap.forEach((val, key, map) => {
        let row = [];

        for (let i = 0; i < 10; i++) {
            if (val.indexOf(i) === -1) row.push(1);
            else row.push(0);
        }
        familyNum += Math.max((row[1] & row[2] & row[3] & row[4]) + (row[5] & row[6] & row[7] & row[8]), (row[3] & row[4] & row[5] & row[6]));
    });

    familyNum += (n - resvMap.size) * 2;

    return familyNum;
};


```