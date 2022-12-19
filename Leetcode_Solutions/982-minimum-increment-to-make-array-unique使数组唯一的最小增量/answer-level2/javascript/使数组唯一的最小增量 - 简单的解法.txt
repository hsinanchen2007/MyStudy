### 解题思路
先排序，根据数组起止下标判断数字是否重复。若重复，则其他数++

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */

/**
 * 解法三：
 * 对解法二稍作优化... 终于过了， hhh
 * 执行用时 :9596 ms, 在所有 JavaScript 提交中击败了6.90%的用户
 */
var minIncrementForUnique = function(A) {
    A = A.sort((a,b)=>a-b)
    let n = 0
    for( let i=0; i<A.length;i++){
        let s = A.indexOf(A[i])
        let e = A.lastIndexOf(A[i])
        n += e-s
        while( s != e ){
            s++
            A[s]++
        }
    }
    return n
}
/**
 * 解法二：
 * 靠。。。挂在 57组
 * 先排序，根据数组起止下标判断数字是否重复。若重复，则其他数++ ==> n++
 */
// var minIncrementForUnique = function(A) {
//     A = A.sort((a,b)=>a-b)
//     let n = 0
//     for( let i=0; i<A.length;i++){
//         let s = A.indexOf(A[i])
//         let e = A.lastIndexOf(A[i])
//         while( s != e ){
//             n++
//             A[s+1]++
//             s++
//         }
//     }
//     return n
// }


/**
 * 解法一：
 * 暴力又双叒超时... （第54组）
 */
// var minIncrementForUnique = function(A) {
//     let n = 0;
//     for( let i=0; i<A.length; i++ ){
//         let temp = A[i]
//         if( A.filter(item=> item == temp ).length > 1 ){
//             while( ~A.indexOf(temp) ){
//                 temp++
//                 n++
//             }
//             A[i] = temp
//         }
//     }
//     return n
// };
```