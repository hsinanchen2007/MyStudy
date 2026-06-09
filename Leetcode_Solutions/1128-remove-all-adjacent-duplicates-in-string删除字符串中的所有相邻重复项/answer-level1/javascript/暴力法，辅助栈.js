### 暴力法思路：每次遇到相邻的，先删除后，下标指针向前移动一步
```
var removeDuplicates = function(S) {
    let arr = S.split('');

    for (let i = 0; i < arr.length - 1;) {
        if (arr[i] == arr[i + 1]) {
            arr.splice(i, 2);
            if (i - 1 >= 0) i--;
        } else {
            i++;
        }
    }
    return arr.join('');
};

```
### 辅助栈思路：每次与栈顶元素比较，如果相同表示相邻且相等，然后pop出，最终栈内只存在相邻不想等字符
```
var removeDuplicates = function(S) {
    let stack = [];

    for (let i = 0; i < S.length; i++) {
        if (stack.length && stack[stack.length - 1] == S[i]) {
            stack.pop();
        } else {
            stack.push(S[i]);
        }
    }
    return stack.join('');
}
```

