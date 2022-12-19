### 解题思路
一次遍历：unshift()在前面插入，push 在后面插入

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function(nums) {
    var res=new Array();
    for(let i of nums){
        if(i%2==0){
            res.push(i);
        }else{
            res.unshift(i);
        }
    }
    return res;
};
```