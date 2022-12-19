由题目知道：一定能达到数组的最后一个数字，所以：直接找到每一步能跃迁的最大位置```
代码块
var jump = function(nums) {
    let leftPos=0;//leftPos是当前出发点
    let i=0;
    let max=0;
    if(nums.length===1){
        return 0  
    }
    for(;nums[leftPos]+leftPos<nums.length-1;++i){
        let fPostion=nums[leftPos]+leftPos  //当前可以跳到的最远距离
        let j=leftPos+1
        for(;j<=fPostion;j++){
            if(max<j+nums[j]){
                max=j+nums[j];  //找到最大值点后将出发位置移到当前位置
                leftPos=j
            }
        }
        max=0
    }
    return i+1 //因为第一次跳跃没计算，所以加一次
};

