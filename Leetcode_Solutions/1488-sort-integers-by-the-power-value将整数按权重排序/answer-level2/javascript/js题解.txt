```

// 获得权重
let getWeight = (x) => {
    let c = 0;
    while(x !== 1){
        if(x % 2===0){
            x = x / 2
        }else{
            x = 3 * x + 1
        }
        c++;
    }
    return c;
}

var getKth = function(lo, hi, k) {
    let a = []
    for(let i = lo; i <= hi; i++){
        a.push({
            val: i,
            w: getWeight(i)
        })
    }
    a.sort((a, b) => {
        if (a.w === b.w){
            return a.val - b.val;
        }else{
            return a.w - b.w;
        }
    })
    return a[k - 1].val;
};
```

前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解