### 解题思路
将输入的数组扁平化 然后根据输入项中每项的长度求余赋值  就是结果不太好看。。

### 代码

```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var transpose = function(A) {
    let flatArr = A.toString().split(',').map(item => parseInt(item))
    let len = A[0].length
    let re = Array(len).fill(Array())
    flatArr.forEach((item, index) => {
        let reIndex = index % len
        re[reIndex] = [...re[reIndex], item]
    })
    return re
};
```