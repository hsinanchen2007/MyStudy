根据题目，是要找出两数相加得到一个和目标值相同的数，我立刻就是想到了排序，使用选择排序可以很简单的实现这个程序

代码如下：

```
var twoSum = function(nums, target) {
        let arr = new Array(2);
        for(let i = 0; i < nums.length; i++){
            for(let j = i + 1; j <= nums.length - 1; j++){
                if(nums[i] + nums[j] === target){
                    arr[0] = i;
                    arr[1] = j;
                }
            }
        }
        return arr;
};
```



    