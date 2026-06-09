解题思路：1.将不同的放在最前面，相同的不管。
        2.需要一个指向当前数组位置的i，和一个不停往后遍历的j，
        3.i成功找到不同的时候，变动。j一直不用的往后

var removeDuplicates = function(nums) {
    var i =0;
    let j =0;
    let temp=nums[i]
while(j<=nums.length-1){
    if(temp==nums[j+1]){
        j++;
    }else{
        nums[i+1]=nums[j+1];
        temp=nums[j+1]
        i++;
    }

}
return i;
};