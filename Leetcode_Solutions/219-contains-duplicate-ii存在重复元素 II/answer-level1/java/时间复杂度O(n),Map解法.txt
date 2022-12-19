1：map中的每一项key是nums[i],value是索引i，
2：遍历数组，如果当前项在map中存在，就比较索引的差值是否小于k
3：小于就证明存在，返回true

此题目注意：’最大值为k‘这几个字，就是距离范围在k以内。

我的解法时间复杂度为O(n)，但这点东西占40m内存，希望有大神指点。我bb完了


var containsNearbyDuplicate = function(nums, k) {
    var myMap = new Map();
    for(let i = 0 ; i<nums.length ; i++){
        if(myMap.has(nums[i])){
          if(Math.abs(myMap.get(nums[i]) - i) <=k){
              return true;
          }  
        }
         myMap.set(nums[i] , i)
    }
    return false
};