### 解题思路
假设全部都满足条件，循环遍历数组1，然后与在数组2查找不满足条件的,减去不满足条件的数量
### 代码

```javascript
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @param {number} d
 * @return {number}
 */
var findTheDistanceValue = function(arr1, arr2, d) {
    var result = arr1.length;
    var flag = 0;
    arr1.forEach(item=>{
        flag = arr2.findIndex(i=>{
            return Math.abs(item-i)<=d
        })
        if(flag!=-1){
            result--
        }
    })
    return result
};
```