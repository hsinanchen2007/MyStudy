### 解题思路
暴力破解法
1.最长回文串其实就是偶数个元素可以有n个，奇数个元素只能有1个或者没有；
2.统计所得的奇数个元素减掉1可以放入回文串中，偶数个元素直接放入；
3.判断是否有奇数个元素，是则在最长回文串的长度+1，否则直接返回长度
首先将字符串分割放入数组中
然后循环比较
关键点：用splice（index，1，“check”）中的check替代已比较且重复的元素，这样不会对数组的长度进行变化
然后进行统计
### 代码
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let nums = []
    nums = s.split("")
    let number = 0
    let c=false
    for(let i = 0 ;i < nums.length; i++){
        let numss = 1
        if(nums[i]!="check"){
        for(let n = i+1;n < nums.length;n++){
            if(nums[i]==nums[n]){
                nums.splice(n,1,"check")
                numss++
            }
        }
        
        if(numss%2===1||numss==1){
            number = number + numss - 1
            
            c = true
        }else{
            number = number + numss
        }
        }
    }
    if(c){
         return number+1
    }else{
          return number
    }
};
```