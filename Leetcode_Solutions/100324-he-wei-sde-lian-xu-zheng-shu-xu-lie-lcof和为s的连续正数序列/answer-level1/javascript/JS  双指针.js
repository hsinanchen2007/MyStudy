### 代码

```javascript
var findContinuousSequence = function(target) {
    let low = 1,
        high = 2;
    let res = [],
        temp =[];
    while(low<high){
        let sum = ((low + high) * (high - low + 1))/2;
        if(sum === target){
            let set = new Set();
            for(let i = low; i <= high; i++){
                set.add(i);
            }
            temp = Array.from(set);
            res.push(temp);
            low++;
        }else if(sum < target){
            high++;
        }else if(sum > target){
            low++;
        }
    }
    return res
};
```