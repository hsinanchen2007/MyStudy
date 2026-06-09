### 题解一：回溯法
利用回溯的方式，在循环中尝试每一条可能的路径，如果能到字符的末端，则为可行的路径。在回溯函数中，设字符串为`str`，索引为`i`：

* 若`i > str.length - 1`, 抵达字符串的末端，为可行路径。
* 若`str[i] === '0'`, 无法从该字符出发抵达后面的字符，返回上一步。
* 若`str[i] !== '0'`, 
    * 从该字符抵达下一个字符，调用`backtrace(str, i + 1)`
    * 若`s[i] + s[i + 1] <= '26'`, 调用`backtrack(str, i + 2)`

思路较为直观，但是速度最慢: 执行用时 :3660 ms, 在所有 javascript 提交中击败了5.18%的用户
#### 回溯法题解
```javascript []
var numDecodings = function (s) {
    if (s.length <= 0) {
        return 0;
    }
    count = 0;

    const backtrack = (str, i) => {
        if (i > str.length - 1) {
            count++;
            return;
        }
        if (s[i] === '0') {
            return;
        }
        if (i + 1 <= str.length - 1 && s[i] + s[i + 1] <= '26') {
            backtrack(str, i + 2);
        }
        backtrack(str, i + 1);
    }

    backtrack(s, 0);
    return count;
};
```

### 题解二：动态规划
每一种路径的尝试的方法用时太长，我们需要考虑别的方式。在这里我们可以将本题想象成，寻找从字符串的起始抵达终点的路径数，其要求可以改为:

 * 寻找从起始到字符串末尾的路径数。
 * 若当前的字符为`1~9`之间，可以选择前进一步。
 * 若当前字符与下一字符相加在`10~26`之间，可以选择前进两步。

因为路径只能从左往右走，而且只能一次走两步或者一步，因此抵达每一位字符串的路径数，都是前面一位或前面两位的路径数之和。假设我们字符串为`str`，索引为`i`，记录路径数的数组为`path`，那么在`i`处的路径之和为:
``` javascript
path[i] = 0;
if (str[i - 1] !== '0') {
    path[i] += path[i - 1];
}
if (str[i-2] + str[i-1] <= '26') {
    path[i] += path[i - 2];
}
```
如果从头开始，即`i = 0`开始遍历，则可以改写成
``` javascript
if (str[i] >= '1' && str[i] <= '9') {
    path[i + 1] += path[i];
    if (str[i] + str[i + 1] <= '26') {
        path[i + 2] = path[i];
    }
}
```
在创建记录路径的数组时，因为最后一步可能是倒数两个字符，也可能是一个字符，为方便记录，我们创建一个字符串长度加一且位数都为的数组:
``` javascript
const path = [...new Array(str.length + 1)].map(() => 0);
```
#### 动态规划题解
    执行用时 :64 ms, 在所有 javascript 提交中击败了94.82%的用户
    内存消耗 :35.7 MB, 在所有 javascript 提交中击败了17.86%的用户
```javascript []
var numDecodings = function (str) {
    if (str.length <= 0) {
        return 0;
    }
    const path = [...new Array(str.length + 1)].map(() => 0);
    // 初始化起点路径数为1
    path[0] = 1;
    for (let i = 0; i < str.length; i++) {
        if (str[i] !== '0') {
            path[i + 1] += path[i];
            if (i + 2 < path.length && str[i] + str[i + 1] <= '26') {
                path[i + 2] = path[i];
            }
        }
    }
    return path[path.length - 1];
};
```

### 题解三：动态规划优化

在上面我们用数组来记录每一位的路径数，速度已经较快但是内存的消耗量排在`17.86%`。回顾上面的代码，我们发现其实我们在每一次循环中只用到了`path[i]`, `path[i + 1]` 和 `path[i + 2]`三个变量。因此我们可以用`current`,`next`和`next2`来代替这三个变量。于是可以将上面代码中记录`path`的部分改写成:
``` javascript
if (str[i] !== '0') {
    next += current;
    if (str[i] + str[i + 1] <= '26') {
        next2 = current;
    }
}
```
最后在下一个循环中，我们需要将`next`的值赋予现在的`current`，将`next2`的值赋予现在的`next`:
``` javascript
current = next;
next = next2;
```

#### 空间优化后动态规划题解
    执行用时 :60 ms, 在所有 javascript 提交中击败了96.89%的用户
    内存消耗 :33.8 MB, 在所有 javascript 提交中击败了82.14%的用户
```javascript []
var numDecodings = function (str) {
    if (str.length <= 0) {
        return 0;
    }
    let current = 1,
        next = 0;
    for (let i = 0; i < str.length; i++) {
        let next2 = 0;
        if (str[i] !== '0') {
            next += current;
            if (str[i] + str[i + 1] <= '26') {
                next2 = current;
            }
        }
        current = next;
        next = next2;
        if (current === '0') {
            break;
        }
    }
    return current;
};
```