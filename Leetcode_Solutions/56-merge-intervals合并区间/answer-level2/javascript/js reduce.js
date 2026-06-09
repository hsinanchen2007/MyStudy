```
var merge = function(intervals) {
    if(intervals.length == 0){
        return intervals;
    }
    intervals.sort((a, b) => a[0] - b[0]);
    let res = [];
    res.push(intervals.reduce((acc, cur) => {
        if(acc[1] >= cur[0]){
            if(acc[1] < cur[1]){
                acc[1] = cur[1];
            }
            return acc;
        }else{
            res.push(acc);
            return cur;
        }
    }));
    return res;
};
```
先排序，后合并，reduce中acc代码上一次计算的结果，如果上一次能合并的话，acc就是合并后的结果，不能的话acc为上一个数组。最后一项就是reduce的最后结果，因为没有比较，所以直接用res接住返回值
