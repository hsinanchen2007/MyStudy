### 解题思路
放到对象里面 如果存在就+1 否则就等于一
复杂度2n吧 写的不太好 其实还可以调用Math.max去比较

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let obj={};
    for(let i=0;i<nums.length;i++){
        if(!obj[nums[i]]){
            obj[nums[i]]=1
        }else{
            obj[nums[i]]+=1
        }
    }
    let max=0;
    let maxStr=''
    for(var key in obj){
        if(obj[key]>max){
            max=obj[key];
            maxStr=key;
        }
    }
    // console.log(max)
    return maxStr
};
```