### 解题思路
我是一开始接触算法的，本能的一下就想到了for循环，但是又觉得比较垃圾，说一下我的思路吧
首先是两数之和，两数之和就是i+j，就是两层循环，但是i和j的下标又不能一样，所以这里要判断，
最后给了总和。只要知道其中一个，算出另一个就可以
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for(var i = 0;i<nums.length;i++){
        for(j=0;j<nums.length;j++)
        {
            if(i==j) {j=j+1}
             if(nums[j]== target-nums[i])
             {
                 return [i,j]
             }
        }
    }
};
```