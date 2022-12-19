### 解题思路
1. 将字符串按空格分割单词;
2. 两个指针，一个正向遍历，一个反向遍历

注意：按空格分割可能存在多个空格连在一起，通过正则匹配多个空格

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let sarr = s.trim().split(/\s+/);
    let i = 0,
        j = sarr.length-1;
    
    for ( ;i<=j; i++, j--) {
        let tmp = sarr[i];
        sarr[i] = sarr[j];
        sarr[j] = tmp;
    }

    return sarr.join(' ');
};
```