javascript
 
![image.png](https://pic.leetcode-cn.com/cf2cca0aa849e42ddb9208788f95f7d05ebb2df2531076380c66705049182e71-image.png)
使用了三个指针 
AIndex 遍历A 递减
Bindex 遍历B 递减
current  指向A数组尾部     AIndex和Bindex依靠current 向A尾部填充


```
var merge = function(A, m, B, n) {
    let AIndex = m - 1;
    let BIndex = n - 1;   
    let current = m + n - 1;
    while (AIndex >= 0 && BIndex >= 0) {
        if (A[AIndex] <= B[BIndex]) {
            A[current] = B[BIndex]
            BIndex--
            current--
        } else {
            A[current] = A[AIndex]
            AIndex--
            current--
        }
    }
    //最后B剩余最小元素填充到A
    while (BIndex >= 0) {
        A[current] = B[BIndex]
        BIndex--;
        current--
    }
    

};
```
