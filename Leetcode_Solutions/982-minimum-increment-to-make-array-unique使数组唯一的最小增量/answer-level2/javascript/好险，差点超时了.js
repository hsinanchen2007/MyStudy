### 解题思路
![image.png](https://pic.leetcode-cn.com/f7ef716d9d634b212579722e91a910ab9d15f5dadcfc35d2c088ae949c9205ed-image.png)

繁复，但是否相对更好理解呢？哈哈，未必了。搞了三个数组，uniqueArr放A中只出现一次的数字，dupliArr放重复出现的数字，vancArr放uniqueArr中的空缺数字。然后把dupliArr挨个尝试插进vancArr中去，没法插就全部怼到uniqueArr后面去。

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function (A) {
    if (A.length === 0) return 0;

    let uniqueArr = [],
        dupliArr = [],
        vancArr = [],
        sortedA = A,
        i = 0,
        moveCnt = 0;

    sortedA.sort((a, b) => { return a - b; });

    while (i < sortedA.length) {
        if (sortedA.lastIndexOf(sortedA[i]) != i) {
            dupliArr.push(sortedA[i])
        } else {
            uniqueArr.push(sortedA[i]);
        }
        i++;
    }

    if (dupliArr.length === 0) return 0;

    let tail = uniqueArr.length - 1;
    for (let i = uniqueArr[0]; i <= uniqueArr[tail]; i++) {
        if (uniqueArr.indexOf(i) === -1) vancArr.push(i);
    }

    let j = 0;
    while (j < vancArr.length && dupliArr.length > 0 && vancArr.length > 0) {
        if (dupliArr[0] < vancArr[j]) {
            moveCnt += (vancArr[j] - dupliArr[0]);
            dupliArr.shift();
            uniqueArr.push(vancArr[j]);
            vancArr.splice(j, 1);
        } else {
            j++;
        }
    }

    let newMax = Math.max(...uniqueArr) + 1;
    while (dupliArr.length > 0) {
        moveCnt += (newMax - dupliArr[0]);
        uniqueArr.push(newMax);
        dupliArr.shift();
        uniqueArr.push()
        newMax++;
    }

    return moveCnt;
};

```