### 解题思路
此处撰写解题思路
尽量将损失降到最低，即min(a,b) a和b的差值要最小， 所以先给数组排序（由小到大），奇数位相加
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    let result = nums.sort((a,b)=>{
        return a-b
    }).filter((item,index)=>{
        return index%2 == 0
    }).reduce((a,b)=>{
        return a+b
    })
    return result
};
```