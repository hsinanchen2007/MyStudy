var singleNumber = function(nums) {
    let sortNums = nums.sort()
    for(var i =0;i< sortNums.length;i++){
        if(sortNums[i] !== sortNums[i+2]){
            return sortNums[i]
        }else{
            i+=2
        }
    }
}