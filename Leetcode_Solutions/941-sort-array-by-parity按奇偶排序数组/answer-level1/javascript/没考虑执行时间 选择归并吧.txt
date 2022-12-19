### 解题思路
既然要偶数奇数分开，那索性就创造两个数组。最后进行concat操作就好了

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function (A) {
    let odd = [];
    let even = [];
    for(let i=0;i<A.length;i++){
        A[i]%2==0?even.push(A[i]):odd.push(A[i]);
    }
    A=[];
    A=A.concat(even,odd)
    return A 
};
```