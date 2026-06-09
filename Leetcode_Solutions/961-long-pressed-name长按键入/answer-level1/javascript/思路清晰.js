### 解题思路
直接看代码吧

### 代码

```javascript
var isLongPressedName = function(name, typed) {
    let i = 0, j = 0, len = typed.length, n = name.length;

    while(i < n) {
        let cur = name[i], count = 1, k = i + 1;

        while(k < n && name[k] == cur) {
            k++;
            count++; // 记录当前字符的连续个数
        }
        i = k;

        let p = 0;
        while(j < len) {
            if (typed[j] == cur) {
                j++;
                p++;
                if (j == len && i < n) return false; // 如果typed遍历结束时候，name还没结束，则返回false
            } else {
                if (p < count) {
                    return false; // 如果typed中该字符的个数小于name中出现的个数，返回false
                }
                break;
            }
        }
    }
    return true;
};
```