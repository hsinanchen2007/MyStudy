var Solution = function(nums) {
    this.nums = nums
};
 */
Solution.prototype.pick = function(target) {    
    let index = []
    for(var i =0;i<this.nums.length;i++){
        if(this.nums[i]===target)
        index.push(i)
    }
    var result  =  index[Math.floor(Math.random()* index.length)]
    return result
};
/**
执行用时 :
148 ms
, 在所有 javascript 提交中击败了
69.23%
的用户
内存消耗 :
45.5 MB
, 在所有 javascript 提交中击败了
100.00%
的用户
*/