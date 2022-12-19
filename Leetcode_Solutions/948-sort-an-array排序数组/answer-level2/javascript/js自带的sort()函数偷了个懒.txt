### 解题思路

利用js自带的sort（）排序函数偷了个懒
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    return nums.sort(function(a,b){
        return a-b;
    });
};
```