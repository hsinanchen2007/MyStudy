### 解题思路
充分利用了js数组的方法 滑稽
arr.sort方法就是排序 a-b代表升序
之后arr.splice从开始也就是最小值返回指定长度的数组就行 芜湖
内存消耗是100%滴
### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    arr.sort((a,b)=>a-b)
    return arr.splice(0,k)
};
```