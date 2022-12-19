### 1. 题目分析
- 裴蜀定理：$\forall a,b\in \mathbb{Z}, gcd(a, b) = 1 \Leftrightarrow \exists x,y\in \mathbb{Z}, s.t. ax+by=1.$
- 利用裴蜀定理，自左至右求出最大公因数即可
    - 若最大公因数为1，一定存在两两互质的最大公因数，可以(使用这两个互质的公因数)实现「好数组」
        - 注：最大公因数可以通过有限次乘法运算求出
    - 若最大公因数不为1，所有数都有共同的(大于1的)公因数，不能实现「好数组」
### 2. Coding
```java
public boolean isGoodArray(int[] nums) {
    int len = nums.length, res = nums[0];
    for(int i = 1; i < len; i ++){
        res = gcd(res, nums[i]);
    }
    return res == 1;
}

public static int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
```
### 3. 执行结果
![image.png](https://pic.leetcode-cn.com/306238c494293c6d63d5ffdefc1b7b4fc7cbcad7f07e38fcf87a35c8ecc279ae-image.png)
