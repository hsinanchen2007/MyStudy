

var singleNumber = function(nums) {
    let gg = function(total,num){
        return total ^ num;
    }
    return nums.reduce(gg);
};