### 解题思路
非递减就是从小到大或者允许中间有相等的情形,  照相排队第一印象就想是中间高,两边低, 然后又想,没说是一行的, 估计是说按一排一排的高度, 矮的一排在前面,高的在后面

实际上就是数组排序问题呗,按升序用sort重排一下数组,然后对比前后的数组中,有多少个变动的.
### 代码

```javascript
/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function(heights) {
    let init = [...heights]
    let list = heights.sort((n,m)=>n-m)
    let nums = 0
    list.forEach((item,index)=>{
      if(item != init[index]){
        ++nums
      }
    })
    return nums
};
```