// 本题看起来像是查找缺失的数组，实则是在考察排序
// 由题可知
// 1，从0到n-->换句话说就是数组的下标
// 2，缺失的数字 -->  如果我们在跑一个排序过后的数组发现某一个节点 i! = num[i] 那么这个i不就是缺失的数字么
//     就好比这里本来应该是i但是现在不是i了
// ```
var missingNumber = function(nums) {
    nums = nums.sort((a,b)=>a-b)
    for(let i = 0; i<nums.length;i++){
        if(i!= nums[i]){
            return i
        }
    }
    return nums.length
};
// ```
// 欢迎讨论
// 👏👏👏