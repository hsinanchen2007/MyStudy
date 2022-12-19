```
var dominantIndex = function(nums) {
    var index = 0;
    var firstMax = 0;
    var secondMax = 0;
    for(var i = 0; i < nums.length; i++){

        if(nums[i] > firstMax) {
            index = i;
            secondMax = firstMax;
            firstMax = nums[i];
        }else if(nums[i] > secondMax){
            secondMax = nums[i];
        }

    }
    if(firstMax >= 2*secondMax){
        return index;
    }else{
        return -1;
    }
};
```
