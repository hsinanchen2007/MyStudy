暴力解法思路应该都差不多。之前直接双循环超时了，加了个限制，第二层循环是直接从第一层循环右边数字开始，就OK了。优点代码少，缺点就是时间和内存了
var countSmaller = function(nums) {
     var list = []
    for (var i = 0; i < nums.length; i++) {
      let num = 0
      let j = i + 1
      for (j; j < nums.length; j++) {
        if (nums[i] > nums[j]) {
          num += 1
        }
      }
      list.push(num)
    }
    return list
};