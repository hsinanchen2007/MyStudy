### 思路一: 栈

根据题目的意思，我们需要运行一个`string`中的表达式，得出结果。我们可以在遍历一次字符串的时候，同时维护两个`stack`，一个用于存储数字，一个存储操作符:
```JavaScript
const nums = [], operators = [];
```
在存入数据之后，我们需要一个工具来计算结果，我们需要根据`operators`的最后一个值，运算`nums`中最后的两个数字，即完整代码中的`calculator`函数。

在遍历字符串的时候，我们遇到数字字符的时候会需要区分这个字符是前一个数字的一部分，还是一个新的数字。在这里我们可以用`nums`及`operators`的长度来对比，因为完整的表达式中，运算符的长度会比数字的长度少一个，所以如果`nums`与`operator`的长度相同，则该字符为新的数字，否则该字符为上一个数字的后续。

```JavaScript
if (nums.length === operators.length) {
    nums.push(+s[i]);
} else {
    nums.push(nums.pop() * 10 + +s[i]);
}
```

最后我们需要决定在遍历字符串中，触发运算动作的条件。当我们遇到低优先级运算符`+`和`-`时，我们可以将之前的运算符全部运算完，将结果推入`nums`中，然后再推入新的运算符。因为低优先级的运算符不会影响前面的结果。而遇到高优先级运算符`*`和`/`时，我们需要注意前一个运算符是同样为高优先级运算符，若是，则因先处理前一个运算符，因为同一等级的运算符须从左往右计算，否则会有错误。
```JavaScript
if (s[i] === '+' || s[i] === '-') {
    while (operators.length > 0) {
        calculator(nums, operators);
    }
} else {
    const op = operators[operators.length - 1];
    if (op === '*' || op === '/') {
        calculator(nums, operators);
    }
}
operators.push(s[i]);
```

#### 完整题解
```JavaScript []
var calculate = function (s) {
    // 分别存储未计算的数字及符号
    const nums = [],
        operators = [];
    const numReg = new RegExp(/[0-9]/);

    /** 用于将nums最后得两个数根据 operators 最后一个符号作运算，将结果存入 nums */
    const calculator = (nums, operators) => {
        const b = nums.pop();
        const a = nums.pop();
        const op = operators.pop();
        switch (op) {
            case '+':
                nums.push(a + b);
                break;
            case '-':
                nums.push(a - b);
                break;
            case '*':
                nums.push(a * b);
                break;
            case '/':
                nums.push(parseInt(a / b));
                break;
        }
    }

    for (let i = 0; i < s.length; i++) {
        if (s[i] === ' ') {
            continue;
        }
        if (numReg.test(s[i])) {
            // 若为数字且数字的长度与操作符长度相同，下一个必定是单独的数字
            if (nums.length === operators.length) {
                nums.push(+s[i]);
            } else {
                // 若数字长度与操作符长度不符，下一个数字字符为前一个数字的一部分。
                nums.push(nums.pop() * 10 + +s[i]);
            }
        } else {
            // 若为低优先级运算符，则先将前面的所有运算结算。
            if (s[i] === '+' || s[i] === '-') {
                while (operators.length > 0) {
                    calculator(nums, operators);
                }
            } else {
                // 若为高优先级运算符，则如果前一运算符也是高优先级运算符，先计算之前的数字。
                // 因同一优先级运算须从左到右运算，若最后从右往左算结果会有问题。
                const op = operators[operators.length - 1];
                if (op === '*' || op === '/') {
                    calculator(nums, operators);
                }
            }
            operators.push(s[i]);
        }
    }
    // 最后如有未计算的运算符
    while (operators.length > 0) {
        calculator(nums, operators);
    }
    return nums[0];
};
```

### 思路二: 单独存储未运算的数字和操作符

参考了运算速度快的答案，非常有意思的想法。在代码中定义了几个变量，其中`operator`记录上一个操作符，`sum`代表当前的结果，`preNum`代表上一个参与运算的数字，`curNum`代表当前的数字。
```JavaScript
let operator = '+',
    sum = 0,
    preNum = 0,
    curNum = 0;
```
在遇到当前的字符为操作符时，不管当前的操作符是什么，都根据`operator`记录的前一个操作符作运算:

当`operator`为`-`时，将`sum`与当前数字相减，并将负数存入`preNum`中:
```JavaScript
sum -= curNum;
preNum = -curNum;
```
当`operator`为`+`时，将`sum`与当前数字相加，并将证书存入`preNum`中:
```JavaScript
sum += curNum;
preNum = curNum;
```
当`operator`为`*`时, 将`sum`减去`preNum`，加上`preNum`与`curNum`相乘的结果，并记录相乘的结果前一个参与运算的数字:
```JavaScript
sum = sum - preNum + preNum * curNum;
preNum = preNum * curNum;
```
当`operator`为`/`时, 将`sum`减去`preNum`，并加上`preNum`与`curNum`相除的结果，并记录相除的结果为前一个参与运算的数字:
```JavaScript
sum = sum - preNum + parseInt(preNum / curNum);
preNum = parseInt(preNum / curNum);
```
这样的做法可以简化上面的判断的流程，只根据前一运算符作运算，并记录上一个参与运算的右值，当发现下一个符号为`*`或者`/`时，再减去`preNum`，再加上`preNum`与`curNum`运算的值。在内存的运用上更是可以击败100%的用户。

#### 完整题解
    执行用时 :92 ms, 在所有 javascript 提交中击败了89.71%的用户
    内存消耗 :36.1 MB, 在所有 javascript 提交中击败了100.00%的用户

```JavaScript []
/**
 * @param {string} s
 * @return {number}
 */
var calculate = function (s) {
    let operator = '+',
        sum = 0,
        preNum = 0,
        curNum = 0;
    const numReg = new RegExp(/[0-9]/);

    for (let i = 0; i < s.length + 1; i++) {
        if (s[i] === ' ') {
            continue;
        }
        if (numReg.test(s[i])) {
            curNum = curNum * 10 + +s[i];
        } else {
            switch (operator) {
                case '-': {
                    sum -= curNum;
                    preNum = -curNum;
                    break;
                }
                case '+': {
                    sum += curNum;
                    preNum = curNum;
                    break;
                }
                case '*': {
                    sum = sum - preNum + preNum * curNum;
                    preNum = preNum * curNum;
                    break;
                }
                case '/': {
                    sum = sum - preNum + parseInt(preNum / curNum);
                    preNum = parseInt(preNum / curNum);
                    break;
                }
            }
            curNum = 0;
            operator = s[i];
        }
    }
    return sum;
};
```