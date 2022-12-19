利用双指针法，使x从小到大，y从大到小循环。

对于任意xi, yi来讲，分为以下三种情况：
1. f(xi, yi) > z
对于任意y >= yi，有f(xi, y) > z，故只需要减小y的值即可；
2. f(xi, yi) == z
对于任意x > xi，有f(x, yi) > z；
对于任意y > yi，有f(xi, y) > z；
故增大x并减小y；
3. f(xi, yi) < z：增大x；
对于任意x <= xi，有f(x, yi) < z，故只需要增大x的值即可；

因为最差情况也只需要2n的时间，复杂度O(n)。

```js
var findSolution = function(customfunction, z) {
    var r = new Array();
    var my = 1000; // 记录当前y可取的最大值

    for(let x = 1; x <= 1000; x++) {
        
        for(let y = my; y >= 1; y--) {
            let fz = customfunction.f(x, y);
            if(fz > z) {
                // f(xi, yi) > z
                // 则对于任意x > xi，有f(xi, yi) > z
                my = y - 1;
                continue;
            } else if(fz == z) {
                // 找到结果，f(xi, yi) == z
                // 则对于任意x > xi，有f(x, yi) > z
                r.push([x, y]);
                my = y - 1;
                break;
            } else if(fz < z) {
                // f(xi, yi) < z
                // 注意此处隐含条件是f(xi, yi + 1) > z
                // 所以对于任意x > xi，有f(x, yi + 1) > z
                // 故下个循环从yi开始即可。
                my = y;
                break;
            }
        }
    }
    return r;
};
```
