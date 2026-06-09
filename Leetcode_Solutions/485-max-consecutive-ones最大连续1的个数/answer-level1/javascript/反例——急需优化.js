```
/**
 * 给定一个二进制数组， 计算其中最大连续1的个数。
 * 输入:[1,1,0,1,1,1]
 * 输出：3
 * 思路：1.判非1条件；2.求最大值
 **/
 var nums = [1,1,0,1,1,1]
 var numsArr1 = []
 var count = 0
 for(var i=0; i<nums.length; i++){
    if(nums[i] == 1){
        count++
    }else{
        count = 0
    }
    numsArr1.push(count)
 }
 console.log('numsArr1--',numsArr1)
 numsArr1.sort(function(a,b){ return a - b })    
 console.log('结果--',numsArr1[numsArr1.length-1])
```
用时和内存都不太好~