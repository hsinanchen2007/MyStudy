### 解题思路

从1开始遍历，然后一直往上加加到超过target值还没找到则break，找到也break，并且将结果加入到返回的数组中去

然后从2,开始继续上面的操作...

接下来从3，...

一直到从n开始，n+(n+1)的值都超过了或者等于target的值时，就是退出主循环的时候

然后将结果数组返回

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function (target) {
    let x = 1; // 左边的数
    let rtn = [];
    while (true) {
        let y = x + 1; // 右边的值
        let sum = (x + y) * (y - x + 1) / 2; // 等差数列求和公式
        if (sum > target) {
            break;
        } else if (sum < target) {
            while (true) {
                let sum = (x + y) * (y - x + 1) / 2;
                if (sum > target) {
                    break;
                } else if (sum < target) {
                    y++;
                } else {
                    rtn.push(getArr(x, y));
                    break;
                }
            }
            x++;
        } else {
            rtn.push(getArr(x, y))
            break;
        }

    }
    return rtn;

};

function getArr(x, y) {
    let arr = [];
    for (let i = x; i <= y; i++) {
        arr.push(i)
    }
    return arr;
}
```