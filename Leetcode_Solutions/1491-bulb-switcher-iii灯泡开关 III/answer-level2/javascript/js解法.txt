```
维护最大最小值，每次开灯check一下
var numTimesAllBlue = function(light) {
    if(!light.length) return 0;
    let c = 0;
    let arr = []
    let min = Number.MAX_SAFE_INTEGER;
    let max = 0;
    for(let i = 0; i < light.length; i++){
        arr.push(light[i])
        if (light[i] < min){
            min = light[i]
        }
        if(light[i]>max){
            max = light[i];
        }
        // 每次开灯check一下。满足下面条件就是左侧全亮
        if(max === i+1 && min===1 && arr.length === i+1){
            c++;
        }
    }
    return c;
};
```

前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解，
希望对前端同行找工作面试、修炼算法内功有帮助。
前端算法交流群：621067993