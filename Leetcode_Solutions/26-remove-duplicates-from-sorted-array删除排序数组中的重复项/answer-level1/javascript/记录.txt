### 解题思路
方法一：
遍历时进行数组查找，如果不是该元素第一次出现，则删掉这个元素，同时，因为删掉后，数组元素减少，查找下标往前移一位。
该方法进行了两边查询，但可以适用于无序数组

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    for(let i=0; i<nums.length; i++){
        if(nums.indexOf(nums[i],0) !== i){
            nums.splice(i,1)
            i--;
        }
    }  
};
```


### 解题思路
方法二：
参考官方的标准解法进行改动，考虑到实际应用中，无序排序情况，就在遍历之前进行一次数组排序，
在最后的时候，截断多余的数组元素，实现去重

### 代码

```javascript
var removeDuplicates = function(nums) {
    // nums.sort();    //考虑无需排序加一个排序

    let i = 0;
    for(let k=1; k<nums.length; k++){
        if(nums[i] !== nums[k]){
            i++;
            nums[i] = nums[k]
        }
    }

    nums.length = i+1;
    return i+1  
};
```