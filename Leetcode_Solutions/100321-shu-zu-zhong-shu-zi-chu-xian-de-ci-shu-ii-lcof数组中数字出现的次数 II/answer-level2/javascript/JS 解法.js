### 代码

```javascript
var singleNumber = function(nums) {
    const obj = nums.reduce((prev, next) => {
        if(next in prev){
            prev[next]++;
        }else{
            prev[next] = 1;
        }
        return prev
    }, {})
    for(let key in obj){
        if(obj[key] === 1){
            return key
        }
    }
};
```