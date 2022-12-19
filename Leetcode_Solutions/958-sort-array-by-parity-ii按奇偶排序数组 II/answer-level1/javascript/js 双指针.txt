执行用时 :136 ms, 在所有 JavaScript 提交中击败了93.32%的用户
内存消耗 :38.1 MB, 在所有 JavaScript 提交中击败了97.56%的用户

思路来源官方题解
目标：让偶数部分下标 i 的所有数都是偶数。
当发现偶数部分下标对应的值不是偶数时，不断增加指向奇数部分的指针，直到找到一个偶数，然后交换指针 i，j 所指的数。

```javascript
var sortArrayByParityII = function(A) {
    let i = 0,
        j = 1;
    for(; i < A.length; i += 2){
        if(A[i] % 2 == 0)continue;//当A[i] % 2 == 1时会到下面的while循环看j
        while(A[j] % 2 == 1)j += 2;
        [A[i],A[j]]=[A[j],A[i]];//ES6在引入了数组解构的概念，值互换会变得更加方便
    }
    return A;
}
```

