### 解题思路
分三步
1. 先对数组进行长度递减排序
2. 依次验证是否符合条件，独一无二且不属于比他长的字符串子序列
3. 判断是否属于子序列的方法，使用计数法即可

### 代码

```javascript
var findLUSlength = function(strs) {
    strs.sort((a, b) => b.length - a.length);

    for (let i = 0; i < strs.length; i++) {
        if (help(strs, i)) {
            return strs[i].length;
        }
    }
    return -1;
};

function help(arr, k) {
    // 判断位置为k的字符是否独一无二，且不属于比他长的子序列
    let c = arr[k];
    let flag = arr.indexOf(c) == arr.lastIndexOf(c);

    for (let i = 0; i < k; i++) {
        if (valid(arr[i], c)) return false;
    }

    return flag;
}

function valid(a, b) {
    // 判断b是否是a的子序列
    if (a.indexOf(b) != -1) return true;

    let i = 0, j = 0;

    while (i < a.length) {
        if (a.charAt(i) == b.charAt(j)) {
            j++;

            if (j == b.length) return true;
        }
        i++;
    }
    return false;
}
```