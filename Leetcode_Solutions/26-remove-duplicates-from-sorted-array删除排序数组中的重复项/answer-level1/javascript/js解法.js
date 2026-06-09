var removeDuplicates = function(nums) {
    var temp = 0;
    for(var i=0;i<nums.length;i++) {
        temp = nums[i];
        for(var j=i+1;j<nums.length;j++) {
            if(nums[j] === temp) {
                nums.splice(j,1);
                //防止连续出现相同的数
                j--;
            }
        }
    }
    return nums.length;
};