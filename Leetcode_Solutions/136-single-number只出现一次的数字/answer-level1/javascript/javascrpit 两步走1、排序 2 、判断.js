var singleNumber = function(nums) {
    //从小到大排序
    nums.sort((a,b)=>{
        return a-b;
    });
    for(let index =0;index<nums.length;index++){
        //第一个 就是
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        //最后一个 是
        if(nums[nums.length-1]!=nums[nums.length-2]){
            return nums[nums.length-1];
        }
        //结果在中间 它应该和前后的不一样
        if(index!=0 && index !=(nums.length-1)){
            if(nums[index]!=nums[index+1] 
                &&nums[index]!=nums[index-1] ){
                    return nums[index];
            }
        }
    }
};