### 解题思路
利用js中的Map记录字符和字符出现的次数，然后找出出现次数最多的字符，推进数组中，如果推进来1个，说明这个就是主要字符，推进来多于1个，说明没有主要字符。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let r = new Map();
    let res = [];
    for(let i = 0; i < nums.length; i++){
        r.set(nums[i], r.get(nums[i])+1 || 1);
    }
    let max = Math.max(...r.values());
    console.log(r);
    for(let key of r.keys()){
        if(r.get(key) == max){
            res.push(key);
        }
    }
    if(res.length == 1){
        return res.join('');
    }else{
        console.log(res);
    }
};
```