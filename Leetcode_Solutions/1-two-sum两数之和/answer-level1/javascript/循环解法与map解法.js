### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    //通过两次循环遍历数组
    for(let i=0; i<nums.length-1; i++){
        //将每个值与其后面的值进行相加看是否等于target
        for(let j=i+1; j<nums.length; j++){
            //若等于目标值则返回
            if(nums[i]+nums[j]===target){
                return [i,j]
            }
        }
    }
    return null;
};

var twoSum = function(nums, target) {
    //创建map，将数组的值当作map的键；map的值为序号。
    let map = new Map();
    //利用循环往map中填充值
    for(let i=0; i<nums.length; i++){
        //如果目标值target减掉当前数组nums中的值，在map的键中没有出现，则填充map
        if(!map.has(target-nums[i])){//has方法是用来判断键的。
            map.set(nums[i],i);
        }else{//否则，返回当前数组的下标以及满足了条件的map中的值
            return [map.get(target-nums[i]),i];
        }
    }
    return null;
};
```