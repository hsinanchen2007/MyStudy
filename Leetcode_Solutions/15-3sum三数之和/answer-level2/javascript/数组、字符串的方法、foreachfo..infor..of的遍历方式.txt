### 超出时间限制的做法
没有像[高赞](https://leetcode-cn.com/problems/3sum/solution/pai-xu-shuang-zhi-zhen-zhu-xing-jie-shi-python3-by/)一样考虑当有很多重复元素时，比如［0，0，0，0，0，....］
应该当前后元素相等时跳过后面的元素，防止一直判断同样的元素，造成时间溢出
```
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    var len = nums.length;    
    var result = [];
    var index = 0;

    if(len < 3) {   
       return result;
    }
    nums.sort(function(a, b) {
        return a-b;
    });

    for(var i = 0; i < len; i++) {
        var start = i+1;
        var end = len - 1;
        while(start < end) {
            sum = nums[i] + nums[start] + nums[end];
            if(sum < 0) {
                start++;
            } else if(sum == 0) {
                // 创建新数组的方法一
                var arr = [nums[i], nums[start], nums[end]];
                if(!hasarr(result, arr)) {
                    result[index] = arr;
                    index++;
                }
                if(start < end) {
                    start++;
                } else if(start > end) {
                    end--;
                }   
                // 创建数组的方法二
                //result[index] = new Array(nums[i], nums[start], nums[end]);
                //result[index] = [];                
            } else {
                end--;
            }
        }
    }
    console.log();
    return result;       
};

// [判断两个数组是否相等的方法](https://segmentfault.com/a/1190000016574183)
// 不能使用＝＝＝，因为数组是引用数据类型，比较的是地址而不是值
function hasarr(arr, target) {
    // es6中新增的for of方法
    for (let cur of arr) {
        let isEqual = true
        for (let i = 0; i < target.length; i++) {
            if (cur[i] != target[i]) {
                isEqual = false
            }
        }
        if (isEqual) return true
    }
    return false
}
```
[for的各种循环方式](https://www.cnblogs.com/larrywang/p/10325988.html)
[字符串的方法](https://www.runoob.com/js/js-strings.html)
[数组的方法](https://www.runoob.com/jsref/jsref-obj-array.html)