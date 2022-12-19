### 解题思路一　函数库法
使用cmath头文件中的库函数x^n = pow(x,n);或者直接手写循环，每次乘以底数。
### 代码

```cpp
    /*
     * 方法１　函数库方法
     * 直接使用cmath函数库中的pow(x,n)函数
     * 即x^n=pow(x,n)；
     *
     * 也可类似于进制转换，
     * 直接使用手动乘法
     * */
std::vector<int> printNumbers(int n) {
    std::vector<int> res;
    int i = 1;

    int m = 1;

    //函数库pow(x,n)
    m = pow(10,n);

    //手动乘
//    while (n>0){
//        m *= 10;
//        n--;
//    }

    if(m > INT_MAX){
        return {};
    }

    while (i < m){
        res.push_back(i);
        i++;
    }

    return res;
}
```

### 解题思路二　快速幂法
将n分解为二进制，再使用分治原理，判断每一位是否乘底数。本题出的比较简单，没有考虑溢出等问题。关于快速指数幂的计算可看博客[快速指数（快速幂）/模指数运算代码模板](https://blog.csdn.net/iteapoy/article/details/94395418)

```cpp
    /*
     * 方法２　快速幂方法
     * 求x=base^a，base是底数，a为指数幂
     * 对base^a进行分治，即：
     *
     * -- base^a = base^(a/2+a/2) = base^(a/2) * base^(a/2)                     a mode 2 = 0;
     * -- base^a = base^((a-1)/2+(a-1)/2) = base^((a-1)/2) * base^((a-1)/2)     a mode 2 = 1;
     *
     * 如此就能够通过将a分解成二进制，
     * 对其使用与&和右移>>操作了
     * */
typedef long long int LL;
std::vector<LL> printNumbers2(LL base, LL a) {
    std::vector<LL> res;
    LL m = 1;
    while (a != 0){
        //a&1表示判断a的二进制最后一位是否为1
        if(a&1){
            //当位数为1时，乘底数
            m *= base;
        }

        //a每移位一次，base乘一倍
        base *= base;
        //右移或a/=2
        a = a>>1;
    }

    LL i = 1;
    while (i < m){
        res.push_back(i);
        i++;
    }

    return res;
}
```

### 通用方法　模指数运算－－分治原理＋二进制计算
计算模指数，使用方法２的分治和二进制计算原理，该方法可以通用。
```cpp
    /*
     * 通用方法１：模指数运算－分治原理
     * 分治法：分、治再归并
     * 求x = a^e mod m，a是底数，e为指数幂，m是模数
     *
     * -- a^e mod m = a^(e1+e2) mod m = (a^e1 mod m) * (a^e2 mod m) mod m     e = e1+e2
     *
     * 分别计算出分治的a^e1 mod m 和a^e2 mod m 结果
     * 再将它们合并为a^e mod m
     *
     *
     * 通用方法２：模指数运算－二进制算法
     * 以二进制方式分拆指数
     * 将e表示为二进制dn-1 dn-2 ... d1 d0，此处di=0或１
     * e = dn-1*2^(n-1) + ... + d1*2 + d0 = Dn-1 + ... D1 + D0 (Di = di*2^i)
     * 所以a^e = a^(Dn-1) * a^(Dn-2) * ... * a^D1 * a^D0 (a^Di)
     * 分治计算：Ai = a^Di mod m, i = 0, 1, ..., n-1
     * a^(2^(i+1)) mod m = (a^(2^i) mod m) * (a^(2^i) mod m) mod m
     * 计算O(loge)次
     * 实用于通用函数
     * */
std::vector<LL> printNumbersTemplate(LL base, LL a, LL m) {
    std::vector<LL> res;
    LL x = 1;
    while (a!=0){
        if(a&1){
            x = (x * base)%m;
        }
        base = (base * base) % m;
        a=a>>1;
    }

    LL i = 1;
    while (i < x){
        res.push_back(i);
        i++;
    }

    return res;
}
```