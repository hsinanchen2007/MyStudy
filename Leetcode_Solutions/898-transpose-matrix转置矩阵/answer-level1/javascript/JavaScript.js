```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var transpose = function(A) {
    const rotateArr = Array.from({ length: A[0].length }, () => [])
    A.forEach((v) => {
        v.forEach((item, idx) => {
            rotateArr[idx].push(item)
        })
    })
    return rotateArr
};
```
![TIM截图20191114110831.png](https://pic.leetcode-cn.com/1acd9e1f94fb59ed2b16db641cd95c551952861793a79055a10cd977e1c88fb9-TIM%E6%88%AA%E5%9B%BE20191114110831.png)
