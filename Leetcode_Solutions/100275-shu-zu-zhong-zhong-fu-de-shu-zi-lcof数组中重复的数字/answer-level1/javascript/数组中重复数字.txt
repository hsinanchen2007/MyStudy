### 解题思路
因为之前对set的add方法的返回值理解的不透彻，打算用set做，结果不成功，因为add方法的返回值是对象，而不是布尔值。所以这一题还是要用类似于桶排的方法。如果num数组中，nums[i]处的数值为0，即nums[i]还从未出现过，则将对应位置上的num数组元素置位1。如果num数组的nums[i]位置不为0，则nums[i]之前出现过。所以保存这个值，并结束循环，最后返回这个值。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
//这是桶排的做法
var findRepeatNumber=function(nums){
    var repeat;
    var num=[];
    for(var i=0;i<nums.length;i++){
        if(!num[nums[i]]){
            num[nums[i]]=1;
        }else{
            repeat=nums[i];
            break;
        }
    }
    return repeat;
}
```