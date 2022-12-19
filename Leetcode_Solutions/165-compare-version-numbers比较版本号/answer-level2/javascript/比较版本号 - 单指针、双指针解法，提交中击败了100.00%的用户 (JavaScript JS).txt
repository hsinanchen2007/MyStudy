### 思路

版本号的的比较顺序应该是从大版本往小版本开始对比，每个版本之间用`.`隔开。因此我们可以将两个版本字符串以`.`分隔开，从第一个版本号开始往下对比，若遇到`version1`的当前版本号大于`version2`，则返回`1`,否则返回`-1`。若一方的小版本号为空，则看另外一方的小版本号是否不为`0`。

根据上面的思路有两种做法，一种是用`JavaScript`自带的`Array.split()`函数，将其以`.`分割成数组。另一种是不使用数组，用双指针去指向当前版本号所在的位置。

### 题解一 单指针双数组
```JavaScript []
/**
 * 执行用时 :68 ms, 在所有 javascript 提交中击败了73.38%的用户
 * 内存消耗 :33.8 MB, 在所有 javascript 提交中击败了19.57%的用户
 */
var compareVersion = function(version1, version2) {
    const arrayA = version1.split('.');
    const arrayB = version2.split('.');

    let pointer = 0;
    while (pointer < arrayA.length && pointer < arrayB.length) {
        const res = arrayA[pointer] - arrayB[pointer];
        if (res === 0) {
            pointer++;
        } else {
            return res > 0 ? 1 : -1;
        }
    }
    // 若arrayA仍有小版本号
    while (pointer < arrayA.length) {
        if (+arrayA[pointer] > 0) {
            return 1;
        } else {
            pointer++;
        }
    }
    // 若arrayB仍有小版本号
    while (pointer < arrayB.length) {
        if (+arrayB[pointer] > 0) {
            return -1;
        } else {
            pointer++;
        }
    }
    // 版本号完全相同
    return 0;
};
```

### 题解二 双指针
与上面的做法相比，只是将字符分割的部分自己实作。
```JavaScript []
/** 
 * 执行用时 :48 ms, 在所有 javascript 提交中击败了100.00%的用户
 * 内存消耗 :33.6 MB, 在所有 javascript 提交中击败了58.70%的用户
*/
var compareVersion = function(version1, version2) {
    let pA = 0, pB = 0;
    /** 寻找当前区间的版本号 */
    const findDigit = (str, start) => {
        let i = start;
        while (str[i] !== '.' && i < str.length) {
            i++;
        }
        return i;
    }

    while (pA < version1.length && pB < version2.length) {
        const nextA = findDigit(version1, pA);
        const nextB = findDigit(version2, pB);
        const numA = +version1.substr(pA, nextA - pA);
        const numB = +version2.substr(pB, nextB - pB);
        if (numA !== numB) {
            return numA > numB ? 1 : -1;
        }
        pA = nextA + 1;
        pB = nextB + 1;
    }
    // 若arrayA仍有小版本号
    while (pA < version1.length) {
        const nextA = findDigit(version1, pA);
        const numA = +version1.substr(pA, nextA - pA);
        if (numA > 0) {
            return 1;
        }
        pA = nextA + 1;
    }
    // 若arrayB仍有小版本号
    while (pB < version2.length) {
        const nextB = findDigit(version2, pB);
        const numB = +version2.substr(pB, nextB - pB);
        if (numB > 0) {
            return -1;
        }
        pB = nextB + 1;
    }
    // 版本号完全相同
    return 0;
};
```