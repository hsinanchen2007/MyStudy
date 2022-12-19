![屏幕快照 2019-09-20 上午10.14.48.png](https://pic.leetcode-cn.com/248cb91a00b1c4c3dd5c80938c17dc3c25b8f8c867078c1b3a425223bd589b1c-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-09-20%20%E4%B8%8A%E5%8D%8810.14.48.png)

## 思路
首先就是回溯。
其次，需要注意的是，由于是找出所有可能的解，所以例如`[3,5]`是等同于`[5,3]`的。
因此，在每一次的循环中，自动去寻找比当前节点大的数作为可能的后续解。

例如，当 n=5,k=3 时
-   turn1:   1为初始节点，则寻找[2,3,4,5];
-   turn2:   2为初始节点，则寻找[3,4,5];
-   turn3,4 如前文规律。



以下是代码：
```javascript []
var combine = function(n, k) {
    
    var res = [];
    var could = [];
    if(k==0){
        return [[]]
    }
    function dfs(start,n,k,res,could){
        if(could.length == k){
            res.push(could.slice(0));
            return;
        }
        for(var i = start ; i<n+1;i++){
            could.push(i);
            dfs(i+1,n,k,res,could);
            could.pop()
        }
        return res;
    }
    return dfs(1,n,k,res,could)
};
```


