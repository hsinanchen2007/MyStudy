### 解题思路
这道题目我是直接使用二维数组来实现的，代码中i来控制nums中的那一个数和其他的数相加减，j控制nums进行遍历。
题目比较简单，但是解法应该很多。
我看到了这道题有哈希表的标签。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for(let i = 0 ; i < nums.length ; i++){
        for(let j = i + 1 ; j < nums.length; j++){
            if(nums[i] + nums[j] === target){
                return [i,j]
            }
        }
    }
};

```
