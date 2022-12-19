```js
var findMedianSortedArrays = function(nums1, nums2) {
    const quickSort = (array = []) => {
        if (array.length < 2) {
            return array
        }

        // 基准点
        const pivot = array[0]

        // 分割成大于和小于基准点的两个数组
        const smallerList = array.slice(1).filter(item => item < pivot || item === pivot)
        const biggerList = array.slice(1).filter(item => item > pivot)

        // 递归调用
        return [...quickSort(smallerList), pivot, ...quickSort(biggerList)]
    }
    
    let newArr = [...nums1,...nums2]
    newArr = quickSort(newArr)
    const {length} = newArr
    const half = (+length) / 2
    
    return length % 2 
    ? (newArr[Math.floor(half)])
    : +(newArr[half-1] + +newArr[half])/2
};
```
