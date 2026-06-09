### 解题思路

首先将B的所有元素全部替换进A（从A[m]开始替换。
考虑到如下测试用例：

[-1,0,1,1,0,0,0,0,0,0]
4
[-1,0,2,2,3]
5

这时替换完成后的A为[-1,0,1,1,-1,0,2,2,3,0]，因为A.length > m + n，所以替换完成后后面会多出来0，如果直接进行sort，那么后面的0也会排序到前面,不能通过。
所以先把最后的0 splice出来保存，排序完成后再逐一push进去。


### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
    let i = 0
    while(i < n) {
        A[m + i] = B[i]
        i ++
    }
    
    let spliceArr = A.splice(m+n)

    A.sort((a, b) => {
        return a - b
    })

    A.push(...spliceArr)
};


```