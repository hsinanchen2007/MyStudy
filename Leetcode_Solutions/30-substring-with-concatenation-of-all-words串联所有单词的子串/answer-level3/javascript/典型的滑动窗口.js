### 解题思路
穷举法列出所有单词的全排列【未去重复项】，求从开始时用set作为结果集


动态窗口，0,n,2n,3n...慢慢拓展至words.length长度
超出时，左边收缩

辅助变量：**words的hash列表,s产生的hash列表**，count已统计个数

### 代码

```javascript
/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function (s, words) {
    var result = []
    if (words.length == 0) {
        return result
    }

    var all = words.length, step = words[0].length
    if (s.length < step) {
        return result
    }
    var map = {}//hash表
    for (let i = 0; i < words.length; i++) {
        const e = words[i];
        map[e] = map[e] == undefined ? 1 : map[e] + 1
    }
    var i = 0
    while (i < step) {
        var l = r = i, temp = {}, count = 0
        while (r + step <= s.length) {
            var str = s.substring(r, r + step)
            r += step
            if (words.indexOf(str) == -1) {
                count = 0
                l = r//从改位置重新开始
                temp = {}
            } else {
                temp[str] = temp[str] == undefined ? 1 : temp[str] + 1
                count++
                while (temp[str] > map[str]) {//滑动窗口最多只能all个
                    var new_str = s.substring(l, l + step)
                    count--
                    temp[new_str]--
                    l += step
                }
                if (count == all) {
                    result.push(l)
                }
            }
        }
        i++
    }
    return result
};
```
坑点：
给的例子只是普通测试用例
滑动最小单位是step，不是1，后面部分可以前面部分合体满足