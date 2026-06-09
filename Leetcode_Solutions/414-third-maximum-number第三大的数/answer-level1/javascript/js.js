### 解题思路
此处撰写解题思路
小白第一次做题解，没啥说的，算法很菜，写着玩玩
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function(nums) {
    nums.sort((a,b)=>(b-a));
    for(let i=0;i<nums.length;i++){
        for(let j=i+1;j<nums.length;j++){
            if(nums[i]===nums[j]){
                nums.splice(i,1)
                j--
            }
        }
    }
    if(nums.length<3){
        return nums[0];
    }else{    
        return nums[2]
    }
};
```