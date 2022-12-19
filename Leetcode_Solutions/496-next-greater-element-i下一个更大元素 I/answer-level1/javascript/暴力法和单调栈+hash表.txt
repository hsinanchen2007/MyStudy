/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function(nums1, nums2) {
    // //暴力解法
    // var flag = 0;
    // var result = [];
    // for(let i = 0; i < nums1.length; i++){
    //     for(var j = 0; j < nums2.length; j++){
    //         if(nums1[i] == nums2[j]){
    //             flag = 1;
    //         }
    //         if(flag){
    //             if(nums1[i]<nums2[j]){
    //                 result.push(nums2[j]);
    //                 break;
    //             }
    //         }
    //     }
    //     if(j == nums2.length){
    //         result.push(-1);
    //     }
    //     flag = 0;
    // }
    // return result;

    // 单调栈+hash表解法
    var s = [];
    var hash = [];
    var result = [];
    for(let i = nums2.length-1; i >= 0; i--){
        while(s.length && s[s.length-1] <= nums2[i]){
            var x = s.pop();
            hash[x] = s.length ? s[s.length-1] : -1;
        }
        s.push(nums2[i]);
    }
    while(s.length){
        var x = s.pop();
        hash[x] = s.length ? s[s.length-1] : -1;
    }
    for(let i = 0; i < nums1.length; i++){
        result.push(hash[nums1[i]]);
    }
    return result;
};