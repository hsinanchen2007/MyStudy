![QQ截图20200126204407.png](https://pic.leetcode-cn.com/d38db106b315f415b73f37f5972de96d89e36d8262bfd6e34e182c464a9be069-QQ%E6%88%AA%E5%9B%BE20200126204407.png)

### 解题思路
由于位运算符异或运算的特点，即两个相同的数进行异或运算时，其结果为0，所以当将数组中所有的元素进行异或运算时，其结果必定为那个唯一的数。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
    var singleNumber = function(nums) {
       let result = 0
       nums.forEach(item=>{
        result = item ^ result
       })
       return result
    };
```