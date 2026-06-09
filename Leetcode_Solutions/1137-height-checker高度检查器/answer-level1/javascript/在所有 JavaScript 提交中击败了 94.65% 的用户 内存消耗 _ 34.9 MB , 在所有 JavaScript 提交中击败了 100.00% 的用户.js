借鉴了第二条题解张佳晨的思路。即对原来的数组进行排序，排序完成后与原始数组中的元素对比，遇到不同的元素count++，最后返回count
```
var heightChecker = function (heights) {
            var count = 0;
            var arr = heights.slice(0);//伪深拷贝
            arr.sort(function (a, b) { return a - b });
            for (var i = 0; i < arr.length; i++) {
                if (arr[i] !=heights[i]) {
                    count++;
                }
            }
            return count;
        };
```
#### 有一个容易忽略的地方是将heights赋值给arr时，实际上只是将存放在堆内存的数组的地址赋予了arr，此时arr和heights在栈内存独立存储，但是两者的地址指向堆内存中同一个数组，对arr排序后堆内存中的数组值发生改变，heights此时取值取到的是排序后的数组，因此在for循环内进行比较时，两者指向的数组是同一个，arr[i]总会等于heights[i]，count永远等于0。所以在给数组赋值时用slice（0）的方式实现伪深拷贝