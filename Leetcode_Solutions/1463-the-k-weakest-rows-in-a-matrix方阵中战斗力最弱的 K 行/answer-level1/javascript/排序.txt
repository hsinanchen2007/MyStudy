### 解题思路
此题最大的难点是如何将某一行中数字“1”的个数，进行排序，map对象key=>value是可以很清楚转换其相对之间的关系，
map对象也可以针对value进行单独排序，只要写两行代码转换就行
```
let arrObj = Array.from(map)
arrObj.sort((a,b)=>a[1]-b[1])
```
其中a[1]、b[1]代表map中的value值，如果是要根据key值进行排序，代码为：
```
arrObj.sort((a,b)=>a[0]-b[0])
```
**于是代码如下**
```
var kWeakestRows = function(mat, k) {
    let m = mat.length
    let map = new Map()
    for(let i=0;i<m;i++){
        let n = mat[0].length
        for(let j=0;j<=n;j++){
            if(!mat[i][j]){
                map.set(i,j)
                break
            }
        }
    }
    let arrObj = Array.from(map)
    arrObj.sort((a,b)=>a[1]-b[1])
    const arr = arrObj.map(item=>item[0])
    arr.splice(k)
    return arr
};
```
**本以为完美无缺，可却在一个测试用例处出现了错误**
![123.png](https://pic.leetcode-cn.com/b92fc42a67b93b0035fd900c3ec946b7d4133603655aa554e3b87aaa3db63a8f-123.png)

**很奇怪的是，我在自己浏览器上调试了好几次，是正确的**
![456.png](https://pic.leetcode-cn.com/df70d2ca49044104ab219cafae6b81803203de6f1017f8e4d9475b837742d291-456.png)

**不知道是不是leecode测试用例的bug，无奈之下，只得硬加一个判断**
```
    arrObj.sort(
        (a,b)=>{
                if(a[1]===b[1]){
                    return a[0]-b[0]
                } else {
                    return a[1]-b[1]
                }
            })
```
**才测试通过，虽然我觉得真的不需要(⊙o⊙)…，一下子性能差了好多**

### 代码

```javascript
/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[]}
 */
var kWeakestRows = function(mat, k) {
    let m = mat.length
    let map = new Map()
    for(let i=0;i<m;i++){
        let n = mat[0].length
        for(let j=0;j<=n;j++){
            if(!mat[i][j]){
                map.set(i,j)
                break
            }
        }
    }
    let arrObj = Array.from(map)
    arrObj.sort(
        (a,b)=>{
                if(a[1]===b[1]){
                    return a[0]-b[0]
                } else {
                    return a[1]-b[1]
                }
            })
    const arr = arrObj.map(item=>item[0])
    arr.splice(k)
    return arr
};
```
**昨天陷入死胡同了，其实直接用二维数组也可以，就不需要多一步将map转换为数组的过程了**


```
var kWeakestRows = function(mat, k) {
    let m = mat.length
    let arrObj = []
    for(let i=0;i<m;i++){
        let n = mat[0].length
        for(let j=0;j<=n;j++){
            if(!mat[i][j]){
                arrObj.push([i,j])
                break
            }
        }
    }
    arrObj.sort(
    (a,b)=>{
            if(a[1]===b[1]){
                return a[0]-b[0]
            } else {
                return a[1]-b[1]
            }
        })
    const arr = arrObj.map(item=>item[0])
    arr.splice(k)
    return arr
```

只是不知道为什么时间复杂度更高了。。。