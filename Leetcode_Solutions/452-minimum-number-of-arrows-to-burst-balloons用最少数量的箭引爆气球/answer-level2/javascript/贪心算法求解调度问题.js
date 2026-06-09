```
var ascend=function(x,y){
    return x[1]-y[1]
}
var findMinArrowShots = function(points) {
    if(points.length===0)return 0
    let ans=1
    points.sort(ascend)
    let x=points[0][1]
    for(let point of points){
        let start=point[0]
        if(start>x){
            ans++
            x=point[1]
        }
    }
    return ans
};
```
按照每一个区间的最大值进行排序之后，画图，看哪种能扎破
![txsf.png](https://pic.leetcode-cn.com/ff31796d9db90891bfe5396abd8b07433f58a311e2cb33c4bd52d18d05801e1d-txsf.png)
