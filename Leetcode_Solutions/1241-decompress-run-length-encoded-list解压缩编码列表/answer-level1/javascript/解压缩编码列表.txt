### 解题思路
循环体中的变量每次+2，每次循环时候创建一个新的临时数组，数组的长度为当前的nums[i]，
并将数组内的值填充为num[i+1]，最后与上一次的结果数组进行拼接。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(nums) {
    var res=[]
    for(let i=0;i<nums.length;i=i+2){
    var temp=new Array(nums[i]).fill(nums[i+1])
    res=res.concat(temp)
    }
    return res
};
```