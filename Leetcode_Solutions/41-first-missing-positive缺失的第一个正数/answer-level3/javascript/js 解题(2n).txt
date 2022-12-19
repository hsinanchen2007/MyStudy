最快48ms，优化后代码变少了,时间和内存消耗多了一点
var firstMissingPositive = function(nums) {
    let arr=[]
    for(let i=nums.length;i--;){
      if(nums[i]>0)arr[nums[i]]=true
    }
    if(!arr[1])return 1
    let len=arr.length
    for(let i=2;i<len;i++){
        if(!arr[i]){
            return i
        }
    }
    return len
};