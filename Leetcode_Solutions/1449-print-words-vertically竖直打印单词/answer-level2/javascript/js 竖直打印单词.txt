![image.png](https://pic.leetcode-cn.com/29363b7e859941696b13bde96af24eb7650bfeed28e0a4975650972ebd6f03c8-image.png)

继续……暴力，短时间内还感受不了程序之美……
正则去除尾部空格

```
/**
 * @param {string} s
 * @return {string[]}
 */
var printVertically = function(s) {
    let arr = s.split(' ')
    let maxLen = 0
    for(let i of arr) {
        if (i.length > maxLen) {
            maxLen = i.length
        }
    }
    let list = new Array(maxLen).fill('')
    for(let i = 0; i < maxLen; i++) {
        for(let j = 0; j < arr.length; j++) {
            list[i] += arr[j][i] || ' '
        }
    }
    list = list.map((i) => {
        return i.replace(/\s*$/g, '')
    })
    return list
};
```
