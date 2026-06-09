### 解题思路
1.直接使用数组的sort的方式进行完成，核心在于先排序，然后在取值

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    let minArrs=[]
    arr.sort(function(a, b){return a - b})
    // 排序成5,4,3,2,1
    // console.log(arr)
    minArrs = arr.splice(0,k)
    // arr.forEach(item=>{
    //     minArrs.push(item)
    //     minArrs.sort(function(a, b){return b - a})
        // if(minArrs.length === 0) {
        //     minArrs.push(item)
        // } else{
        //     // 默认第一个是最小的
        //     if(item <= minArrs[0]) {
        //         minArrs.unshift(item)
        //     } else{
        //         if(item < minArrs[minArrs.length-1]) {
        //             // 排序
        //             let low = 1,high = arr.length - 1;
        //             var mid = Math.floor((low + high) / 2);
        //             if (minArrs[mid] === item) {
        //                 // 进行排序
        //                 minArrs.splice(mid, 0, item);
        //                 return arr;
        //             } else if(item > minArrs[mid]) {
        //                if(item<=minArrs[min+1]) {
        //                     minArrs.splice(mid+1, 0, item);
        //                } else{
                            
        //                }
        //             } else{
        //                 if(item > minArrs[mid-1]) {
                            
        //                 } else{

        //                 }
        //             }
        //             minArrs = sort(minArrs, item)
        //         } else{
        //             minArrs.push(item)
        //         }
        //     }
        // }
        // 超出进行截断最后一位
    //     if(minArrs.length > k) {
    //         minArrs.shift()
    //     }
    // })
    return minArrs
};
// 1,3,5,6,7
function sort(arr,item) {
    let low = 1,high = arr.length - 1;

    while (low <= high) {
        var mid = Math.floor((low + high) / 2);
        
        if (arr[mid] === item || item) {
            // 进行排序
            arr.splice(mid, 0, item);
            return arr;
        }
        if (target > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid -1;
        }
    }
    return arr
}
```