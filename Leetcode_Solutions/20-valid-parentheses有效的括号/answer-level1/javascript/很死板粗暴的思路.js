### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const left = ['(', '{', '[', ''];
    const right = [')', '}', ']', ''];

    const input = s.split('');
    if (!input.length) return true;
    if (input.length % 2 !== 0) return false;

    const valid = [];
    const isLeft = char => left.includes(char);
    const isRight = char => right.includes(char);

    let flag = true;
    for(let i = 0; i< input.length; i++) {
        if (isLeft((input[i]))) {
            valid.push(input[i]);
        } else {
            let checkValue = valid.pop();
            let checkType = left.findIndex(item => item === checkValue);
            if (right[checkType] !== input[i]) {
                flag = false;
                break;
            };
        }
    }

    return flag && !valid.length;
};
```

1、先是把属于左、右括号的放一堆，（后续会通过检验的值的下标作为“CP匹配”）；
2、最初是，发现输入的长度为奇数，直接return false；亦或者输入为空字符，直接return true；
3、新建一个数组valid用来存放当前的检验进度；
4、遍历输入的数组，若属于左括号的进行valid.push；若属于右括号的，对valid进行pop来检验；检验的方式是通过对比该字符所在下标，与其对应“CP”的下标是否相等；
5、最后通过flag和valid数组的长度进行综合判断结果。