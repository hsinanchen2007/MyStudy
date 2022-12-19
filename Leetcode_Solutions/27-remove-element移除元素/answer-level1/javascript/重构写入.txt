### 解题思路
此处撰写解题思路
定义一个变量直接 判断时候等于val 不等与直接赋值给 nums
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {

    let sum=0
 for(let i=0;i<nums.length;i++){
     if(nums [i]!==val){
       nums [sum]=nums [i]
        sum++
     }
 }
 return sum
};
```