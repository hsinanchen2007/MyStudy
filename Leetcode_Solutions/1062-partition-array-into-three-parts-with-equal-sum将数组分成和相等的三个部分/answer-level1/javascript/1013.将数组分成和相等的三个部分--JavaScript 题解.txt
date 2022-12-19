时间复杂度 O(n), 空间复杂度 O(1) 
1. 先计算数组和 sum，如果数组长度小于3 或者 不能整除3，则直接 return false
2. 数组循环，从左到右累加，如果碰到累加结果 = sum/3，则重新累加直到碰到下一个累加结果 = sum / 3
3. 要注意[1,-1,-1,1]的情况，所以第二个 for 循环到数组长度 - 1

```
var canThreePartsEqualSum = function (A) {
    let sum = A.reduce((x, y) => x + y);
    let res = false;
    if (sum % 3 !== 0 || A.length < 3) return res;
    let avg = sum / 3;
    let temp = 0, i = 0, temp1 = 0 ;
    for (i; i < A.length - 2; i++) {
        temp += A[i]
        if (temp === avg) break
    }
    for (var j = i + 1; j < A.length - 1; j++) {
        temp1 += A[j]
        if (temp1 === avg) res = true;
    }
    return res;
};
```
