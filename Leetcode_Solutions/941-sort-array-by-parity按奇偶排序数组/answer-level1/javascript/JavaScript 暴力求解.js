### 解题思路
- 通过 Javascript 中的数组的 filter（）方法进行遍历，返回指定类型；
- 然后通过 concat（） 方法进行将偶数数组和奇数数组进行拼接；

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function(A) {
    let arr1 = []
    let arr2 = []
    arr1 = A.filter( item => item % 2 == 0)
    arr2 = A.filter(item => item % 2 != 0)
    return arr1.concat(arr2)
};
```