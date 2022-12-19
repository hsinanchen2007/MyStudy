### 解题思路
- 通过 Array.from() 深拷贝一个数组
- 通过两遍 forEach 循环赋值 

### 代码

```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var transpose = function(A) {
    const B = Array.from({ length: A[0].length }, () => [])
    A.forEach((v) => {
        v.forEach((item, index) => {
            B[index].push(item)
        })
    })
    return B
};

```