var findKthLargest = function(nums, k) {
<!-- 先排序再输出 nums(nums.length-k)个数 -->
    return( nums.sort(function(a,b){
        return a-b
    })[nums.length-k])
 
};