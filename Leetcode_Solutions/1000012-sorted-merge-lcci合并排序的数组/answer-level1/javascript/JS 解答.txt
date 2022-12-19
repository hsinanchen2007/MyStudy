### 解题思路
该问题主要分三类场景：首先清空A后面的0.第一种就是B的最大值小于A的最小值；第二种事B的最小值大于A的最大值，对于这两种场景很简单；主要分析的是第三种场景，里面有大有小。通过循环A的元素长度m,取一个外部变量j,比较A[i]和B[j],当B[j]小于A[i] 时，将B[j]插入到A的i位置处，A的长度m++,j++;在比较B的下一个元素和A的下一个元素。循环完后，当j<n时，说明B[j]之后的都大于A种所有元素，直接push到A后面即可。

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
    var j = 0;
    var s = m + n;
     A.splice(m);
    if(B[n-1]<A[0]){
        A.unshift(...B)
    }else if(B[0]>A[m-1]){
         A.push(...B)
    }else {
        for (var i = 0;i<m;i++){
                if(B[j]<A[i] && j<n){
                    A.splice(i,0,B[j]);
                    j++;
                    m++;
                }
            }
            if(j<n){
            var arr = B.slice(j);
            A.push(...arr);
            }
    }
   
};
```