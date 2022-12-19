### 解法一：贪婪算法
![image.png](https://pic.leetcode-cn.com/921e5b9fa7f043a14237f0a943a903d16fbc6a7c3ba8705ba2a4a4ffc1dea333-image.png)


### 解题思路
        总结一下，不难发现其中的运算规律；不管多大的数，最终都是归结为2,3和4这三个数字的乘积，且数字3是根本
    
    （数字4可以认为是“2+2”，所以数字2和3是两个十分重要的数字，进一步会发现数字3的指数上升速度是比2更快的，
    比如一根绳子长为6，可分为两段：3+3，也可分为三段：2+2+2，明显前者得到的m更大，前者是9，后者是8）。

        因此，无论多大的数，分解到最后大部分绳子的长度都将是3。

![剪绳子1.jpg](https://pic.leetcode-cn.com/b1446b9ab8acd796dfc1722dc60ea2628c1e9498a3c5b0248202d35440daf208-%E5%89%AA%E7%BB%B3%E5%AD%901.jpg)


### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=1) return 0;
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        else{
            // n=3*quotient+remainder  被除数=除数*商+余数
            int quotient=n/3;
            int remainder=n%3;
            if(remainder==0) return pow(3,quotient);
            else if(remainder==1) return pow(3,quotient-1)*4;
            else return pow(3,quotient)*2;
        }
    }
};
```

### 解法二：动态规划
### 解题思路
    定义函数：f(n)=m
    随便剪一刀有 n-1 种可能，每次前半段的长度i分别为 1,2,3，...，n-1。所以可得到递推公式：f(n)=max(f(i)*f(n-i))(0<i<n)。
    可以采取从下往上的顺序计算，减少大量不必要的重复计算，即先算f(2)、f(3)，再算f(4)、f(5)，一直到f(n)。
```
class Solution {
public:
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=1) return 0;
        if(n==2) return 1;
        if(n==3) return 2;
        int products[n+1];
        products[1]=1;
        products[2]=2;
        products[3]=3;
        for(int i=4;i<=n;i++){
            int max=0;
            for(int j=1;j<=i/2;j++){
                int tmp=products[j]*products[i-j];
                if(max<tmp) max=tmp;
            }
            products[i]=max;
        }
        return products[n];
    }
};
```
