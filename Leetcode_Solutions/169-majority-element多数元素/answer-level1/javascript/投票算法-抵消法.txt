### 解题思路
抵消法

假定第一个元素是多数，出现了一次，后面一个元素若一样则出现次数加一，若不一样则抵消，出现次数减一

当抵消完count为0时，选择后一个元素开始重新计算，最后剩下的，就是多数

例如：
A A B (A出现两次，B出现一次，抵消一次，A为多数)
A A B B B (A出现2次，B出现2次，抵消两次，剩下B为多数)
A B A B B (A出现1次，B出现1次，抵消，A出现1次，B出现1次，抵消，剩下B为多数)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    // var nums=[6,5,5];
    debugger
    var morenum = nums[0];
    var count = 1;

    if(nums.length==1){
        return morenum;
    }else{
        for(var i=1; i<nums.length; i++){
            if(nums[i]==morenum){
                count=count+1;
            }else{
                count=count-1;
            }
            while(count==0){
                morenum=nums[i+1];
                break;               
            }

         }
        return morenum;
    }

};
```