### 解题思路
![T`Q5@HQF{B`()KQSFM1XV5C.png](https://pic.leetcode-cn.com/a80b968e2486c4f989c2727d1583d0fc9b03254d559218967a7957c3b334c66c-T%60Q5@HQF%7BB%60\(\)KQSFM1XV5C.png)

用栈的后进先出，使用Array来模拟栈
(())
"("时入栈，")"时出栈
结果只要计算栈的深度就行了
1,
(
[(],入栈，深度0
2,
[((],入栈，深度1
3,
[(],出栈，深度1
4,
[],出栈，深度0

有一说一，这题目翻译的机翻都比这好
### 代码

```javascript
/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function (seq) {
    let List = [];
    return seq.split("").map((value, index) => {
        if (value === "(") {
            List.push(value);
            return (List.length - 1) % 2;
        } else {
            List.pop();
            return List.length % 2
        }
    });
};
```