本题与 [415 Add Strings](https://leetcode-cn.com/problems/add-strings) 的题目很相似，也是输入两个字符串，不允许用`Integer library`。解题的思路也类似，将两个字符串转换成单一字符数组后，用`ASCII`编码来获取每一位的数字。之后再用竖式乘法来算结果。
#### 竖式乘法 ####
对于例子中的`123 * 456`，我们可以通过得到:
``` 
3 * 456 + 20 * 456 + 100 *456 = 1368 + 9120 + 45600 = 56088 
```
#### 实际演算 ###
首先，我们需要将字符串转换成单一字符的数组，并且用每一个字符的 `charCode` 减去 `'0'.charCodeAt(0)`的方式转换为数字:
```
const left = '0'.charCodeAt(0);
// num1Arr 取较短的数字， num2Arr 取较长的数字，短数乘长数速度较快。
const num1Arr = (num1.length > num2.length ? num2 : num1).split('').map(item => item.charCodeAt(0) - left);
const num2Arr = (num1.length > num2.length ? num1 : num2).split('').map(item => item.charCodeAt(0) - left);
```
接着，我们需要用 `num1Arr` 的每一位分别去乘以 `num2Arr` 的每一位，并且将结果记录在 `res` 数组中。

为了方便记录数组，我们将数组的结果反过来记录，即位数高的数字在数组的前列，位数高的数字在数组的后面。如`[ 6, 5 ]`代表`56`。

如上面的例子，在`123 * 456`的计算中， `2 * 6` 时结果应该是 `2 * 6 * 10 = 120`，存储在倒序的数列中就是`[0, 2, 1]`。 即在结果中的起始`index`应该为`1`。设`2`的`index`为`i`, `6`的`index`为`j`,
```
const resArr = (num1Arr[i] * num2Arr[j]).toString().split('');
            resArr.reverse();
const index = num2Arr.length - 1 - j + num1Arr.length - 1 - i = 3 - 1- 2 + 3 - 1 - 1 = 1
```
接着我们要将其结果按照`index`的起始顺序，一位一位加到结果中:
```
let next = 0, k = 0;
while (k < resArr.length || next !== 0) {
    // 结果当前位数加上前一位的进位
    let sum = (res[index + k] | 0) + next;
    // 若 k < resArr，即非最后一位进位
    if (k < resArr.length) {
        sum += +resArr[k];
    }
    res[index + k] = sum % 10;
    // 若 sum 大于10，进位+1
    next = sum / 10 >= 1 ? 1: 0;
    k++;
}
```
### 完整代码

```Javascript []
var multiply = function(num1, num2) {
    const left = '0'.charCodeAt(0);
    // 首先将字符串用 charCodeAt 转换成对应的数字。
    // num1Arr 取较短的数字， num2Arr 取较长的数字，用 num1Arr 去分别乘 num2Arr 速度会提升15ms
    const num1Arr = (num1.length > num2.length ? num2 : num1).split('').map(item => item.charCodeAt(0) - left);
    const num2Arr = (num1.length > num2.length ? num1 : num2).split('').map(item => item.charCodeAt(0) - left);
    let res = [];
    for (let i = num1Arr.length - 1; i > -1; i--) {
        for (let j = num2Arr.length - 1; j > -1; j--) {
            // 数字的相乘的结果转换为数组，并且 reverse，方便计算
            const resArr = (num1Arr[i] * num2Arr[j]).toString().split('');
            resArr.reverse();
            const index = num2Arr.length - 1 - j + num1Arr.length - 1 - i;
            let next = 0, k = 0;
            while (k < resArr.length || next !== 0) {
                // 结果当前位数加上前一位的进位
                let sum = (res[index + k] | 0) + next;
                // 若 k < resArr，即非最后一位进位
                if (k < resArr.length) {
                    sum += +resArr[k];
                }
                res[index + k] = sum % 10;
                // 若 sum 大于10，进位 = 1
                next = sum / 10 >= 1 ? 1: 0;
                k++;
            }
        }
    }
    // 去除结果前的 0
    while (res.length > 1 && res[res.length - 1] === 0) {
        res.pop();
    }
    return res.reverse().join('');
};
```