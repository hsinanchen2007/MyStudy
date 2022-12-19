
1.   let  A = ["cool","lock","cook"]
2.   使用reduce方法先后进行判断pre为第一个数组['c','o','o','l']，cur为当前遍历数组['l','o','c','k']
3.   返回有交集的数组arr = ['c','o','l'] 
4.   当reduce第二次执行回调函数的时候，pre的值就是上一个回调函数的返回值arr，也就是 ['c','o','l'] 
5.   重复第2，3，4 最后返回结果值。
6.   如果对您有帮助，还请点个赞，感谢！



```
/**
 * @param {string[]} A
 * @return {string[]}
 */
var commonChars = function (A) {
    // 将字符串转换成数组
    A = A.map(it => {
        return it.split('')
    })

    return A.reduce((pre, cur) => {
        let i = 0, arr = []
        while (pre && cur && i < pre.length) {
            let j = cur.indexOf(pre[i])
            if (~j) {
                arr.push(...cur.splice(j, 1))
            }
            i++
        }
        return arr
    })
};
```
