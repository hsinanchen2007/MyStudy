js 巧用循环； 
forEach在遍历前会读取固定长度，动态的改变数组本身不会受影响

var subsets = function(nums) {
    let res = [[]];
    for(let i=0;i<nums.length;i++){
        res.forEach(e=>{
            res.push(e.concat(nums[i]))
        })
    }
    return res;
};


