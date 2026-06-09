var maxSubArray = function(nums) {
    let sum = 0,maxNum =Number.MIN_SAFE_INTEGER;
    for(let i=0;i<nums.length;i++){
        sum+=nums[i];
        if(sum>0){
            maxNum = Math.max(sum,maxNum);
        }else{
            sum = 0;
            maxNum = Math.max(maxNum,nums[i]);//当数组的所有数据均小于等于0时
        }
    }
    return maxNum;
};

整体思路为：
    只要当前子数组相加之和大于0就继续相加，小于0则令sum=0,重新计算。