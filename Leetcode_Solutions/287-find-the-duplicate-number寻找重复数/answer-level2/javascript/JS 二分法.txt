### 解题思路
使用二分法思想
     长度为 n + 1的数组，只有1-n，的数字，说明这里面一定有重复的数字
     反推可以得到，有重复的数字的数组，数组值在 start-end 之间，那么其长度一定大于 end - start + 1 
         没有重复值的数组，数值在 start-end 之间，长度一定不大于 start - end + 1，
         
         用二分法思想
             middle = (end-start)/2 +start

             len 表示 数值在 start - middle 之间的项数，

                 若 len > middle - start + 1 的时候，
                    重复的数字一定在 start ~ middle 区间之内，
                         此时将 end 换为 middle

                 反之 一定不在
                     则重复的数字一定在，middle ~ end之间
                         此时将 start 换为 middle + 1
             


### 代码

```javascript
var findDuplicate = function(nums) {
    if(nums.length <= 0){
        return -1;
    }
    let end = nums.length - 1;
    let start = 1;
    let resultLen = 0;
    let result;
    while(end >= start){
        resultLen = 0;
        let middle = Math.floor((end-start)/2 + start);
        console.log(middle);
        for(let i = 0; i < nums.length; i++){
            if(nums[i] <= middle && nums[i] >= start){
                resultLen ++;
            }
        }
        if(resultLen > (middle - start + 1)){
            end = middle;
        }else{
            start = middle + 1;  
        }
        if(start == end){
            return start;
        }
    }
    return -1
};
```