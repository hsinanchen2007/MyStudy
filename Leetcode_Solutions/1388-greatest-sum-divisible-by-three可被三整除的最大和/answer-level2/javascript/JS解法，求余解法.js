1、首先求出sum值，然后判断sum % 3

为0: 直接返回sum即可
为1: 找到sum减去余数为1的最小值或者两个余数为2的最小值（比较）
为2: 找到sum减去余数为2的最小值或者两个余数为1的最小值（比较）

![image.png](https://pic.leetcode-cn.com/5159561c0440eb6cda8c30fa47bc8bb86b8998bf6aba958c26e81e6542080f37-image.png)

```

var maxSumDivThree = function(arr) {
    let arr1 = arr.filter(item => item % 3 === 1).sort((a, b) => a - b);
    let arr2 = arr.filter(item => item % 3 === 2).sort((a, b) => a - b);
    console.log(arr1)
    console.log(arr2)
    let sum = arr.reduce((pre, cur) => pre + cur, 0)
    if (sum % 3 === 0) {
        return sum;
    } else if (sum % 3 === 1) {
        sum = Math.max(sum - arr1[0], sum - arr2[0] - arr2[1] | 0);
    } else {
        sum = Math.max(sum - arr2[0], sum - arr1[0] - arr1[1] | 0);
    }
    return sum
};
```
最后即可得到答案；

