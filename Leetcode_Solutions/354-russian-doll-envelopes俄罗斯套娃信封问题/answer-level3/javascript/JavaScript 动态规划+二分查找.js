
```
/**
 * @param {number[][]} envelopes
 * @return {number}
 */
var maxEnvelopes = function(envelopes) {
    var length = envelopes.length;
    // 按宽度升序排列，高度降序排列
    envelopes.sort(function(a,b){
        return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
    })
    // 对高度数组寻找 LIS
    var height = new Array(length);
    for (var i = 0; i < length; i++)
        //存储 高度
        height[i] = envelopes[i][1];
    
    return lengthOfLIS(height);

};
function lengthOfLIS(nums) {
    var piles   = 0, 
        n       = nums.length,
        top     = [];
    for (var i = 0; i < n; i++) {
        // 要处理的扑克牌
        var poker = nums[i];
        var left = 0, right = piles;
        // 二分查找插入位置
        while (left < right) {
            var mid = (left + right) >>1;
            if (top[mid] >= poker)
                right = mid;
            else
                left = mid + 1;
        }
        if (left == piles) piles++;
        // 把这张牌放到牌堆顶
        top[left] = poker;
    }

    // 牌堆数就是 LIS 长度
    return piles;
}
```
