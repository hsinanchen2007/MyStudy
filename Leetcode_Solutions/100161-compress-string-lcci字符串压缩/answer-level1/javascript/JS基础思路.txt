### 解题思路
以二维数组的形式存储数据
子数组固定存储格式为[字符，累计数]，循环一遍后可以得到二维数组结构，再统一拼接即可

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let arr = []
    let key = ''
    for (let s of S) {
        if (key !== s) {
            key = s
            arr.push([key, 1])
        } else {
            arr[arr.length - 1][1]++
        }
    }
    let str = arr.map(item => item[0] + item[1]).join('');
    return str.length >= S.length ? S : str;
};
```