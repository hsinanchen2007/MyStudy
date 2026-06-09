### 解题思路
1 使用map结构存储左右括号的对应关系
2 使用一个数组作为一个后进先出的栈结构
3 遇到左括号的时候push进栈，遇到右括号的时候和数组最后一位对比，是最后一位对应的反括号则将数组删除最后一位，如果不是则说明不能封闭，返回false
4 循环结束后数组中还有值，则说明该左括号没有被封闭，返回false

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    if (s === '') return true;
    const mapData = new Map([
        ['(', ')'],
        ['{', '}'],
        ['[', ']'],
    ]);
    const arr = [s[0]];
    for (let i = 1; i < s.length; i++) {
        if (mapData.has(s[i])) {
            arr.push(s[i]);
        } else {
            if (mapData.get(arr[arr.length - 1]) === s[i]) {
                arr.pop()
            } else {
                return false;
            }
        }
    }
    return arr.length === 0;
};
```