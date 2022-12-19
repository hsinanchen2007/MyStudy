```javascript
var search = function(nums, target) {
    let res= nums.reduce((t,v)=>{
        t=v==target?t++:t;
    },0)
    return res;
};
```
