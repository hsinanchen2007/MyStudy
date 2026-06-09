### 解题思路
求出target的平均值，向两边遍历，遍历一遍就可得出结果

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    //nums已经排序了，二分法
    let avg= target/2;
    let j;//接近avg的索引下标
    for(let i = 0; i< nums.length; i++){
        if(avg >= nums[i]){
            j=i;
            break;
        }
    }
    let left=j;
    for(let right=j;right<nums.length;right++){
        let x = target - nums[right];
        while(left>=0 && nums[left] > x){
            left--;
        }
        if(left < 0)break;
        if(nums[left] === x && left!==right)return [nums[left],nums[right]];
        left++;
    }
    return [];
};
```