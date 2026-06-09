## 尾数中的0怎么来的？
先考虑，尾数中的0是怎么来的？


- 在1~9的范围内，选两个数字相乘，只有 2*5=10。所以，一对`2`和`5`，贡献一个0。
- 不限制范围的话，一对`2的倍数`和`5的倍数`，贡献一个0
- 阶乘中，`2的倍数`肯定比`5的倍数`多。所以，只需要考虑`5的倍数`出现了多少次



## 怎么算？

举例说明，题目：$22!$ 中尾数0的个数。

$22!$ 中，5的倍数的有`Math.floor(22/5)=4`个，分别是`5` `10` `15` `20`。

根据前面的分析，题目**等价于：$5*10*15*20$ 中尾数0的个数**

![image.png](https://pic.leetcode-cn.com/bc03ffb2f02babf157af3185d6b1534cfa77ad29d91435570d9c82fb511e06d9-image.png)
所以，题目**等价于：$5^k*k!$ 中尾数0的个数**

**等价于：k + （$k!$ 中尾数0的个数）**

---

可以写成递归：
```js
var trailingZeroes = function(n) {
    if(n<5){
        return 0;
    }else{
        let k=Math.floor(n/5);
        return k+trailingZeroes(k); 
    }
};
```
也可以写成循环：
```js
var trailingZeroes = function(n) {
    let res=0;
    while(n>=5){
        let k=Math.floor(n/5);
        res+=k;
        n=k;
    }
    return res;
};
```