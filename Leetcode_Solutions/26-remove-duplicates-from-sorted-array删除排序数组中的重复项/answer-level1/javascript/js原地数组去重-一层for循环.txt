执行用时 :
120 ms
, 在所有 JavaScript 提交中击败了
76.76%
的用户
内存消耗 :
37.9 MB
, 在所有 JavaScript 提交中击败了
10.08%
的用户

  var removeDuplicates = function(nums) {
    // nums.sort((a,b) => a < b ? -1 : (a > b ? 1: 0));
    for(let i = 0; i< nums.length; i++) {
        if(nums[i] === nums[i+1]) {
            nums.splice(i,1);
            i--;
        }
    };
      return nums.length;
 };