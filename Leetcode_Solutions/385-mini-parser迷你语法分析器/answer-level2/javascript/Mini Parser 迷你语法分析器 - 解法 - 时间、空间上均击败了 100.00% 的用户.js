### 思路

首先我们需要厘清题目的意思。从例子的情况来看是，我们需要将给定的字符串`Parser`成定义好的`NestedInteger`，而这个`NestedInteger object`可以包含一个单独的整数，或者是一个`list`，`list`里面包含新的`NestedInteger`。

在题目的例子中，假如输入为`s = '324'`，我们的`NestedInteger`应该类似下面的`object`
```
NestedInteger {
    _integer: '324'
}
```
当输入为`s = "[123,[456,[789]]]"` ，我们的`NestedInteger`应该类似下面的`object`
```
NestedInteger {
    _integer: null,
    _list: [
        NestedInteger {
            _integer: '123'
        },
        NestedInteger {
            _list: [
                NestedInteger {
                    _integer: '456'
                },
                NestedInteger {
                    list: [
                        NestedInteger {
                            _integer: '789'
                        }
                    ]
                }
            ]
        }
    ]
}
```
当为单独的`integer`时, 我们需要用`NestedInteger.setInteger(integer)`方法，当为`list`时，我们需要用`NestedInteger.add(NestedInteger)`。

根据题意，及例子的结构，我们需要将字符串以中括号区分`object`，每一对中括号是单独的`NestedInteger`, 而逗号后的数字也是单独的`NestedInteger`，而且同一层的`NestedInteger`，以逗号分隔开。

根据这些特性我们可以用递归调用的方法来做，我们可以定义一个`process(str, start, end)`函数，其中`start`为当前`NestedInteger`的起点，`end`为终点。在每一层循环中:

 * 定义一个新的`NestedInteger object`
 * 判断第一个字符是否为'['，若为`[`，则此`NestedInteger`包含数组。若否，则包含单个的数字，可以用`setInteger`直接赋值。
 * 若为该`object`包含的是`NestedInteger object`，则从`start`开始遍历字符串，以同一层的逗号为区分，重复调用``process(str, start, end)`函数，获取`child NestedInteger object`。
 * 最后返回本层的`NestedInteger`。
 
### 完整题解
    执行用时 :100 ms, 在所有 javascript 提交中击败了100.00%的用户
    内存消耗 :46.5 MB, 在所有 javascript 提交中击败了100.00%的用户

其中需要注意的是，我们在解析`list`时，需要以逗号作为区分点，但要注意是否为同一层的逗号，例如`[123,[456,[789]]]`中，第一个逗号为第一个`list`的分割点，第二个逗号在第二个`list`中，我们可以用左右括号数量来区分，当左右括号数量相等时，我们遇到的是同一层的逗号，当左右括号不等式为下一层的逗号，不用处理。
```JavaScript
/**
 * @param {string} s
 * @return {NestedInteger}
 */
var deserialize = function(s) {
    /** 包含负数的正则表达式，用于截取数字 */
    const numberReg = new RegExp(/([\-0-9]*)/);

    const process = (str, start, end) => {
        const child = new NestedInteger();
        // 若本层的 NestedInteger 仅仅包含一个数字
        if (str[start] !== '[') {
            /** 用正则表达式截取起始位置开始的第一个数字 */
            const number = numberReg.exec(str.substr(start, str.length - start))[0];
            child.setInteger(number);
        } else {
            // 若本层包含一个list，则遍历 start+1 -> end - 1 的字符，将其分割成小的 object 继续递归
            let left = start + 1;
            // 以逗号为分割点，需要区分是否为同一层的逗号。
            // 当左括号、右括号之和为0时，遍历遇到的逗号为本层的逗号。
            let bracketsCount = 0;
            for (let i = left; i < end; i++) {
                // 记录左右括号之和
                if (str[i] === '[') {
                    bracketsCount++;
                } else if (str[i] === ']') {
                    bracketsCount--;
                }
                // 当遇到逗号且左右括号之和为0时，即为本层逗号。
                if (bracketsCount === 0 && str[i] === ',') {
                    child.add(process(str, left, i - 1));
                    left = i + 1;
                    continue;
                }
                // 当遍历到结尾时，将处理最后一个 object。
                if (i === end - 1) {
                    child.add(process(str, left, i));
                }
            }
        }
        return child;
    }
    return process(s, 0, s.length - 1);
};
```

最后，本地`debug`的时候，我们需要定义一个`NestedInteger`的`construction function`，否则本地运行会报错。
```JavaScript
var NestedInteger = function() {
    this._integer = null;
    this._list = [];
    this.setInteger = (integer) => {this._integer = integer};
    this.add = (item) => {this._list.push(item)};
}
```