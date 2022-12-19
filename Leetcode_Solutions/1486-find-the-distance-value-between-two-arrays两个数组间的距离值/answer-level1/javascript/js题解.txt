```
var findTheDistanceValue = function(arr1, arr2, d) {
    let cnt = 0;
    for(let i = 0; i < arr1.length; i++){
        let dis = Number.MAX_SAFE_INTEGER;
        for(let j = 0; j < arr2.length; j++){
            if (Math.abs(arr2[j] - arr1[i]) < dis){
                dis = Math.abs(arr2[j] - arr1[i])
            }
        }
        if (dis > d){
            cnt++;
        }
    }
    return cnt;
};
```


前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解，