### 解题思路
从小到大排序，取前k位

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */

// 解法三： 试试快排..
var getLeastNumbers = function(arr, k) {
    return quickSort(arr).splice(0, k)
}
function quickSort(arr) {
    if( arr.length <= 1) return arr
    const [pivot] = arr.splice( Math.floor( arr.length/2 ), 1 ) 
    let left = [], right=[]
    for( let i=0;i<arr.length; i++ ){
        if( arr[i] < pivot ){
            left.push(arr[i])
        }else{
            right.push(arr[i])
        }
    }
    return quickSort(left).concat([pivot], quickSort(right))
}


// 解法二： 冒泡果然慢。。哈哈哈 --- 击败了5.15%的用户
// var getLeastNumbers = function(arr, k) {
//     for(let i = 0; i<arr.length; i++){
//         for(let j = 0; j <arr.length - i - 1; j++){
//             if( arr[j] > arr[j+1]){
//                 [arr[j],arr[j+1]] = [arr[j+1], arr[j]]
//             }
//         }
//     }
//     let result = []
//     for(let i=0;i<k;i++){
//         result.push(arr[i])
//     }
//     return result
// };

// 解法一： 内置函数真香 
// var getLeastNumbers = function(arr, k) {
//     arr = arr.sort( (a,b)=> a-b )
//     return arr.splice(0,k)
// };
```