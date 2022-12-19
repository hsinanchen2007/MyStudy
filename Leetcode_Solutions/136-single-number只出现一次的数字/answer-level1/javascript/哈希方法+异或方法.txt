//方法一、创建哈希表，存入每个值时，判断存在相同的值就删除，最后map只留一个值。通过Object.key(map)显示值
var singleNumber = function(nums) {
    
    // var map={};
    // for(var i=0;i<nums.length;i++){
    //     if(map[nums[i]]) delete map[nums[i]];
    //     else map[nums[i]]=1;//存在map哈希表中的第一个value，nums[i]
    // } 
    // return Object.keys(map)[0];//显示vaule
//方法二、很巧妙，异或运算，a^a=0,a^0=a,所以最后只能保留单个的值    
    var sum=0;
    for(var i=0;i<nums.length;i++)
        sum^=nums[i];
    return sum;
};