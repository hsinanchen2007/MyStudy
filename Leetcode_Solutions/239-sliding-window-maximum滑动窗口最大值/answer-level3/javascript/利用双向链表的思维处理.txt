//可能是JS中的shift消耗性能，用这种方式处理，比暴力方法，更加耗时 手动狗头
var maxSlidingWindow = function(nums, k) {
   if(nums.length===0){
        return [];
    }
    let result = [];
    let window =[];//1.永远都是包含k个元素，2.存入的是下标
    let n = nums.length;
    for(let i in nums){
    let x = nums[i];
    /*
        由于window的移动，window中存入的数据超出范围
        需要将最前面的值进行移除，因为需要后续的值进来
    */
    if(i>=k&&window[0]<=i-k){
        window.shift();
    }
    /*
        1.进行数据对比，新进数据如果都比原先的大，原生存入的数据，全部移除，
        2.通过window.push(),永远保证window[0]，是该窗口中最大的值
    */
    while(window.length&&nums[window[window.length-1]]<=x){
        window.pop();
    }
    window.push(i);
    /*
        1. 因为i是从0开始移动，所以需要将0-1-2中最大值找出才可以result.push
        2. 在1.完成之后，window[0]是 该窗口中最大的值
    */
    if(i>=k-1){
        result.push(nums[window[0]])
    }
    }
    return result;
};