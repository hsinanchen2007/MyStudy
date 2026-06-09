`var moveZeroes = function(nums) {
    var count = 0
    for(var i=0; i<nums.length; ){
        if(nums[i] == 0){
            nums.splice(i,1)
            count++
        }else{
            ++i
        }
    }
    // 推进同个数的0进数组
    for(var k=0; k<count; k++){
        nums.push(0)
    }
};`
我卡在这里：不等于0再i+1，因为splice改变原数组，序号已变；否则会跳过去掉0后的一位。