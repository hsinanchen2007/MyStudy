### 解题思路

 * 对字符串数组list，去重，并且按照长度从大到小排序
 * 辅助函数，包含，检测a，是否包含b
 * 计算默认的最大长度n，遍历数组list，如果能被已有的元素包含，则n - l + 1

### 代码

```javascript
/**
 * 对字符串数组list，去重，并且按照长度从大到小排序
 * 辅助函数，包含，检测a，是否包含b
 * 计算最大长度n，遍历数组list，如果能被已有的元素包含，则n - l + 1
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function (words) {
    //去重
    let list = [...new Set(words)];
    //从长到短排序
    list.sort((a, b) => b.length - a.length);

    //总长度
    let res = 0;
    for(let e of list) {
        res += e.length + 1;
    }

    //判断是否能被压缩
    for(let i = 0; i < list.length; i++) {
        let canInclude = false;
        testInclude: for(let j = i - 1; j >= 0; j--) {
            canInclude = include(list[j], list[i]);
            if(canInclude) {
                //n - l + 1
                res -= list[i].length + 1;
                break testInclude;
            }
        }
    }

    return res;

};

/**
 * if a include b
 * b.length <= a.length
 * @param {string} a 
 * @param {string} b 
 */
function include(a, b) {
    //undefined
    if(!a) return false;

    const blen = b.length;
    const alen = a.length;
    for(let i = 0; i < blen; i++) {
        if(b[blen - i - 1] !== a[alen - i - 1]) return false;
    }

    return true;
}
```