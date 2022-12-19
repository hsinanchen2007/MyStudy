#### 一、回溯算法
会超时
```javascript
var canJump = function(nums) {
    return canJumpFromPosition(0,nums)
};
const canJumpFromPosition = function(position,nums) {
    if(position === nums.length - 1) {
        return true;
    }
    let cur = Math.min(position+nums[position],nums.length - 1);
    for(let i = position+1; i <= cur; i++) {
        if(canJumpFromPosition(i,nums)) {
            return true;
        }
    }
    return false;
}
```
时间复杂度：O(2^n)
空间复杂度：O(n) 需要栈的额外空间

#### 二、动态规划（记忆化递归）
利用空间换时间

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    var arr = new Array(nums.length); 
    arr[nums.length-1] = true;
    return canJumpFromWhere(0,nums,arr);
}
const canJumpFromWhere = function(position,nums,arr){
    if(arr[position] != undefined){ // 如果该位置已经走过，则直接返回，不用再走下面的遍历，节省了重复递归的时间
        return arr[position];
    }
    var cur = Math.min(position+nums[position],nums.length - 1);
    for(var i = position+1;i<=cur;i++){
        if(canJumpFromWhere(i,nums,arr)){
            arr[position] = true;
            return true;
        }
    }
    arr[position] = false;
    return false;
}
```
时间复杂度：O(n^2)
空间复杂度：O(2n)，利用栈的空间和数组的额外空间

#### 三、迭代
```javascript
var canJump = function(nums) {
    var arr = new Array(nums.length).fill(false);
    arr[nums.length-1] = true;
    for(var right = nums.length-2;right>=0;right--){
        var cur = Math.min(right+nums[right],nums.length-1);
        for(var left = right + 1;left<=cur;left++){
            if(arr[left] == true){
                arr[right] = true;
                break;
            }
        }
    }
    return arr[0];
}
```
时间复杂度：O(n^2)
空间复杂度：O(n)，利用数组的空间

#### 四、贪心
思路: 如果能一直跳到最后、就成功了
```javascript
var canJump = function(nums) {
    let k = 0;
    for (let i = 0; i < nums.length; i++){
        if (i > k) return false;
        k = max(k, i + nums[i]);
    }
   return true;
};
```
时间复杂度：O(n)
空间复杂度：O(1)