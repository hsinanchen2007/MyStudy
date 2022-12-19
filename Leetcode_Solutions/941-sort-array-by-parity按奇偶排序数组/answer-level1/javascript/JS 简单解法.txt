刚学JS不是很久，还有很多方法不知道，这里仅用我知道的方法进行解答
首先读题，题目的要求无非就是将偶数放在**前**，奇数放在**后**。
输出的内容只要符合**上述条件**，无论奇偶数的大小排序如何，都算是正确答案。
这里马上就想到数组中两个添加方法
**Array.push()**//向尾部添加
**Array.unshift()**//向首(头)部添加
想必看到这大家就懂了，只需要用简单的判断语句即可完成此题
话不多说，代码附上.
```javascript []
var sortArrayByParity = function(A) {
    var B = new Array();
    for(let i = 0 ; i < A.length ; i++){
        if( A[i] % 2 == 0 ){
            B.unshift(A[i]);
        }else{
            B.push(A[i]);
        }
    }
    return B
};
```


