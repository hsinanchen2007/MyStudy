### 解题思路

先把 没有在arr2 的元素 分离出来,排序

然后循环arr2, 这样就可以按照arr2的排序 进行 排序了


### 代码

```javascript
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
    let footerList = arr1.filter(t => !arr2.includes(t)).sort((a,b) => a - b)

    let list = []
    arr2.forEach(item => {
      while(arr1.indexOf(item) > -1){
        let index = arr1.indexOf(item)
        list.push(arr1[index])
        arr1.splice(index,1)
      }
    })
    return list.concat(footerList)
};
```