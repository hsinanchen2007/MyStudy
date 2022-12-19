### 解题思路
判断两字符串长度
为 -1; 即 删除操作
为  0; 即 替换操作
为 +1; 即 删除操作

因为能成功的两字符串只差一个字符
所以我们可以同时循环字符串 first 和 second
当 first[i] 与 second[j] 不想等时
若 -1; 即删除操作, i下标右移,    则剩余字符串应相等
若  0; 即替换操作, i, j下标右移, 则剩余字符串应相等
若 +1; 即添加操作, j下标右移,    则剩余字符串应相等

当修改次数 modify 为1 即满足题意 为0 则可以认为任意字符替换为该字符 即可

### 代码

```javascript
/**
 * @param {string} first
 * @param {string} second
 * @return {boolean}
 */
var oneEditAway = function(first, second) {
    const diff = first.length - second.length;
    if(diff > 1 || diff < -1) return false;

    let i=0;
    let j=0;
    let modify = 0;
    const len1 = first.length;
    const len2 = second.length;
    while(i<len1 && j<len2) {
        if(first[i] === second[j]) {
            i++;
            j++;
            continue;
        }

        if(diff === 1) {
            // Insert
            i++;
            modify++;
            continue;
        }
        if(diff === 0) {
            // Replace
            i++;
            j++;
            modify++;
            continue;
        }
        if(diff === -1) {
            // Remove
            j++;
            modify++;
            continue;
        }
    }
    return modify <= 1;
};
```