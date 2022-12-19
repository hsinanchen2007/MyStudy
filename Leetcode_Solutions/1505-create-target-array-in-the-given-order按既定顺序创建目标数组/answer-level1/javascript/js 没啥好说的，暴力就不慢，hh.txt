![image.png](https://pic.leetcode-cn.com/d075eda80c7fff2a73544518cee438b9dddcafb50a6f089ff9eaf5d35b5455ff-image.png)

### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number[]} index
 * @return {number[]}
 */
var createTargetArray = function(nums, index) {
  let arr = [];
  
  for (let i = 0; i < index.length; i++) {
    let inx = index[i], val = nums[ i ];
    arr.splice(inx, 0, val);
  }
  
  return arr;
};
```