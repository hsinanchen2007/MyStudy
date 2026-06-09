### 代码

```javascript
var singleNumbers = function(nums) {
    const obj = nums.reduce((prev, next) => {
        if(next in prev){
            prev[next]++;
        }else{
            prev[next] = 1;
        }
        return prev
    }, {})
    let res = [];
    for(let key in obj){
        if(obj[key] === 1){
            res.push(key)
        }
    }
    return res
};
```