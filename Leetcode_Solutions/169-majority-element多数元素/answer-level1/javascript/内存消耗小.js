### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let obj={},num=0,max
    nums.forEach((item,index)=>{
        if(!obj[item]){
            obj[item]=1
        }else{
             obj[item]= obj[item]+1
        }

        if(obj[item]>=num){
            num = obj[item]
            max = item
        }
    })

    return max
};
```