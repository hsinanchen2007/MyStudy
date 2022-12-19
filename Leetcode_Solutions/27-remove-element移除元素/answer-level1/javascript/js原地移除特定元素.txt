执行用时 :
76 ms
, 在所有 JavaScript 提交中击败了
94.44%
的用户
内存消耗 :
33.6 MB
, 在所有 JavaScript 提交中击败了
71.03%

# 思路
* 原地移除，改变原数组，选择splice()
* 如果数组里碰到相同的val，就splice掉这一项，此时数组项数就少了一个，i要往后退回一个，即`i--`， 结束～
```javascript []
var removeElement = function(nums, val) {
    for(let i = 0; i< nums.length; i++) {
        if(nums[i] === val) {
            nums.splice(i, 1);
            i--;
        }
    }
    return nums.length;
};
```



`

`
