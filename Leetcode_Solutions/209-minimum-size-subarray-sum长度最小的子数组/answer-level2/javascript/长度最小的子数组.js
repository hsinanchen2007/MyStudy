// # 正确方法一：
// //双指针查找法 O(nlogn)（对数阶）
// ```
var minSubArrayLen = function(s, nums) {
    var arr = [];//装载临时数组
    var minLen = 0; //最小的长度 初始为0
    var arrSum = 0; //累加
    var left = 0;
    var right = 1;
    while(left<nums.length-1 && right <= nums.length){
        arr = nums.slice(left,right);
        arrSum = arr.length? arr.reduce(function(sum,item){ return sum+item }) :0;
        if(arrSum >= s){
           if(left == 0 || (right - left < minLen)){ 
                minLen = arr.length; // 首次记录符合条件的  或者是此后对比下来比已记载的长度小 则重新赋值minLen
           } 
           ++left; //当前已经符合条件了 左侧滑动  
        }else{
            ++right; //不符合条件，右侧滑动加个数 
       }
    }
    return minLen;
};
// ```




// # 以下还有两个错误方法的记载 Mark下分享下

// # 错误方法一：
// 没读好题，以为是找到两者之和大于target最短的长度； **看漏了连续这个字眼**！！！
// ```
var minSubArrayLen = function(s, nums) {
    nums.sort(function(a,b){return b-a});
    var arr = [];
    console.log(nums);
    for(var i = 0;i<nums.length;i++){
        arr = nums.slice(0,i+1);
        var arrSum = arr.reduce(function(sum,item){ return sum+item });
        if( arrSum >= s){
            return arr.length;
        }
    }
    return 0;
};
minSubArrayLen(213,[12,28,83,4,25,26,25,2,25,25,25,12]);
//没看好 题目 还一直在蒙圈 明明我输出是7； 但是答案一直是8 迷糊了很久
// ```
// # 半正确方法二：
// ```
// 可以运行 但是 时间复杂度为 T(n) = O(n2) ；  性能低 数量过大时不行
var minSubArrayLen = function(s, nums) {
    var arr = [];//装载临时数组
    var minLen = 0; //最小的长度
    var arrSum = 0; //累加
    for(let i = 0; i<nums.length; i++){
        let j = i+1;
        while ( j <= nums.length)  {
            arr = nums.slice(i,j);
            arrSum = arr.reduce(function(sum,item){ return sum+item });
            if( arrSum >= s && (!minLen || (minLen > arr.length) )){
                minLen = arr.length;
            }
            ++j;
        }
    }
    return minLen;
};
//力扣的验证是丧心病狂的 一大堆数据跑到我浏览器都卡住了😿
// ```



