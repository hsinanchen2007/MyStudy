一共有两种方法:

### 第一种是动态的更新每层元素，直到更新至最终的结果层
```js
var getRow = function(rowIndex) {
    let res = [];
    for(let i = 1; i <= rowIndex; i++){
        res.push(1);
        for(let j = i - 1; j > 0; j--){
            res[j] += res[j-1];
        }
    }
    res.push(1);
    return res;
};
```

### 第二种利用递推公式
ps:杨辉三角的每层中每一项可以看作是一个组合数列：
![image.png](https://pic.leetcode-cn.com/7e90ab35c9377aa56fdeebcfc8fc79d204eceb010e57f2250a646dabc2467073-image.png)
所以可以使用递推公式在结果层上，逐项通过递推关系求解。

其中递推公式为
![image.png](https://pic.leetcode-cn.com/ae7d253ed5a37e74337093ad98abf955eb22bab3439e20b6d4162f18bcf8e8d1-image.png)


```js
 var getRow = function(rowIndex){
     let res = [1];
     if(rowIndex === 0) return res;
     let pre = 1;
     for(let i = 1; i <= rowIndex; i++){
         res[i] = pre * (rowIndex - i + 1) / i;
         pre = res[i];
     }
     return res;
 };
```