
看了高赞的滑动窗口，写了js版本。
大体思路是定义范围边界：**左边界left和右边界right:**，
如果当前的和sum小于target，则右移右边界--增大，
如果当前的和sum大于target，则右移左边界--收缩。

如示例target = 9
第一轮：left:1, right:1
数组[1]
sum:0 < target
增大右边界：right++

第二轮：left:1, right:2
数组[1,2]
sum:3 < target
增大右边界：right++
...
第四轮：left:1, right:4
数组[1,2,3,4]
sum:10 > target
收缩左边界：lleft++

这样第五轮left:2, right:4
数组[2,3,4]
sum:9 === target
找到正确的数组，记录下来，再收缩左边界，寻找下一个数组。

```
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let list = [];
    let left = 1;
    let right = 1;
    let sum = 0;
    while(left < target/2) {
        if(sum < target) {
            sum += right;
            right++;
        } else if (sum > target) {
            sum -= left;
            left++;
        } else {
            let arr = [];
            for (let i = left; i < right; i++) {
                arr.push(i);
            }
            list.push(arr);
            sum -= left;
            left++;
        }
    }
    return list;

};
```
