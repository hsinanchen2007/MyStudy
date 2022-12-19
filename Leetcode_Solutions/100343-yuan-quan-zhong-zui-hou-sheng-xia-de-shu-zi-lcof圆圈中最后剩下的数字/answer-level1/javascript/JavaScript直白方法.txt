
先创建元素为其索引的长度为n的数组，然后判断从零位置开始  每次循环删掉第m个元素
![image.png](https://pic.leetcode-cn.com/81ede217841640b9949731321895cf57ea830fe23947ddeef691143f8696897b-image.png)

```javascript
var lastRemaining = function(n, m) {
    if (n === 1) return 0;
    let arr = [... new Array(n).keys()];
    let head = 0;
    function del() {
        head = (head + m - 1) % arr.length;
        arr.splice(head, 1);
    }
    while(arr.length > 1) {
        del()
    }
    return arr[0]
};
```