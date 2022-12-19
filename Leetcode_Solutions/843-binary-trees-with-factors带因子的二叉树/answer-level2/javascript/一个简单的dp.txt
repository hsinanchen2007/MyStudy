```
var numFactoredBinaryTrees = function(A) {
    A.sort((a,b) => a - b)
    const map = {}
    A.forEach((v) => map[v] = 1)

    for(let i = 0;i < A.length;i++) {
        for(let j = 0;j <= i;j++) {
            if(map[A[i]*A[j]]) {
                let curI = map[A[i]] 
                let curJ = map[A[j]] 
                if(i == j) map[A[i]*A[j]] += curI * curJ
                else map[A[i]*A[j]] += curI * curJ * 2
            }
        }
    }

    return Object.values(map).reduce((v,c) => c+v) % (10 ** 9 + 7)
};
```

原理很简单，可以参考另一道题：构建不同的二叉树
主要是遍历顺序
