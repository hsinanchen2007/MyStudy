题目很好理解，但是由于本人代码能力太差，硬是写不出来。。。。
看到别人如此简便、优雅的方法，跪了
更别说什么公式法了。。。
真菜啊
```
var distributeCandies = function(candies, num_people) {
    var res = new Array(num_people).fill(0)
    let i = 0
    while(candies > 0){
        res[i%num_people] += Math.min(i+1 , candies)
        candies -= Math.min(i+1 , candies)
        i++
    }
    return res
};
```
