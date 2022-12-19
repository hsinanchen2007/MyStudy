方法一、暴力计算两两数字汉明距离，求和即可，但是该方法超时
```
var totalHammingDistance = function(nums) {
    var total=0;
    for(var i=0;i<nums.length-1;i++){
        for(var j=i+1;j<nums.length;j++){
            total += hammingDistance(nums[i],nums[j]);
        }
    }
    return total;
};
 function hammingDistance(x, y) {
    var str=parseInt(x ^ y).toString(2);
    return str.split('1').length-1;
};
```
方法二、纵向计算
计算所有数字相同位置 1 的个数和 0 的个数，任意两个1和0都可以算作一个汉明距离，计算个数之积即可
数组中元素的范围为从 0到 10^9,总共每个数字不超过32位
```
var totalHammingDistance = function(nums) {
    var count=0;
    for(var i=0;i<32;i++){
        var oneSum = 0;
        for(var j=0;j<nums.length;j++){
            oneSum += nums[j] & 1;
            nums[j] >>=1;
        }
        count += oneSum*(nums.length-oneSum);
    }
    return count;
};
```

