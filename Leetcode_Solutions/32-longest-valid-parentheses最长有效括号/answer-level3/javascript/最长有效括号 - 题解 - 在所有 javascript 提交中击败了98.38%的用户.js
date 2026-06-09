### 思路

这一题与 [20 Valid Parentheses](https://leetcode-cn.com/problems/valid-parentheses) 的题目类似，只是本题在验证有效括号的基础上，要求找出字符串中最长的有效括号。

在验证有效括号的问题中，我们可以用与20题类似的方式，遍历的开始维护一个`stack`，用于存储未关闭的开括号`(`:

* 当遇到新的开括号`(`时，将其推入`stack`中
* 若遇到闭括号`)`:
    * 若`stack`中有未关闭的`(`，则将最仅的一个开括号推出，组成`pair`
    * 若`stack`中无开括号，则为至此为无效的括号。

在有了验证的方式后，我们需要考虑如何记录有效的括号的长度。我们可以在上面的方式的前提下，添加一步，在每次清空`stack`时，记录当前的新开始的`index`，然后并且记录直至无效时的有效长度:
```JavaScript
const open = '(', close = ')';
let queue = [];
let start = 0;
let max = 0;
for (let i = 0; i < s.length; i++) {
    if (s[i] === open) {
        stack.push(open);
    } else if (s[i] === close) {
        if (stack.length > 0) {
            stack.pop();
        } else {
            max = Math.max(i - start, max);
            start = i + 1;
        }
    }
}
// 遍历结束后记录剩余有效长度
max = Math.max(max, s.length - start);
```
这样我们可以在下面的几种情况下得到成功的结果:
```
')()())'
')()'
```
但是当遇到`(()`，我们计算的`max`却为3。原因是在遍历结束时，`stack`里仍然有未配对的`(`。例如`(()(`，在遍历完后`stack`中会剩下`['(', '(']`两个未配对的符号。这种情况下，有效字符的长度可能存在于：

* `s`的末尾至`stack`最后一个`(`之间, 如`(()`。
* `stack`的初始`index - start`至`stack`的第一个`(`之间，如`()(`。
* `stack`的未配对的`(`之间，如`(()()(`。

因此，我们可以在遍历中改为存储`index`，在最后根据以上的原则判断有效长度:
```JavaScript
const last = stack[stack.length - 1];
const first = stack[0];
max = Math.max(max, s.length - 1 - last, first - start);
for (let i = 0; i < stack.length - 1; i++) {
    max = Math.max(max, stack[i + 1] - stack[i] - 1);
}
```

### 完整题解
    执行用时 :64 ms, 在所有 javascript 提交中击败了98.38%的用户
    内存消耗 :36.1 MB, 在所有 javascript 提交中击败了65.71%的用户
```JavaScript []
var longestValidParentheses = function(s) {
    const open = '(', close = ')';
    let stack = [];
    let start = 0;
    let max = 0;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === open) {
            // stack 存储开括号
            stack.push(i);
        } else if (s[i] === close) {
            if (stack.length > 0) {
                // 遇到闭括号时，推出最后一个 ( 与之匹配
                stack.pop();
            } else {
                // 若 stack 为空，记录 start 至 i 的有效括号长度。
                max = Math.max(i - start, max);
                start = i + 1;
            }
        }
    }
    // 若 stack 中仍有未匹配的开括号，需要另外寻找其中的有效括号长度
    if (stack.length > 0) {
        const last = stack[stack.length - 1];
        const first = stack[0];
        // 检查起始及末尾的有效长度，即 start 至第一个未匹配的开括号的长度
        max = Math.max(max, s.length - 1 - last, first - start);
        // 检查开括号间的长度间隔。
        for (let i = 0; i < stack.length - 1; i++) {
            max = Math.max(max, stack[i + 1] - stack[i] - 1);
        }
    } else {
        // 若 stack 已经完全匹配完，则 s 从 start 至末尾一段为有效符号，记录其长度。
        max = Math.max(max, s.length - start);
    }

    return max;
};
```
