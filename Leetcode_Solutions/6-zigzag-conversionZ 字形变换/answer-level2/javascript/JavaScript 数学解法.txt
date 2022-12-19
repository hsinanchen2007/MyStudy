### 解题思路
时间：92ms
内存：40.1MB
![image.png](https://pic.leetcode-cn.com/a974e3da0059364daf9645f5942f19356f31c0598460b9fd3ebcf57ea645187b-image.png)

本题思路是找到其中数学规律，计算出每个元素所在行数，则很容易可以得到最后的结果
我们可以将整个Z型字符串分组，每组的第一个元素是行数为0的元素，最后一个元素是下一个行数为0的前一个元素

举例：
L   | C   | I   | R
E T | O E | S I | I G
E   | D   | H   | N

这是一个3行的Z型字符串，每组为4个

又例：
L     | D     | R
E   O | E   I | I
E C   | I H   | N
T     | S     | G

这是一个4行的Z型字符串，每组为6个

那么可以判断出，当行数+1时，每组左边竖直列会+1个元素，右边斜向上列会+1个元素，可得每+1行数，一组就会多两个元素
则：`const group = 2 * (numRows - 1)`

有了一组的个数，接下来判断每个元素的行数
先求得当前元素在当前组的序号，也就是简单的用当前元素的位置对每组个数取余
设当前元素在整个完整字符串的位置为i
即：`const remainder = i % group`

观察可得，当元素在左边竖直列时，也就是当上面求得的余数小于行数常量时，当前行数即等于余数
当余数大等于行数常量时，当前行数等于行数常量减去余数和行数加一的差再加一
用数学公式表示为：`numRows - (remainder - numRows + 1) - 1`
`remainder - numRows + 1` 表示是从左下往右上数第几个元素，+1 是因为 remainder 从0开始计，而 numRows 从1开始计，两者计数方式需相同。
有了左下往右上的序号数，就可以将行数常量减去刚刚求得的序号，也就是`numRows - (remainder - numRows + 1)`，求得当前行数。
再-1是因为刚刚算出的行数是从1开始计数，而为了取数方便，我们需要从0开始计，则可得计数公式`numRows - (remainder - numRows + 1) - 1`

有了每个元素的行数，就可以判断 strArr 数组中是否有当前行数对应的元素。例如我计算出当前行数为2，我需要找到 strArr[2] 元素是否存在，如果不存在则构造一个新的字符串，将当前元素填充进字符串，放进 strArr[2] 中。如果存在，则取出 strArr[2] 的字符串，将当前元素添加到字符串末尾，并写会 strArr[2]。

最后，遍历 strArr 数组，将所有字符串拼接在一起，则可得最后的结果。

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    // 判断如果长度为1，则直接返回
    if (numRows === 1) {
        return s
    }
    // 算出一组有几个数
    const group = 2 * (numRows - 1)
    const strArr = []
    // 遍历字符串，从第0行开始按照行数填充进上面 strArr 对应的节点，例如这个字符在第0行，则填充进 strArr 数组的第0个元素字符串中
    for (let i = 0; i < s.length; i++) {
        const remainder = i % group // 取余数，判断是该组中的第几个数

        // 根据一组有几个数，这个是该组中的第几个来判断该元素在第几行
        const row = remainder < numRows ? remainder : numRows - (remainder - numRows + 1) - 1

        // 判断目标位置有没有元素，没有就新建一个
        let rowStr = strArr[row] !== undefined ? strArr[row] : ''
        rowStr += s.charAt(i)
        strArr[row] = rowStr
    }
    let out = ''
    strArr.map(item => {
        out += item
    })
    return out
};
```