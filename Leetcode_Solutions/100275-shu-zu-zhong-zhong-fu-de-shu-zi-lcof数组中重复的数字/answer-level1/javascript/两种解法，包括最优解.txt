### 解题思路
第一种解法：
只需要遍历一遍数组，时间复杂度O(n)
但是需要创建一个新的对象，空间复杂度也是o(n)
第二种解法：
更加优秀的空间复杂度为O(1)的解法
原理是，利用题目中长度为n的数组，所有数字都在 0～n-1 的范围内这个条件
如果没有重复数字，则在排序后，每个数字都会和下标相对应，所以只要找到和下标不对应的数字，就是重复数字
每个数字最多交换两次就能找到自己的位置，所以时间复杂度为o(n)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    let obj = {}
    for(let i of nums){
        if(obj[i]){
            return i
        }else{
            obj[i] = true
        }
    }
};
```

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    for(let i = 0;i<nums.length;i++){ //循环遍历数组
        while(nums[i] !== i){ //如果当前值m不等于当前下标i
            if(nums[nums[i]] !== nums[i]){ //判断当前当前值m与下标为m的值是否相同
                 //不相同就将当前值m与下标为m的值调换
                [nums[nums[i]],nums[i]] = [nums[i],nums[nums[i]]] //利用数组解构赋值，交换变量值
            }else{
                //如果相同，则为重复数字，输出该数字
                return nums[i]
            }
        }
    }
};
```