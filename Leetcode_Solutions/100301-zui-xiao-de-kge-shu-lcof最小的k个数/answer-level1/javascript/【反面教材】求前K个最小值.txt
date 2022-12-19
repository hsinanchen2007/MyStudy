### 解题思路
上一次的解法是对整个数组进行排序并切片，但是算法的时间复杂度是nlogn
此次我打算对固定的k个元素进行排序，每次与k个元素中最大的元素进行排序，如果比最大的元素大，那么我将此最大元素从我的结果中剔除，并将当前元素插入到合适的位置。
这里我是使用list+sort的方式来维护的前K个有序元素
这种方式的时间复杂度其实是O(n)的，虽然我使用了排序，但是是对固定元素进行排序，所以排序阶段的时间复杂度是O(1)的，所以整体的时间复杂度是O(n)。
然后这个结果的执行用时反而还没有之前的好。

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    //开辟出k个元素的数组用于存放结果
    //取出前K个数，并进行排序
    let temp=arr.slice(0,k)
    temp.sort((x,y)=>x-y)
    arr.slice(k).forEach(i=>{
        if(i<temp[k-1]){
            //最大的数出来
            temp.pop()
            //将当前数字放入到合适的位置
            temp.push(i)
            temp.sort((x,y)=>x-y)
        }
    })
    return temp
};
```