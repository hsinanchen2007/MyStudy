**方法1：常规迭代**
```
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long a=1;
        while (a<n)
            a=a<<1;
        return n==a;
    }
};
```

**方法2：位运算1**
```
/*
* 1二进制为1B，0为0B
* 2二进制为10B，1为01B
* 4二进制为100B,3为011B
* 8二进制为1000B，7为0111Bc
* 2的冥转成二进制就是左边1加上多个0
* 那么2的冥减一就是左边0加上多个1
* 那么采用与运算n&n-1结果一定为0
* 注意运算符优先-优先于==优先于&
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n&n-1)==0;
    }
};
```

**方法3：数学**
```
//一个整数如果是2的幂次方，必定可以被2的31次幂整除。
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && 2147483648%n==0;
    }
};
```

**方法4：采用bitset**
```
//2次幂则2进制中只有1个1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && bitset<31>(n).count()==1;
    }
};
```



