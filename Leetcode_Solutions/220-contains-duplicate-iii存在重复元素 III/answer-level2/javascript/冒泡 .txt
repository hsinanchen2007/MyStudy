var containsNearbyAlmostDuplicate = function(nums, k, t) {
<!-- 两个for 循环判断 num[a] 和num[i] 是否满足 差值小于t index 差小于k -->
    for(var i=0;i<nums.length;i++)
        {
            for(var a=i+1;a<nums.length;a++)
                {
                    if(Math.abs(nums[a]-nums[i])<=t&&a-i<=k)
                        {
                            return true
                        }
                }
        }
    return false
};