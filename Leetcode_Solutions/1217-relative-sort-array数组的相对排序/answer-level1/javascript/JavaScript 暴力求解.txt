### 解题思路
![image.png](https://pic.leetcode-cn.com/e646e5262af7fafb52aea0c315e5e609102867e05657ff6f6fcf5249095f1fdc-image.png)
- 两次遍历 如果在 arr2 数组中发现 arr1 的元素，则与前面的位置进行交换
- 最后通过将排序好的数组 和 不在 arr2的剩下部分进行排序 ，最后concat拼接在一起

### 代码

```javascript
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
    let lastIdx = 0
    for(let i = 0; i < arr2.length; i++){
        for(let j = 0; j < arr1.length; j++){
            if(arr1[j] ==  arr2[i]){
                [arr1[lastIdx], arr1[j]] = [arr1[j], arr1[lastIdx]]
                lastIdx++
            }
        }
    }
    let arr = arr1.slice(lastIdx).sort((a,b) => a -b)
        return arr1.splice(0,lastIdx).concat(arr)

};
```